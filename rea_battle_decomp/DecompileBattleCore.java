import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.*;

public class DecompileBattleCore extends GhidraScript {
    private Function ensureFunction(Address addr, String name) throws Exception {
        Function func = getFunctionAt(addr);
        if (func == null) {
            func = getFunctionContaining(addr);
        }
        if (func == null) {
            if (getInstructionAt(addr) == null) {
                disassemble(addr);
            }
            func = createFunction(addr, name);
        }
        return func;
    }

    @Override
    public void run() throws Exception {
        File outDir = new File("E:/rea/rea_battle_decomp/c_out");
        if (!outDir.exists()) {
            outDir.mkdirs();
        }
        // Clear old misleading files
        File[] oldFiles = outDir.listFiles();
        if (oldFiles != null) {
            for (File f : oldFiles) {
                f.delete();
            }
        }

        long base = currentProgram.getImageBase().getOffset();
        PrintWriter summary = new PrintWriter(new FileWriter(new File(outDir, "_summary.txt")));
        summary.printf("ImageBase: 0x%08x%n", base);
        summary.printf("Program Function Count: %d%n%n", currentProgram.getFunctionManager().getFunctionCount());

        DecompInterface decomp = new DecompInterface();
        DecompileOptions opts = new DecompileOptions();
        decomp.setOptions(opts);
        decomp.openProgram(currentProgram);

        long[] vmas = new long[] {
            0x005c731cL,
            0x005dbc18L,
            0x005dd300L,
            0x005df080L,
            0x005ce084L,
            0x004c5e0cL,
            0x004c6340L,
            0x004c8660L,
            0x008b6decL,
            0x008b99a0L,
            0x004dff1cL,
            0x00703318L,
            0x0095a59cL,
            0x0095a5dcL,
            0x00959ca8L,
            0x00959cf4L,
            0x0095a494L,
            0x0095c5f4L,
            0x00964d60L
        };

        String[] names = new String[] {
            "Battle_MainUpdateLoop",
            "Battle_Sub5DBC18",
            "Battle_Sub5DD300",
            "Battle_Sub5DF080",
            "Battle_CheckRange",
            "Battle_AttackHitDispatch",
            "Battle_DamageEngine",
            "Battle_Sub4C8660",
            "Battle_SpawnOrInitUnit",
            "Battle_Sub8B99A0",
            "Battle_EndOrResult",
            "Battle_SceneUpdateCaller",
            "Battle_Get_83938",
            "Battle_Set_83938",
            "Battle_Set_83ad4",
            "Battle_Add_83ad4",
            "Battle_CheckUnitCanMove",
            "Battle_AttackTrigger_95c5f4",
            "Battle_Helper_964d60"
        };

        Map<Long, Function> funcs = new LinkedHashMap<>();
        for (int i = 0; i < vmas.length; i++) {
            long vma = vmas[i];
            Address ghidraAddr = toAddr(base + vma);
            try {
                Function f = ensureFunction(ghidraAddr, names[i]);
                if (f != null) {
                    funcs.put(vma, f);
                    summary.printf("VMA 0x%08x (Ghidra 0x%s) -> %s @ 0x%s (size=%d)%n",
                        vma, ghidraAddr.toString(), f.getName(), f.getEntryPoint().toString(),
                        f.getBody().getNumAddresses());
                } else {
                    summary.printf("FAIL_CREATE VMA 0x%08x (Ghidra 0x%s) (%s)%n", vma, ghidraAddr.toString(), names[i]);
                }
            } catch (Exception e) {
                summary.printf("ERR VMA 0x%08x: %s%n", vma, e.getMessage());
            }
        }

        summary.println("\n=== Decompiling Functions ===");
        for (Map.Entry<Long, Function> entry : funcs.entrySet()) {
            long vma = entry.getKey();
            Function func = entry.getValue();
            String safeName = func.getName().replaceAll("[^a-zA-Z0-9_]", "_");
            String fileName = String.format("%s_vma_0x%08x.c", safeName, vma);

            StringBuilder meta = new StringBuilder();
            meta.append("// ELF VMA: 0x").append(Long.toHexString(vma)).append("\n");
            meta.append("// Ghidra Addr: 0x").append(func.getEntryPoint().toString()).append(" (ImageBase=0x").append(Long.toHexString(base)).append(")\n");
            meta.append("// Function: ").append(func.getName()).append("\n");
            meta.append("// Size: ").append(func.getBody().getNumAddresses()).append(" bytes\n");

            Set<Function> called = func.getCalledFunctions(monitor);
            meta.append("// Callees (" + called.size() + "): ");
            for (Function c : called) {
                long cVma = c.getEntryPoint().getOffset() - base;
                meta.append(c.getName()).append("@0x").append(Long.toHexString(cVma)).append(", ");
            }
            meta.append("\n\n");

            DecompileResults res = decomp.decompileFunction(func, 180, monitor);
            if (res != null && res.decompileCompleted()) {
                String cCode = res.getDecompiledFunction().getC();
                PrintWriter cw = new PrintWriter(new FileWriter(new File(outDir, fileName)));
                cw.print(meta.toString());
                cw.println(cCode);
                cw.close();
                summary.printf("OK   VMA 0x%08x -> %s (%d bytes)%n", vma, fileName, cCode.length());
            } else {
                String err = (res != null) ? res.getErrorMessage() : "null result";
                summary.printf("FAIL VMA 0x%08x (%s): %s%n", vma, func.getName(), err);
            }
        }

        summary.close();
        println("Done! ImageBase=0x" + Long.toHexString(base));
    }
}
