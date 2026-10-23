import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;

public class DecompileDamage extends GhidraScript {
    @Override
    public void run() throws Exception {
        println("=== Phase 9 Combat Damage Decompiler Script ===");

        File outDir = new File("E:/rea/phase9/decompiled_c");
        if (!outDir.exists()) {
            outDir.mkdirs();
        }

        long[] targets = new long[] {
            0x004c6340L, // Battle_ApplyDamageToUnit (Main damage calculation)
            0x00958ba4L, // Unit_GetAttributeOrState
            0x0095987cL, // Unit_GetHP
            0x0095ac18L, // Unit_CheckDamageImmunity
            0x00957c8cL, // Unit_GetTargetType
            0x00960488L  // Unit_ApplyHPChange
        };

        String[] names = new String[] {
            "Battle_ApplyDamageToUnit_0x4c6340",
            "Unit_GetAttributeOrState_0x958ba4",
            "Unit_GetHP_0x95987c",
            "Unit_CheckDamageImmunity_0x95ac18",
            "Unit_GetTargetType_0x957c8c",
            "Unit_ApplyHPChange_0x960488"
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
