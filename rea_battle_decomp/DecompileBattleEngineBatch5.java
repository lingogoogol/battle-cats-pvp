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

public class DecompileBattleEngineBatch5 extends GhidraScript {
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
        File outDir = new File("E:/rea/rea_battle_decomp/c_out_batch5");
        if (!outDir.exists()) {
            outDir.mkdirs();
        }

        long base = currentProgram.getImageBase().getOffset();
        PrintWriter summary = new PrintWriter(new FileWriter(new File(outDir, "_summary_batch5.txt")));

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
            0x004b1be4L, 0x004b1bf4L, 0x004b1c38L,
            0x004b1e64L, 0x004b1f30L, 0x004b1f74L, 0x004b2028L, 0x004b2104L,
            0x004b217cL, 0x004b21ecL, 0x004b2234L, 0x004b22a4L, 0x004b2314L, 0x004b235cL,
            0x004b2394L, 0x004b23ccL, 0x004b261cL, 0x004b26a4L, 0x004b276cL,
            0x004ba6d4L, 0x004ba7ecL,
            0x004bbf4cL, 0x004bc08cL,
            0x004bc3b4L, 0x004bc444L,
            0x004bc54cL, 0x004bc5c4L,
            0x004bc6bcL, 0x004bc748L,
            0x004bc854L, 0x004bc8e0L,
            0x004bc9ecL, 0x004bcb18L,
            0x004bcc2cL, 0x004bcd58L,
            0x004bce6cL, 0x004bcf80L,
            0x004bd09cL, 0x004bd1ccL,
            0x004bd678L, 0x004bdba0L, 0x004bddfcL,
            0x004c14c8L, 0x004c14f8L,
            0x004c1960L, 0x004c1990L,
            0x004c5990L, 0x004c5e0cL, 0x004c6340L, 0x004c6da8L,
            0x004c8660L, 0x004c8c2cL,
            0x005db4b4L, 0x005dba74L,
            0x005dd300L, 0x005dd3f0L, 0x005dd600L, 0x005df080L,
            0x005dfef0L, 0x005e0280L,
            0x008b95b4L,
            0x009632d8L, 0x00963984L,
            0x00964cb4L, 0x00964d60L
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
            0x004b1be4L,
            0x004b1bf4L,
            0x004b1e64L,
            0x004b1f30L,
            0x004b1f74L,
            0x004b2028L,
            0x004b217cL,
            0x004b21ecL,
            0x004b2234L,
            0x004b2394L,
            0x004b23ccL,
            0x004b26a4L,
            0x004ba6d4L,
            0x004bbf4cL,
            0x004bc3b4L,
            0x004bc54cL,
            0x004bc6bcL,
            0x004bc854L,
            0x004bc9ecL,
            0x004bcc2cL,
            0x004bce6cL,
            0x004bd09cL,
            0x004bd678L,
            0x004bdba0L,
            0x004c14c8L,
            0x004c1960L,
            0x004c5990L,
            0x004c5e0cL,
            0x004c6340L,
            0x004c8660L,
            0x005db4b4L,
            0x005dd300L,
            0x005dd3f0L,
            0x005dd600L,
            0x005dfef0L,
            0x008b95b4L,
            0x009632d8L,
            0x00964cb4L
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
        println("Batch 5 decompilation complete.");
    }
}
