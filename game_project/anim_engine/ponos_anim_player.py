"""
Official PONOS 2D Skeletal Animation Player for The Battle Cats.
Parses official .imgcut (Atlas slices), .mamodel (Bone hierarchy + units + bounding ints),
and .maanim (Keyframe tracks with additive/multiplicative modifications & 5 easing modes).
Renders authentic hierarchical 2D skeletal transformations in Pygame.
"""

import os
import math
import pygame
from typing import List, Dict, Tuple, Optional, Any

class ImgCutEntry:
    def __init__(self, cut_id: int, x: int, y: int, w: int, h: int, name: str = ""):
        self.cut_id = cut_id
        self.x = x
        self.y = y
        self.w = w
        self.h = h
        self.name = name

class PonosImgcut:
    def __init__(self, filepath: str):
        self.cuts: Dict[int, ImgCutEntry] = {}
        self.png_name: str = ""
        self.load(filepath)

    def load(self, filepath: str):
        with open(filepath, "r", encoding="utf-8-sig", errors="ignore") as f:
            lines = [l.strip().lstrip('\ufeff') for l in f if l.strip().lstrip('\ufeff')]

        start_idx = 0
        if lines and lines[0].startswith("[imgcut]"):
            start_idx = 1

        if start_idx < len(lines) and lines[start_idx].isdigit() and (
            start_idx + 2 >= len(lines) or not lines[start_idx + 2].isdigit()
        ):
            count = int(lines[start_idx])
            start_idx += 1
        elif len(lines) > start_idx + 2 and lines[start_idx + 2].isdigit():
            self.png_name = lines[start_idx + 1]
            count = int(lines[start_idx + 2])
            start_idx += 3
        else:
            count = 0

        cut_idx = 0
        for i in range(start_idx, len(lines)):
            if count > 0 and cut_idx >= count:
                break
            line = lines[i]
            if line.startswith("["):
                break
            parts = [p.strip() for p in line.split(",")]
            if len(parts) >= 4:
                try:
                    x, y, w, h = int(parts[0]), int(parts[1]), int(parts[2]), int(parts[3])
                    name = parts[4] if len(parts) > 4 else ""
                    self.cuts[cut_idx] = ImgCutEntry(cut_idx, x, y, w, h, name)
                    cut_idx += 1
                except ValueError:
                    break

class ModelPart:
    def __init__(self, index: int, parent_id: int, unit_id: int, cut_id: int, z_depth: int,
                 x: int, y: int, pivot_x: int, pivot_y: int, scale_x: int, scale_y: int,
                 rotation: int, alpha: int, glow: int, name: str = ""):
        self.index = index
        self.parent_id = parent_id
        self.unit_id = unit_id
        self.cut_id = cut_id
        self.z_depth = z_depth
        self.x = x
        self.y = y
        self.pivot_x = pivot_x
        self.pivot_y = pivot_y
        self.scale_x = scale_x
        self.scale_y = scale_y
        self.rotation = rotation
        self.alpha = alpha
        self.glow = glow
        self.name = name

        # Dynamic runtime values
        self.cur_parent_id = parent_id
        self.cur_unit_id = unit_id
        self.cur_cut_id = cut_id
        self.cur_z_depth = z_depth
        self.cur_x = x
        self.cur_y = y
        self.cur_pivot_x = pivot_x
        self.cur_pivot_y = pivot_y
        self.cur_gsca = 1000
        self.cur_scale_x = scale_x
        self.cur_scale_y = scale_y
        self.cur_rotation = rotation
        self.cur_alpha = alpha
        self.cur_h_flip = False
        self.cur_v_flip = False

    def reset(self, scale_unit: int = 1000):
        self.cur_parent_id = self.parent_id
        self.cur_unit_id = self.unit_id
        self.cur_cut_id = self.cut_id
        self.cur_z_depth = self.z_depth
        self.cur_x = self.x
        self.cur_y = self.y
        self.cur_pivot_x = self.pivot_x
        self.cur_pivot_y = self.pivot_y
        self.cur_gsca = scale_unit
        self.cur_scale_x = self.scale_x
        self.cur_scale_y = self.scale_y
        self.cur_rotation = self.rotation
        self.cur_alpha = self.alpha
        self.cur_h_flip = False
        self.cur_v_flip = False

