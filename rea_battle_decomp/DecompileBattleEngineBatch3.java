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

public class DecompileBattleEngineBatch3 extends GhidraScript {
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
        File outDir = new File("E:/rea/rea_battle_decomp/c_out_batch3");
        if (!outDir.exists()) {
            outDir.mkdirs();
        }

        long base = currentProgram.getImageBase().getOffset();
        PrintWriter summary = new PrintWriter(new FileWriter(new File(outDir, "_summary_batch3.txt")));

        // 0. Mark NoReturn helpers so decompiler does not emit bogus fallthroughs
        long[] noReturns = new long[] {
            0x00311610L, // __throw_out_of_range
            0x00370c38L, // throw helper
            0x00abf40cL, // _Unwind_Resume
            0x00ac3380L  // __stack_chk_fail
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

        // 1. Register all Batch 3 + adjacent boundary functions (reverse address order)
        long[] allBoundaries = new long[] {
            0x0047a29cL, // CannonMaxCharge
            0x0047a3a4L, // CannonInitCharge
            0x004ab2d8L,
            0x004b1c38L,
            0x004b1cc8L,
            0x004b1e64L,
            0x004bd678L,
            0x004bdba0L,
            0x004c1e04L,
            0x004c2188L,
            0x004c32c4L,
            0x004c3918L,
            0x004c3f24L, // Explosion damage (neighbor boundary)
            0x004c4088L,
            0x004c51bcL,
            0x004c5990L,
            0x004c5d04L,
            0x004c5e0cL, // CatCannonHitDispatch (neighbor)
            0x004c6340L, // CatCannonEffectEngine (neighbor)
            0x004c8660L, // FireCatCannon / Sub5DF080
            0x004c9224L,
            0x00529258L, // TalentOrbs
            0x005535d4L, // Talent helper 1
            0x00553738L, // Talent helper 2
            0x00553884L, // Talents
            0x005c731cL, // MainUpdateLoop (neighbor)
            0x005cbf84L, // CannonCooldownTick
            0x005dbc18L, // UpdateUnitsAndCastles
            0x005dd300L, // Unit end-state handler
            0x005dd3f0L, // Unit state update (attack/burrow/revive/warp/conjure)
            0x005dd600L, // Unit/Castle animation/tick?
            0x005defb4L, // Neighbor boundary
            0x005df080L, // Neighbor boundary
            0x005dfef0L,
            0x007700d4L, // CatCombo
            0x0091f9dcL, // Treasures
            0x0091fb18L, // Treasures helper
            0x0096b198L
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
            0x0047a29cL,
            0x0047a3a4L,
            0x004ab2d8L,
            0x004b1c38L,
            0x004b1cc8L,
            0x004b1e64L,
            0x004bd678L,
            0x004bdba0L,
            0x004c1e04L,
            0x004c2188L,
            0x004c32c4L,
            0x004c3918L,
            0x004c4088L,
            0x004c51bcL,
            0x004c5990L,
            0x004c5d04L,
            0x004c9224L,
            0x00529258L,
            0x005535d4L,
            0x00553738L,
            0x00553884L,
            0x005cbf84L,
            0x005dbc18L,
            0x005dd3f0L,
            0x005dd600L,
            0x005dfef0L,
            0x007700d4L,
            0x0091f9dcL,
            0x0091fb18L,
            0x0096b198L
        };

        DecompInterface decomp = new DecompInterface();
        decomp.setOptions(new DecompileOptions());
        decomp.openProgram(currentProgram);

        summary.println("\n=== Decompile Results Batch 3 ===");
        for (long vma : toDecompile) {
            Function f = funcMap.get(vma);
            if (f == null) {
                f = getFunctionAt(toAddr(base + vma));
            }
            if (f == null) {
                summary.printf("MISSING 0x%08x%n", vma);
                continue;
            }
            DecompileResults res = decomp.decompileFunction(f, 120, monitor);
            if (res == null || !res.decompileCompleted()) {
                summary.printf("DECOMP_FAIL 0x%08x: %s%n", vma, res != null ? res.getErrorMessage() : "null");
                continue;
            }
            String cCode = res.getDecompiledFunction().getC();
            File outFile = new File(outDir, String.format("BattleFn_0x%08x.c", vma));
            try (PrintWriter fw = new PrintWriter(new FileWriter(outFile))) {
                fw.printf("// ELF VMA: 0x%08x | Ghidra Addr: 0x%s | BodySize: %d%n",
                    vma, f.getEntryPoint().toString(), f.getBody().getNumAddresses());
                fw.println(cCode);
            }
            summary.printf("OK 0x%08x -> %s (%d chars)%n", vma, outFile.getName(), cCode.length());
        }
        summary.close();
        decomp.dispose();
    }
}
