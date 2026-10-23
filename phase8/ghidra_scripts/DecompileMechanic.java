import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;

public class DecompileMechanic extends GhidraScript {
    @Override
    public void run() throws Exception {
        println("=== Phase 8 Mechanic Decompiler Script ===");

        File outDir = new File("E:/rea/phase8/decompiled_c");
        if (!outDir.exists()) {
            outDir.mkdirs();
        }

        long[] targets = new long[] {
            0x004cecc0L, // MyApplication_battle_initWin (Dispatcher)
            0x004dff1cL  // MyApplication_battle_initWin_callback (Lambda evaluation)
        };

        String[] names = new String[] {
            "MyApplication_battle_initWin_0x4cecc0",
            "MyApplication_battle_initWin_callback_0x4dff1c"
        };

        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(currentProgram);

        for (int i = 0; i < targets.length; i++) {
            Address addr = toAddr(targets[i]);
            String name = names[i];

            Function func = getFunctionAt(addr);
            if (func == null) {
                try {
                    if (getInstructionAt(addr) == null) {
                        disassemble(addr);
                    }
                    func = createFunction(addr, name);
                } catch (Exception e) {
                    println("Could not create func at " + addr + ": " + e.getMessage());
                }
            }

            if (func != null) {
                DecompileResults res = decomp.decompileFunction(func, 60, monitor);
                if (res != null && res.decompileCompleted()) {
                    String cCode = res.getDecompiledFunction().getC();
                    File outFile = new File(outDir, name + ".c");
                    PrintWriter pw = new PrintWriter(new FileWriter(outFile));
                    pw.println("// Target Address: 0x" + Long.toHexString(targets[i]));
                    pw.println("// Function: " + name);
                    pw.println("// Decompiled by Ghidra 12.1.4 Headless");
                    pw.println(cCode);
                    pw.close();
                    println("Decompiled " + name + " -> " + outFile.getName() + " (" + cCode.length() + " chars)");
                } else {
                    println("Failed to decompile " + name + ": " + (res != null ? res.getErrorMessage() : "null"));
                }
            } else {
                println("Function at " + addr + " could not be resolved.");
            }
        }

        decomp.dispose();
        println("=== Script Finished ===");
    }
}
