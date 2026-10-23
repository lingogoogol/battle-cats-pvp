import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.FunctionManager;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.disassemble.Disassembler;
import ghidra.program.model.address.AddressSet;

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;

public class ExportTargetDecomp extends GhidraScript {
    @Override
    public void run() throws Exception {
        println("=================================================");
        println("  Ghidra Phase 7 Native Audit & Decompiler Script ");
        println("=================================================");

        File outDir = new File("E:/rea/phase7/ghidra_decompiled");
        if (!outDir.exists()) {
            outDir.mkdirs();
        }

        File logFile = new File(outDir, "audit_log.txt");
        PrintWriter logWriter = new PrintWriter(new FileWriter(logFile));

        // Part 1: Verify the disputed Phase 6 addresses in Ghidra's memory model
        long[] disputedAddrs = new long[] { 0x001c11a1L, 0x001bf6baL, 0x001befe1L };
        String[] disputedNames = new String[] { "battleCheckLogic", "battle_createButton", "battle_initWin" };

        logWriter.println("=== Phase 7 P7-A Ghidra Memory & Address Audit ===");
        println("=== Phase 7 P7-A Ghidra Memory & Address Audit ===");

        for (int i = 0; i < disputedAddrs.length; i++) {
            Address addr = toAddr(disputedAddrs[i]);
            MemoryBlock block = getMemoryBlock(addr);
            String blockName = (block != null) ? block.getName() : "NULL";
            boolean isExec = (block != null) && block.isExecute();
            boolean isRead = (block != null) && block.isRead();
            boolean isWrite = (block != null) && block.isWrite();
            Function func = getFunctionAt(addr);

            String report = String.format("Addr: 0x%08x | Target: %-20s | Block: %-10s | Perms: R=%b W=%b X=%b | IsFunction: %b",
                    disputedAddrs[i], disputedNames[i], blockName, isRead, isWrite, isExec, (func != null));
            println(report);
            logWriter.println(report);
        }

        // Part 2: Decompile verified functions
        long[] targetAddrs = new long[] {
            0x00309c5cL, // Java_com_ponos_battlecats_MyActivity_appInit
            0x00309d2cL, // Java_com_ponos_battlecats_MyActivity_appUpdateDraw
            0x00309e10L, // Java_com_ponos_battlecats_MyActivity_fsInit
            0x00309e18L, // Java_com_ponos_battlecats_MyActivity_gfxInit
            0x0030a098L, // Java_com_ponos_battlecats_MyActivity_appTouch
            0x0030a388L, // Java_com_ponos_battlecats_MyActivity_kill
            0x0098ef3cL, // Application Frame Engine (called from appUpdateDraw)
            0x009909c4L, // Application::Update thunk / base
            0x006f74a0L  // AssetCatalog::RegisterPacks
        };

        String[] targetNames = new String[] {
            "MyActivity_appInit",
            "MyActivity_appUpdateDraw",
            "MyActivity_fsInit",
            "MyActivity_gfxInit",
            "MyActivity_appTouch",
            "MyActivity_kill",
            "Application_EngineCoreLoop_0x98ef3c",
            "Application_Update_0x9909c4",
            "AssetCatalog_RegisterPacks_0x6f74a0"
        };

        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(currentProgram);

        logWriter.println("\n=== Decompilation Results ===");
        println("\n=== Decompilation Results ===");

        for (int i = 0; i < targetAddrs.length; i++) {
            Address addr = toAddr(targetAddrs[i]);
            String name = targetNames[i];

            Function func = getFunctionAt(addr);
            if (func == null) {
                // Attempt to disassemble and create function if missing
                try {
                    if (getInstructionAt(addr) == null) {
                        disassemble(addr);
                    }
                    func = createFunction(addr, name);
                } catch (Exception e) {
                    println("Note: Could not auto-create function at " + addr + ": " + e.getMessage());
                }
            }

            if (func == null) {
                String msg = String.format("0x%08x (%s): FAILED to locate/create function", targetAddrs[i], name);
                println(msg);
                logWriter.println(msg);
                continue;
            }

            DecompileResults res = decomp.decompileFunction(func, 60, monitor);
            if (res != null && res.decompileCompleted()) {
                String cCode = res.getDecompiledFunction().getC();
                File outFile = new File(outDir, name + ".c");
                PrintWriter cWriter = new PrintWriter(new FileWriter(outFile));
                cWriter.println("// Address: 0x" + Long.toHexString(targetAddrs[i]));
                cWriter.println("// Function: " + name);
                cWriter.println("// Decompiled by Ghidra 12.1.4 Headless");
                cWriter.println(cCode);
                cWriter.close();

                String msg = String.format("0x%08x (%s): DECOMPILED successfully -> %s (%d chars)",
                        targetAddrs[i], name, outFile.getName(), cCode.length());
                println(msg);
                logWriter.println(msg);
            } else {
                String errMsg = (res != null) ? res.getErrorMessage() : "Unknown decompiler error";
                String msg = String.format("0x%08x (%s): DECOMPILATION FAILED: %s", targetAddrs[i], name, errMsg);
                println(msg);
                logWriter.println(msg);
            }
        }

        logWriter.close();
        decomp.dispose();
        println("=== Script Finished Successfully ===");
    }
}