class PonosMamodel:
    def __init__(self, filepath: str):
        self.parts: List[ModelPart] = []
        self.scale_unit = 1000
        self.angle_unit = 3600
        self.alpha_unit = 1000
        self.ints: List[List[int]] = []
        self.load(filepath)

    def load(self, filepath: str):
        with open(filepath, "r", encoding="utf-8-sig", errors="ignore") as f:
            lines = [l.strip().lstrip('\ufeff') for l in f if l.strip().lstrip('\ufeff')]

        start_idx = 0
        if lines and lines[0].startswith("[modelanim:model"):
            start_idx = 1

        version = int(lines[start_idx].split(",")[0].strip())
        num_parts = int(lines[start_idx + 1].split(",")[0].strip())
        start_idx += 2

        for i in range(num_parts):
            parts = [p.strip() for p in lines[start_idx + i].split(",")]
            parent_id = int(parts[0])
            unit_id = int(parts[1])
            cut_id = int(parts[2])
            z_depth = int(parts[3])
            x = int(parts[4])
            y = int(parts[5])
            pivot_x = int(parts[6])
            pivot_y = int(parts[7])
            scale_x = int(parts[8])
            scale_y = int(parts[9])
            rotation = int(parts[10])
            alpha = int(parts[11])
            glow = int(parts[12]) if len(parts) > 12 and parts[12].lstrip("-").isdigit() else 0
            name = parts[13] if len(parts) > 13 else ""
            self.parts.append(ModelPart(i, parent_id, unit_id, cut_id, z_depth, x, y,
                                        pivot_x, pivot_y, scale_x, scale_y, rotation, alpha, glow, name))

        rem_idx = start_idx + num_parts
        if rem_idx < len(lines):
            u_parts = [p.strip() for p in lines[rem_idx].split(",") if p.strip()]
            if len(u_parts) >= 3:
                try:
                    self.scale_unit = max(1, int(u_parts[0]))
                    self.angle_unit = max(1, int(u_parts[1]))
                    self.alpha_unit = max(1, int(u_parts[2]))
                except ValueError:
                    pass
            rem_idx += 1

        if rem_idx < len(lines):
            try:
                num_ints = int(lines[rem_idx].split(",")[0].strip())
                rem_idx += 1
                for j in range(num_ints):
                    if rem_idx + j < len(lines):
                        i_parts = [p.strip() for p in lines[rem_idx + j].split(",")]
                        if len(i_parts) >= 6:
                            self.ints.append([int(x) for x in i_parts[:6] if x.lstrip("-").isdigit()])
            except ValueError:
                pass

class KeyFrame:
    def __init__(self, frame: int, value: int, ease_mode: int, ease_power: int):
        self.frame = frame
        self.value = value
        self.ease_mode = ease_mode
        self.ease_power = ease_power

