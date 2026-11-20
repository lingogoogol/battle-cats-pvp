import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.*;

public class DecompileBattleEngineBatch2 extends GhidraScript {
    private Function ensureBoundaryFunction(long base, long vma, String name) throws Exception {
        Address addr = toAddr(base + vma);
        Function func = getFunctionAt(addr);
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
        File outDir = new File("E:/rea/rea_battle_decomp/c_out_batch2");
        if (!outDir.exists()) {
            outDir.mkdirs();
        }

        long base = currentProgram.getImageBase().getOffset();
        PrintWriter summary = new PrintWriter(new FileWriter(new File(outDir, "_summary_batch2.txt")));

        // 1. Register ALL function boundaries inside Battle Engine BEFORE decompiling anything!
        // Ordered high-to-low or all at once with disassemble+createFunction so no function swallows another
        long[] allBoundaries = new long[] {
            0x004c3f24L,
            0x004c5e0cL,
            0x004c6340L,
            0x005cdcdcL,
            0x005cdfa4L,
            0x005ce084L,
            0x005ce4ccL,
            0x005ce60cL,
            0x005ce63cL,
            0x005d3c94L,
            0x005d477cL,
            0x005d4890L,
            0x005d49d4L,
            0x005d4f44L,
            0x005d50f4L,
            0x005d5498L,
            0x005d6b98L,
            0x005d6da0L,
            0x005d8464L,
            0x005d9d6cL,
            0x005da618L,
            0x005daa18L,
            0x005daa58L,
            0x005db2c0L,
            0x005db4b4L,
            0x005db6acL,
            0x005dbabcL,
            0x005dbc18L,
            0x005dd300L,
            0x005dd3f0L,
            0x005dd600L,
            0x005defb4L,
            0x005df080L,
            0x0090ebc4L,
            0x009157fcL,
            // Register MainUpdateLoop AFTER 0x5cdcdc / 0x5ce084 are already created!
            0x005c731cL
        };

        // Pass 1: disassemble from bottom to top or just create functions
        for (int i = allBoundaries.length - 1; i >= 0; i--) {
            long vma = allBoundaries[i];
            Address a = toAddr(base + vma);
            if (getInstructionAt(a) == null) {
                disassemble(a);
            }
        }
        // Pass 2: createFunction on every entry (remove overlapping body if needed by creating in reverse address order!)
        long[] sorted = Arrays.copyOf(allBoundaries, allBoundaries.length);
        Arrays.sort(sorted);
        Map<Long, Function> funcMap = new LinkedHashMap<>();
        for (int i = sorted.length - 1; i >= 0; i--) {
            long vma = sorted[i];
            String name = String.format("BattleFn_0x%08x", vma);
            try {
                Function f = ensureBoundaryFunction(base, vma, name);
                if (f != null) {
                    funcMap.put(vma, f);
                    summary.printf("BOUND 0x%08x -> %s @ 0x%s (size=%d)%n", vma, f.getName(), f.getEntryPoint().toString(), f.getBody().getNumAddresses());
                } else {
                    summary.printf("FAIL_BOUND 0x%08x%n", vma);
                }
            } catch (Exception e) {
                summary.printf("ERR_BOUND 0x%08x: %s%n", vma, e.getMessage());
            }
        }

        // Core targets to decompile in detail
        long[] toDecompile = new long[] {
            0x005ce084L, // CheckRange
            0x005ce63cL, // Unit combat / attack execution (22KB)
            0x005d5498L, // Normal/Wave Hit Loop
            0x005d6da0L, // ApplyDamageAndEffects (KB, Sage, Crit, Barrier, Shield, Surge...)
            0x005d8464L, // Wave/Surge Hit Loop
            0x005d9d6cL, // Calls Attack & WaveSurge
            0x005da618L,
            0x005db2c0L,
            0x004c3f24L, // Explosion damage
            0x009157fcL, // SortieCatCannon
            0x0090ebc4L, // BarrierBreaker / Cannon effect
            0x005c731cL  // MainUpdateLoop (now bounded cleanly before 0x5cdcdc)
        };

        DecompInterface decomp = new DecompInterface();
        decomp.setOptions(new DecompileOptions());
        decomp.openProgram(currentProgram);

        summary.println("\n=== Decompile Results ===");
        for (long vma : toDecompile) {
            Function f = funcMap.get(vma);
            if (f == null) {
                f = getFunctionAt(toAddr(base + vma));
            }
            if (f == null) {
                summary.printf("MISSING 0x%08x%n", vma);
                continue;
            }
            String fileName = String.format("BattleFn_0x%08x.c", vma);
            DecompileResults res = decomp.decompileFunction(f, 180, monitor);
            if (res != null && res.decompileCompleted()) {
                String cCode = res.getDecompiledFunction().getC();
                PrintWriter cw = new PrintWriter(new FileWriter(new File(outDir, fileName)));
                cw.println("// ELF VMA: 0x" + Long.toHexString(vma));
                cw.println("// Ghidra Addr: 0x" + f.getEntryPoint().toString() + " (ImageBase=0x" + Long.toHexString(base) + ")");
                cw.println("// Size: " + f.getBody().getNumAddresses() + " bytes\n");
                cw.println(cCode);
                cw.close();
                summary.printf("OK   0x%08x -> %s (%d bytes)%n", vma, fileName, cCode.length());
            } else {
                summary.printf("FAIL 0x%08x: %s%n", vma, res != null ? res.getErrorMessage() : "null");
            }
        }
        summary.close();
        println("Batch 2 decompilation complete!");
    }
}
