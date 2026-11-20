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

public class DecompileBattleEngineBatch4 extends GhidraScript {
    private Function ensureBoundaryFunction(long base, long vma, String name) throws Exception {
        Address addr = toAddr(base + vma);
        Function func = getFunctionAt(addr);
        if (func == null) {
            Function containing = getFunctionContaining(addr);
            if (containing != null) {
                removeFunction(containing);
            }
            if (getInstructionAt(addr) == null) {
                disassemble(addr);
            }
            func = createFunction(addr, name);
        }
        return func;
    }

    @Override
    public void run() throws Exception {
        File outDir = new File("E:/rea/rea_battle_decomp/c_out_batch4");
        if (!outDir.exists()) {
            outDir.mkdirs();
        }

        long base = currentProgram.getImageBase().getOffset();
        PrintWriter summary = new PrintWriter(new FileWriter(new File(outDir, "_summary_batch4.txt")));

        long[] noReturns = new long[] {
            0x0030a4a8L,
            0x0030f948L,
            0x0030fc1cL,
            0x00311610L,
            0x00341cdcL,
            0x00370c38L,
            0x00abf40cL,
            0x00ac3380L
        };
        for (long vma : noReturns) {
            Address addr = toAddr(base + vma);
            Function nf = getFunctionAt(addr);
            if (nf == null) {
                if (getInstructionAt(addr) == null) {
                    disassemble(addr);
                }
                nf = createFunction(addr, String.format("NoRet_0x%08x", vma));
            }
            if (nf != null) {
                nf.setNoReturn(true);
                summary.printf("NORET 0x%08x -> %s%n", vma, nf.getName());
            }
        }

        long[] allBoundaries = new long[] {
            0x004aacc8L, 0x004aacf0L,
            0x004aad10L, 0x004aad90L,
            0x004ab0a8L, 0x004ab108L,
            0x004ab154L, 0x004ab174L,
            0x004ab294L, 0x004ab2d8L,
            0x004abf1cL, 0x004abfa4L,
            0x004ace18L,
            0x004af784L, 0x004af7bcL,
            0x004b095cL, 0x004b1270L,
            0x004bf8e8L, 0x004bfb98L,
            0x004df9b8L, 0x004dfb40L,
            0x00533678L, 0x005338c8L,
            0x005ce4ccL, 0x005ce60cL,
            0x005d3c94L,
            0x005d477cL, 0x005d4890L,
            0x005d4f44L, 0x005d50f4L,
            0x005d6da0L,
            0x005d8464L,
            0x005d9d6cL,
            0x005df080L, 0x005df1f0L,
            0x005e31e0L, 0x005e3730L,
            0x005e3770L, 0x005e3868L,
            0x005e437cL, 0x005e441cL,
            0x008b6decL, 0x008b95b4L,
            0x0090a85cL,
            0x0090b124L, 0x0090cc08L,
            0x00915484L, 0x009157fcL,
            0x009206acL,
            0x00920824L, 0x00920ad0L,
            0x009645a8L, 0x00964cb4L
        };

        long[] sorted = Arrays.copyOf(allBoundaries, allBoundaries.length);
        Arrays.sort(sorted);

        for (int i = sorted.length - 1; i >= 0; i--) {
            Address a = toAddr(base + sorted[i]);
            if (getInstructionAt(a) == null) {
                disassemble(a);
            }
        }

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

        long[] toDecompile = new long[] {
            0x004aacc8L,
            0x004aad10L,
            0x004ab0a8L,
            0x004ab154L,
            0x004ab294L,
            0x004abf1cL,
            0x004ace18L,
            0x004af784L,
            0x004b095cL,
            0x004bf8e8L,
            0x004df9b8L,
            0x00533678L,
            0x005ce4ccL,
            0x005d3c94L,
            0x005d477cL,
            0x005d4f44L,
            0x005d6da0L,
            0x005d8464L,
            0x005df080L,
            0x005e31e0L,
            0x005e3770L,
            0x005e437cL,
            0x008b6decL,
            0x0090a85cL,
            0x0090b124L,
            0x00915484L,
            0x009206acL,
            0x00920824L,
            0x009645a8L
        };

        DecompInterface ifc = new DecompInterface();
        DecompileOptions opts = new DecompileOptions();
        ifc.setOptions(opts);
        ifc.openProgram(currentProgram);

        for (long vma : toDecompile) {
            Function func = funcMap.get(vma);
            if (func == null) {
                summary.printf("SKIP_NO_FUNC 0x%08x%n", vma);
                continue;
            }
            DecompileResults res = ifc.decompileFunction(func, 180, monitor);
            if (res == null || !res.decompileCompleted()) {
                String err = (res != null) ? res.getErrorMessage() : "null";
                summary.printf("FAIL_DECOMP 0x%08x: %s%n", vma, err);
                continue;
            }
            String cCode = res.getDecompiledFunction().getC();
            File fOut = new File(outDir, String.format("BattleFn_0x%08x.c", vma));
            try (PrintWriter pw = new PrintWriter(new FileWriter(fOut))) {
                pw.printf("// ELF VMA: 0x%x%n", vma);
                pw.printf("// Ghidra Addr: 0x%s (ImageBase=0x%x)%n", func.getEntryPoint().toString(), base);
                pw.printf("// Size: %d bytes%n%n", func.getBody().getNumAddresses());
                pw.println(cCode);
            }
            summary.printf("OK 0x%08x -> %s (size=%d)%n", vma, fOut.getName(), func.getBody().getNumAddresses());
        }

        ifc.dispose();
        summary.close();
        println("Batch 4 decompilation complete.");
    }
}