class AnimTrack:
    def __init__(self, part_id: int, mod_type: int, loop: int, min_val: int, max_val: int, name: str = ""):
        self.part_id = part_id
        self.mod_type = mod_type
        self.loop = loop
        self.min_val = min_val
        self.max_val = max_val
        self.name = name
        self.keyframes: List[KeyFrame] = []

    def _ease_polynomial(self, kf_idx: int, local_frame: float) -> float:
        high = kf_idx
        low = kf_idx
        for j in range(kf_idx - 1, -1, -1):
            if self.keyframes[j].ease_mode == 3:
                low = j
            else:
                break
        for j in range(kf_idx + 1, len(self.keyframes)):
            high = j
            if self.keyframes[j].ease_mode != 3:
                break
        total = 0.0
        for j in range(low, high + 1):
            val = float(self.keyframes[j].value * 4096)
            for k in range(low, high + 1):
                if k != j:
                    denom = self.keyframes[j].frame - self.keyframes[k].frame
                    if denom != 0:
                        val = val * (local_frame - self.keyframes[k].frame) / denom
            total += val
        return total / 4096.0

    def get_value(self, frame: float) -> Optional[int]:
        if not self.keyframes:
            return None

        start_frame = self.keyframes[0].frame
        end_frame = self.keyframes[-1].frame
        if frame < start_frame:
            return None

        span = end_frame - start_frame
        if frame < end_frame or span <= 0:
            local_frame = frame
        elif self.loop == -1:
            local_frame = ((frame - start_frame) % span) + start_frame
        elif self.loop >= 1:
            if (frame - start_frame) / float(span) < self.loop:
                local_frame = ((frame - start_frame) % span) + start_frame
            else:
                local_frame = float(end_frame)
        else:
            local_frame = float(end_frame)

        if start_frame == end_frame:
            return int(self.keyframes[0].value)
        if local_frame >= end_frame:
            return int(self.keyframes[-1].value)

        for i in range(len(self.keyframes) - 1):
            kf1 = self.keyframes[i]
            kf2 = self.keyframes[i + 1]
            if kf1.frame <= local_frame < kf2.frame:
                f_span = kf2.frame - kf1.frame
                if f_span <= 0 or kf1.ease_mode == 1:
                    # ease_mode == 1 is INSTANT step in Ponos
                    return int(kf1.value)
                t = (local_frame - kf1.frame) / float(f_span)
                if kf1.ease_mode == 0:
                    # ease_mode == 0 is LINEAR in Ponos
                    return int(kf1.value + t * (kf2.value - kf1.value))
                elif kf1.ease_mode == 2:
                    # Exponential easing
                    p = kf1.ease_power
                    if p >= 0:
                        factor = 1.0 - math.sqrt(max(0.0, 1.0 - math.pow(t, p)))
                    else:
                        factor = math.sqrt(max(0.0, 1.0 - math.pow(1.0 - t, -p)))
                    return int(kf1.value + factor * (kf2.value - kf1.value))
                elif kf1.ease_mode == 3:
                    return int(self._ease_polynomial(i, local_frame))
                elif kf1.ease_mode == 4:
                    factor = (1.0 - math.cos(t * math.pi / 2.0)) / 2.0
                    return int(kf1.value + factor * (kf2.value - kf1.value))
                else:
                    return int(kf1.value + t * (kf2.value - kf1.value))
        return int(self.keyframes[-1].value)

class PonosMaanim:
    def __init__(self, filepath: str):
        self.tracks: List[AnimTrack] = []
        self.max_frame = 1
        self.load(filepath)

    def load(self, filepath: str):
        with open(filepath, "r", encoding="utf-8-sig", errors="ignore") as f:
            lines = [l.strip().lstrip('\ufeff') for l in f if l.strip().lstrip('\ufeff')]

        start_idx = 0
        if lines and lines[0].startswith("[modelanim:animation"):
            start_idx = 1

        if start_idx + 1 >= len(lines):
            return
        num_tracks = int(lines[start_idx + 1].split(",")[0].strip())
        start_idx += 2

        idx = start_idx
        for _ in range(num_tracks):
            if idx >= len(lines):
                break
            head_parts = [p.strip() for p in lines[idx].split(",")]
            part_id = int(head_parts[0])
            mod_type = int(head_parts[1])
            loop = int(head_parts[2]) if len(head_parts) > 2 and head_parts[2].lstrip("-").isdigit() else -1
            min_v = int(head_parts[3]) if len(head_parts) > 3 and head_parts[3].lstrip("-").isdigit() else 0
            max_v = int(head_parts[4]) if len(head_parts) > 4 and head_parts[4].lstrip("-").isdigit() else 0
            track = AnimTrack(part_id, mod_type, loop, min_v, max_v)
            idx += 1

            if idx >= len(lines):
                break
            num_kf = int(lines[idx].split(",")[0].strip())
            idx += 1
            for _ in range(num_kf):
                if idx >= len(lines):
                    break
                kf_parts = [int(p.strip()) for p in lines[idx].split(",")[:4] if p.strip().lstrip("-").isdigit()]
                if len(kf_parts) >= 4:
                    kf = KeyFrame(kf_parts[0], kf_parts[1], kf_parts[2], kf_parts[3])
                    track.keyframes.append(kf)
                    loop_mult = track.loop if 0 < track.loop <= 4 else 1
                    end_f = kf.frame * loop_mult
                    if end_f > self.max_frame:
                        self.max_frame = end_f
                idx += 1
            self.tracks.append(track)

class PonosAnimationPlayer:
    def __init__(self, png_path: str, imgcut_path: str, mamodel_path: str, anim_paths: Dict[str, str]):
        raw_surf = pygame.image.load(png_path)
        if pygame.display.get_surface() is not None:
            self.sprite_sheet = raw_surf.convert_alpha()
        else:
            self.sprite_sheet = raw_surf
        self.imgcut = PonosImgcut(imgcut_path)
        self.mamodel = PonosMamodel(mamodel_path)
        self.animations: Dict[str, PonosMaanim] = {}
        for k, p in anim_paths.items():
            if os.path.isfile(p):
                self.animations[k] = PonosMaanim(p)

        self.cut_surfaces: Dict[int, pygame.Surface] = {}
        self._slice_sprites()

        self.current_anim_name = list(self.animations.keys())[0] if self.animations else ""
        self.current_frame = 0.0

    def _slice_sprites(self):
        sw, sh = self.sprite_sheet.get_size()
        for cut_id, cut in self.imgcut.cuts.items():
            if cut.w > 0 and cut.h > 0:
                cx = max(0, min(sw - 1, cut.x))
                cy = max(0, min(sh - 1, cut.y))
                cw = min(cut.w, sw - cx)
                ch = min(cut.h, sh - cy)
                if cw > 0 and ch > 0:
                    rect = pygame.Rect(cx, cy, cw, ch)
                    try:
                        sub = self.sprite_sheet.subsurface(rect).copy()
                        if sub.get_bitsize() < 24:
                            s32 = pygame.Surface((cw, ch), pygame.SRCALPHA)
                            s32.blit(sub, (0, 0))
                            sub = s32
                        self.cut_surfaces[cut_id] = sub
                    except Exception:
                        pass

    def get_anim_length(self, anim_name: str) -> int:
        anim = self.animations.get(anim_name)
        return max(1, anim.max_frame) if anim else 1

    def set_animation(self, anim_name: str):
        if anim_name in self.animations and self.current_anim_name != anim_name:
            self.current_anim_name = anim_name
            self.current_frame = 0.0

    def update(self, dt_frames: float = 1.0):
        self.current_frame += dt_frames

    def render(self, surface: pygame.Surface, root_x: int, root_y: int, scale: float = 1.0, flip_h: bool = False, hit_flash: bool = False):
        anim = self.animations.get(self.current_anim_name)
        su = float(self.mamodel.scale_unit)
        au = float(self.mamodel.angle_unit)
        alu = float(self.mamodel.alpha_unit)
        num_parts = len(self.mamodel.parts)

        # 1. Reset parts to base pose
        for p in self.mamodel.parts:
            p.reset(self.mamodel.scale_unit)

        # 2. Apply animation tracks using authentic Ponos modification formulas (integer 30fps frame counter)
        int_frame = int(math.floor(self.current_frame))
        if anim:
            for track in anim.tracks:
                if 0 <= track.part_id < num_parts:
                    part = self.mamodel.parts[track.part_id]
                    val = track.get_value(int_frame)
                    if val is not None:
                        mt = track.mod_type
                        if mt == 0:
                            part.cur_parent_id = val
                        elif mt == 1:
                            part.cur_unit_id = val
                        elif mt == 2:
                            part.cur_cut_id = val
                        elif mt == 3:
                            part.cur_z_depth = val * num_parts + part.index
                        elif mt == 4:
                            part.cur_x = part.x + val
                        elif mt == 5:
                            part.cur_y = part.y + val
                        elif mt == 6:
                            part.cur_pivot_x = part.pivot_x + val
                        elif mt == 7:
                            part.cur_pivot_y = part.pivot_y + val
                        elif mt == 8:
                            part.cur_gsca = val
                        elif mt == 9:
                            part.cur_scale_x = int(val * part.scale_x / su)
                        elif mt == 10:
                            part.cur_scale_y = int(val * part.scale_y / su)
                        elif mt == 11:
                            part.cur_rotation = part.rotation + val
                        elif mt == 12:
                            part.cur_alpha = int(val * part.alpha / alu)
                        elif mt == 13:
                            part.cur_h_flip = bool(val)
                        elif mt == 14:
                            part.cur_v_flip = bool(val)

        # 3. Compute global 2x3 affine transforms matching tbcml/core/anim/model_part.py (transform + draw_part)
        rec_scales: Dict[int, Tuple[float, float]] = {}
        rec_alphas: Dict[int, float] = {}
        matrices: Dict[int, List[float]] = {}
        visiting = set()

        def get_real_scale(p: ModelPart) -> Tuple[float, float]:
            gsca = p.cur_gsca / su
            sx = (p.cur_scale_x / su) * gsca * (-1.0 if p.cur_h_flip else 1.0)
            sy = (p.cur_scale_y / su) * gsca * (-1.0 if p.cur_v_flip else 1.0)
            return sx, sy

        def get_recursive_scale(idx: int) -> Tuple[float, float]:
            if idx in rec_scales:
                return rec_scales[idx]
            if idx in visiting or idx < 0 or idx >= num_parts:
                return (1.0, 1.0)
            visiting.add(idx)
            p = self.mamodel.parts[idx]
            sx, sy = get_real_scale(p)
            if 0 <= p.cur_parent_id < num_parts and p.cur_parent_id != idx:
                psx, psy = get_recursive_scale(p.cur_parent_id)
                sx *= psx
                sy *= psy
            visiting.remove(idx)
            rec_scales[idx] = (sx, sy)
            return (sx, sy)

        def get_recursive_alpha(idx: int) -> float:
            if idx in rec_alphas:
                return rec_alphas[idx]
            if idx in visiting or idx < 0 or idx >= num_parts:
                return 1.0
            visiting.add(idx)
            p = self.mamodel.parts[idx]
            alp = max(0.0, min(1.0, p.cur_alpha / alu))
            if 0 <= p.cur_parent_id < num_parts and p.cur_parent_id != idx:
                alp *= get_recursive_alpha(p.cur_parent_id)
            visiting.remove(idx)
            rec_alphas[idx] = alp
            return alp

        def get_base_p0_size() -> Tuple[float, float]:
            if not self.mamodel.parts:
                return (1.0, 1.0)
            p0 = self.mamodel.parts[0]
            return (p0.scale_x / su, p0.scale_y / su)

        def get_matrix(idx: int) -> List[float]:
            if idx in matrices:
                return matrices[idx]
            if idx in visiting or idx < 0 or idx >= num_parts:
                return [1.0, 0.0, 0.0, 0.0, 1.0, 0.0]
            visiting.add(idx)
            p = self.mamodel.parts[idx]
            siz_x, siz_y = scale, scale
            if 0 <= p.cur_parent_id < num_parts and p.cur_parent_id != idx:
                parent_mat = get_matrix(p.cur_parent_id)
                psx, psy = get_recursive_scale(p.cur_parent_id)
                siz_x = psx * scale
                siz_y = psy * scale
                m0, m1, m2, m3, m4, m5 = parent_mat
            else:
                m0, m1, m2, m3, m4, m5 = 1.0, 0.0, 0.0, 0.0, 1.0, 0.0

            if idx != 0:
                t_pos_x = p.cur_x * siz_x
                t_pos_y = p.cur_y * siz_y
                m2 += (m0 * t_pos_x) + (m1 * t_pos_y)
                m5 += (m3 * t_pos_x) + (m4 * t_pos_y)
            else:
                data = self.mamodel.ints[0] if (self.mamodel.ints and len(self.mamodel.ints[0]) >= 4) else [0, 0, 0, 0]
                base_p0_x, base_p0_y = get_base_p0_size()
                p3_x = data[2] * base_p0_x * scale
                p3_y = data[3] * base_p0_y * scale
                rec_p0_x, rec_p0_y = get_recursive_scale(0)
                px = p.cur_pivot_x * rec_p0_x * scale
                py = p.cur_pivot_y * rec_p0_y * scale
                x = px - p3_x
                y = py - p3_y
                m2 += (m0 * x) + (m1 * y)
                m5 += (m3 * x) + (m4 * y)

            if p.cur_rotation != 0:
                degrees = (p.cur_rotation / au) * 360.0
                radians = math.radians(degrees)
                sin_r = math.sin(radians)
                cos_r = math.cos(radians)
                f0 = (m0 * cos_r) + (m1 * sin_r)
                f1 = (m0 * -sin_r) + (m1 * cos_r)
                f3 = (m3 * cos_r) + (m4 * sin_r)
                f4 = (m3 * -sin_r) + (m4 * cos_r)
                m0, m1, m3, m4 = f0, f1, f3, f4

            visiting.remove(idx)
            mat = [m0, m1, m2, m3, m4, m5]
            matrices[idx] = mat
            return mat

        for i in range(num_parts):
            get_recursive_scale(i)
            get_recursive_alpha(i)
            get_matrix(i)

        # 4. Sort parts by z-depth and draw (skip dummy/invisible parts where parent_id < 0 or unit_id < 0)
        sorted_parts = sorted(range(num_parts), key=lambda i: (self.mamodel.parts[i].cur_z_depth, i))
        dir_mult = -1.0 if flip_h else 1.0
        for part_idx in sorted_parts:
            part = self.mamodel.parts[part_idx]
            if part.cur_parent_id < 0 or part.cur_unit_id < 0:
                continue
            alpha = rec_alphas[part_idx]
            if alpha <= 0.01:
                continue
            cut_id = part.cur_cut_id
            cut_surf = self.cut_surfaces.get(cut_id)
            if cut_surf is None:
                continue

            rec_sx, rec_sy = rec_scales[part_idx]
            mat = matrices[part_idx]
            sx_val = rec_sx * scale * dir_mult
            sy_val = rec_sy * scale
            abs_sx = abs(sx_val)
            abs_sy = abs(sy_val)
            w = max(1, int(round(cut_surf.get_width() * abs_sx)))
            h = max(1, int(round(cut_surf.get_height() * abs_sy)))
            if w <= 1 and h <= 1:
                continue

            scaled_surf = pygame.transform.smoothscale(cut_surf, (w, h))

            pivot_px = float(part.cur_pivot_x) * abs_sx
            pivot_py = float(part.cur_pivot_y) * abs_sy

            eff_flip_x = (sx_val < 0)
            eff_flip_y = (sy_val < 0)
            if eff_flip_x or eff_flip_y:
                scaled_surf = pygame.transform.flip(scaled_surf, eff_flip_x, eff_flip_y)
                if eff_flip_x:
                    pivot_px = float(w) - pivot_px
                if eff_flip_y:
                    pivot_py = float(h) - pivot_py

            # Extract pure rotation angle from matrix (m0=cos, m3=sin) and negate if mirrored globally (flip_h)
            rot_cw = math.degrees(math.atan2(mat[3], mat[0])) * dir_mult
            if abs(rot_cw) > 0.05:
                rotated_surf = pygame.transform.rotate(scaled_surf, -rot_cw)
                rw, rh = rotated_surf.get_size()
                rcx, rcy = rw / 2.0, rh / 2.0
                cx, cy = w / 2.0, h / 2.0
                dx = pivot_px - cx
                dy = pivot_py - cy
                rad = math.radians(rot_cw)
                rot_pivot_x = rcx + (dx * math.cos(rad) - dy * math.sin(rad))
                rot_pivot_y = rcy + (dx * math.sin(rad) + dy * math.cos(rad))
            else:
                rotated_surf = scaled_surf
                rot_pivot_x = pivot_px
                rot_pivot_y = pivot_py

            world_x = root_x + mat[2] * dir_mult
            world_y = root_y + mat[5]
            draw_x = int(round(world_x - rot_pivot_x))
            draw_y = int(round(world_y - rot_pivot_y))

            if hit_flash:
                flash_surf = rotated_surf.copy()
                flash_surf.fill((160, 160, 160), special_flags=pygame.BLEND_RGB_ADD)
                if alpha < 0.99:
                    flash_surf.set_alpha(int(alpha * 255))
                surface.blit(flash_surf, (draw_x, draw_y))
            elif part.glow in (1, 2, 3, -1):
                premult = pygame.Surface(rotated_surf.get_size())
                if alpha < 0.99:
                    rotated_surf = rotated_surf.copy()
                    rotated_surf.set_alpha(int(alpha * 255))
                premult.blit(rotated_surf, (0, 0))
                surface.blit(premult, (draw_x, draw_y), special_flags=pygame.BLEND_RGB_ADD)
            else:
                if alpha < 0.99:
                    rotated_surf = rotated_surf.copy()
                    rotated_surf.set_alpha(int(alpha * 255))
                surface.blit(rotated_surf, (draw_x, draw_y))

