/* SPDX-License-Identifier: MIT
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use, copy,
 * modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
 * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
 * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * RVV 0.9 / 1.0 compatibility shim
 *
 * RVV 1.0 (GCC 13+, Clang 16+) prefixes all intrinsics with __riscv_.
 * RVV 0.9 (T-Head GCC, older toolchains) uses un-prefixed names.
 * This header provides SIMDE_RVV_* macros that expand to the correct
 * intrinsic name for the detected version.
 *
 * Detection:
 *   - SIMDE_RISCV_V09_COMPAT is defined by simde-features.h when
 *     we detect a 0.9 toolchain (or the user forces it with
 *     -DSIMDE_RISCV_V09_FORCE).
 */

#if !defined(SIMDE_RISCV_V_COMPAT_H)
#define SIMDE_RISCV_V_COMPAT_H

/* ======================================================================
 * vsetvl family
 * ====================================================================== */

#if defined(SIMDE_RISCV_V09_COMPAT)
  #define SIMDE_RVV_VSETVL_E8M1(n)   vsetvl_e8m1(n)
  #define SIMDE_RVV_VSETVL_E16M1(n)  vsetvl_e16m1(n)
  #define SIMDE_RVV_VSETVL_E32M1(n)  vsetvl_e32m1(n)
  #define SIMDE_RVV_VSETVL_E64M1(n)  vsetvl_e64m1(n)
  #define SIMDE_RVV_VSETVL_E8M2(n)   vsetvl_e8m2(n)
  #define SIMDE_RVV_VSETVL_E16M2(n)  vsetvl_e16m2(n)
  #define SIMDE_RVV_VSETVL_E32M2(n)  vsetvl_e32m2(n)
#else
  #define SIMDE_RVV_VSETVL_E8M1(n)   __riscv_vsetvl_e8m1(n)
  #define SIMDE_RVV_VSETVL_E16M1(n)  __riscv_vsetvl_e16m1(n)
  #define SIMDE_RVV_VSETVL_E32M1(n)  __riscv_vsetvl_e32m1(n)
  #define SIMDE_RVV_VSETVL_E64M1(n)  __riscv_vsetvl_e64m1(n)
  #define SIMDE_RVV_VSETVL_E8M2(n)   __riscv_vsetvl_e8m2(n)
  #define SIMDE_RVV_VSETVL_E16M2(n)  __riscv_vsetvl_e16m2(n)
  #define SIMDE_RVV_VSETVL_E32M2(n)  __riscv_vsetvl_e32m2(n)
#endif

/* ======================================================================
 * Load (vle) — signed, unsigned, float
 * ====================================================================== */

#if defined(SIMDE_RISCV_V09_COMPAT)
  #define SIMDE_RVV_VLE8_I8M1(ptr, vl)     vle8_v_i8m1((ptr), (vl))
  #define SIMDE_RVV_VLE8_U8M1(ptr, vl)     vle8_v_u8m1((ptr), (vl))
  #define SIMDE_RVV_VLE16_I16M1(ptr, vl)   vle16_v_i16m1((ptr), (vl))
  #define SIMDE_RVV_VLE16_U16M1(ptr, vl)   vle16_v_u16m1((ptr), (vl))
  #define SIMDE_RVV_VLE32_I32M1(ptr, vl)   vle32_v_i32m1((ptr), (vl))
  #define SIMDE_RVV_VLE32_U32M1(ptr, vl)   vle32_v_u32m1((ptr), (vl))
  #define SIMDE_RVV_VLE32_F32M1(ptr, vl)   vle32_v_f32m1((ptr), (vl))
  #define SIMDE_RVV_VLE64_I64M1(ptr, vl)   vle64_v_i64m1((ptr), (vl))
  #define SIMDE_RVV_VLE64_U64M1(ptr, vl)   vle64_v_u64m1((ptr), (vl))
  #define SIMDE_RVV_VLE64_F64M1(ptr, vl)   vle64_v_f64m1((ptr), (vl))
#else
  #define SIMDE_RVV_VLE8_I8M1(ptr, vl)     __riscv_vle8_v_i8m1((ptr), (vl))
  #define SIMDE_RVV_VLE8_U8M1(ptr, vl)     __riscv_vle8_v_u8m1((ptr), (vl))
  #define SIMDE_RVV_VLE16_I16M1(ptr, vl)   __riscv_vle16_v_i16m1((ptr), (vl))
  #define SIMDE_RVV_VLE16_U16M1(ptr, vl)   __riscv_vle16_v_u16m1((ptr), (vl))
  #define SIMDE_RVV_VLE32_I32M1(ptr, vl)   __riscv_vle32_v_i32m1((ptr), (vl))
  #define SIMDE_RVV_VLE32_U32M1(ptr, vl)   __riscv_vle32_v_u32m1((ptr), (vl))
  #define SIMDE_RVV_VLE32_F32M1(ptr, vl)   __riscv_vle32_v_f32m1((ptr), (vl))
  #define SIMDE_RVV_VLE64_I64M1(ptr, vl)   __riscv_vle64_v_i64m1((ptr), (vl))
  #define SIMDE_RVV_VLE64_U64M1(ptr, vl)   __riscv_vle64_v_u64m1((ptr), (vl))
  #define SIMDE_RVV_VLE64_F64M1(ptr, vl)   __riscv_vle64_v_f64m1((ptr), (vl))
#endif

/* ======================================================================
 * Store (vse) — signed, unsigned, float
 * ====================================================================== */

#if defined(SIMDE_RISCV_V09_COMPAT)
  #define SIMDE_RVV_VSE8_I8M1(ptr, v, vl)     vse8_v_i8m1((ptr), (v), (vl))
  #define SIMDE_RVV_VSE8_U8M1(ptr, v, vl)     vse8_v_u8m1((ptr), (v), (vl))
  #define SIMDE_RVV_VSE16_I16M1(ptr, v, vl)   vse16_v_i16m1((ptr), (v), (vl))
  #define SIMDE_RVV_VSE16_U16M1(ptr, v, vl)   vse16_v_u16m1((ptr), (v), (vl))
  #define SIMDE_RVV_VSE32_I32M1(ptr, v, vl)   vse32_v_i32m1((ptr), (v), (vl))
  #define SIMDE_RVV_VSE32_U32M1(ptr, v, vl)   vse32_v_u32m1((ptr), (v), (vl))
  #define SIMDE_RVV_VSE32_F32M1(ptr, v, vl)   vse32_v_f32m1((ptr), (v), (vl))
  #define SIMDE_RVV_VSE64_I64M1(ptr, v, vl)   vse64_v_i64m1((ptr), (v), (vl))
  #define SIMDE_RVV_VSE64_U64M1(ptr, v, vl)   vse64_v_u64m1((ptr), (v), (vl))
  #define SIMDE_RVV_VSE64_F64M1(ptr, v, vl)   vse64_v_f64m1((ptr), (v), (vl))
#else
  #define SIMDE_RVV_VSE8_I8M1(ptr, v, vl)     __riscv_vse8_v_i8m1((ptr), (v), (vl))
  #define SIMDE_RVV_VSE8_U8M1(ptr, v, vl)     __riscv_vse8_v_u8m1((ptr), (v), (vl))
  #define SIMDE_RVV_VSE16_I16M1(ptr, v, vl)   __riscv_vse16_v_i16m1((ptr), (v), (vl))
  #define SIMDE_RVV_VSE16_U16M1(ptr, v, vl)   __riscv_vse16_v_u16m1((ptr), (v), (vl))
  #define SIMDE_RVV_VSE32_I32M1(ptr, v, vl)   __riscv_vse32_v_i32m1((ptr), (v), (vl))
  #define SIMDE_RVV_VSE32_U32M1(ptr, v, vl)   __riscv_vse32_v_u32m1((ptr), (v), (vl))
  #define SIMDE_RVV_VSE32_F32M1(ptr, v, vl)   __riscv_vse32_v_f32m1((ptr), (v), (vl))
  #define SIMDE_RVV_VSE64_I64M1(ptr, v, vl)   __riscv_vse64_v_i64m1((ptr), (v), (vl))
  #define SIMDE_RVV_VSE64_U64M1(ptr, v, vl)   __riscv_vse64_v_u64m1((ptr), (v), (vl))
  #define SIMDE_RVV_VSE64_F64M1(ptr, v, vl)   __riscv_vse64_v_f64m1((ptr), (v), (vl))
#endif

/* ======================================================================
 * M2 load/store (for widening operations)
 * ====================================================================== */

#if defined(SIMDE_RISCV_V09_COMPAT)
  #define SIMDE_RVV_VSE32_I32M2(ptr, v, vl)   vse32_v_i32m2((ptr), (v), (vl))
#else
  #define SIMDE_RVV_VSE32_I32M2(ptr, v, vl)   __riscv_vse32_v_i32m2((ptr), (v), (vl))
#endif

/* ======================================================================
 * Integer arithmetic: add, sub
 * ====================================================================== */

#if defined(SIMDE_RISCV_V09_COMPAT)
  #define SIMDE_RVV_VADD_VV_I8M1(a, b, vl)   vadd_vv_i8m1((a), (b), (vl))
  #define SIMDE_RVV_VADD_VV_I16M1(a, b, vl)  vadd_vv_i16m1((a), (b), (vl))
  #define SIMDE_RVV_VADD_VV_I32M1(a, b, vl)  vadd_vv_i32m1((a), (b), (vl))
  #define SIMDE_RVV_VADD_VV_I64M1(a, b, vl)  vadd_vv_i64m1((a), (b), (vl))
  #define SIMDE_RVV_VADD_VV_U8M1(a, b, vl)   vadd_vv_u8m1((a), (b), (vl))
  #define SIMDE_RVV_VADD_VV_U16M1(a, b, vl)  vadd_vv_u16m1((a), (b), (vl))
  #define SIMDE_RVV_VADD_VV_U32M1(a, b, vl)  vadd_vv_u32m1((a), (b), (vl))
  #define SIMDE_RVV_VADD_VV_U64M1(a, b, vl)  vadd_vv_u64m1((a), (b), (vl))
  #define SIMDE_RVV_VSUB_VV_I8M1(a, b, vl)   vsub_vv_i8m1((a), (b), (vl))
  #define SIMDE_RVV_VSUB_VV_I16M1(a, b, vl)  vsub_vv_i16m1((a), (b), (vl))
  #define SIMDE_RVV_VSUB_VV_I32M1(a, b, vl)  vsub_vv_i32m1((a), (b), (vl))
  #define SIMDE_RVV_VSUB_VV_I64M1(a, b, vl)  vsub_vv_i64m1((a), (b), (vl))
  #define SIMDE_RVV_VSUB_VV_U8M1(a, b, vl)   vsub_vv_u8m1((a), (b), (vl))
  #define SIMDE_RVV_VSUB_VV_U16M1(a, b, vl)  vsub_vv_u16m1((a), (b), (vl))
  #define SIMDE_RVV_VSUB_VV_U32M1(a, b, vl)  vsub_vv_u32m1((a), (b), (vl))
  #define SIMDE_RVV_VSUB_VV_U64M1(a, b, vl)  vsub_vv_u64m1((a), (b), (vl))
#else
  #define SIMDE_RVV_VADD_VV_I8M1(a, b, vl)   __riscv_vadd_vv_i8m1((a), (b), (vl))
  #define SIMDE_RVV_VADD_VV_I16M1(a, b, vl)  __riscv_vadd_vv_i16m1((a), (b), (vl))
  #define SIMDE_RVV_VADD_VV_I32M1(a, b, vl)  __riscv_vadd_vv_i32m1((a), (b), (vl))
  #define SIMDE_RVV_VADD_VV_I64M1(a, b, vl)  __riscv_vadd_vv_i64m1((a), (b), (vl))
  #define SIMDE_RVV_VADD_VV_U8M1(a, b, vl)   __riscv_vadd_vv_u8m1((a), (b), (vl))
  #define SIMDE_RVV_VADD_VV_U16M1(a, b, vl)  __riscv_vadd_vv_u16m1((a), (b), (vl))
  #define SIMDE_RVV_VADD_VV_U32M1(a, b, vl)  __riscv_vadd_vv_u32m1((a), (b), (vl))
  #define SIMDE_RVV_VADD_VV_U64M1(a, b, vl)  __riscv_vadd_vv_u64m1((a), (b), (vl))
  #define SIMDE_RVV_VSUB_VV_I8M1(a, b, vl)   __riscv_vsub_vv_i8m1((a), (b), (vl))
  #define SIMDE_RVV_VSUB_VV_I16M1(a, b, vl)  __riscv_vsub_vv_i16m1((a), (b), (vl))
  #define SIMDE_RVV_VSUB_VV_I32M1(a, b, vl)  __riscv_vsub_vv_i32m1((a), (b), (vl))
  #define SIMDE_RVV_VSUB_VV_I64M1(a, b, vl)  __riscv_vsub_vv_i64m1((a), (b), (vl))
  #define SIMDE_RVV_VSUB_VV_U8M1(a, b, vl)   __riscv_vsub_vv_u8m1((a), (b), (vl))
  #define SIMDE_RVV_VSUB_VV_U16M1(a, b, vl)  __riscv_vsub_vv_u16m1((a), (b), (vl))
  #define SIMDE_RVV_VSUB_VV_U32M1(a, b, vl)  __riscv_vsub_vv_u32m1((a), (b), (vl))
  #define SIMDE_RVV_VSUB_VV_U64M1(a, b, vl)  __riscv_vsub_vv_u64m1((a), (b), (vl))
#endif

/* ======================================================================
 * Float arithmetic: add, sub, mul, div, sqrt
 * ====================================================================== */

#if defined(SIMDE_RISCV_V09_COMPAT)
  #define SIMDE_RVV_VFADD_VV_F32M1(a, b, vl)  vfadd_vv_f32m1((a), (b), (vl))
  #define SIMDE_RVV_VFADD_VV_F64M1(a, b, vl)  vfadd_vv_f64m1((a), (b), (vl))
  #define SIMDE_RVV_VFSUB_VV_F32M1(a, b, vl)  vfsub_vv_f32m1((a), (b), (vl))
  #define SIMDE_RVV_VFSUB_VV_F64M1(a, b, vl)  vfsub_vv_f64m1((a), (b), (vl))
  #define SIMDE_RVV_VFMUL_VV_F32M1(a, b, vl)  vfmul_vv_f32m1((a), (b), (vl))
  #define SIMDE_RVV_VFMUL_VV_F64M1(a, b, vl)  vfmul_vv_f64m1((a), (b), (vl))
  #define SIMDE_RVV_VFDIV_VV_F32M1(a, b, vl)  vfdiv_vv_f32m1((a), (b), (vl))
  #define SIMDE_RVV_VFDIV_VV_F64M1(a, b, vl)  vfdiv_vv_f64m1((a), (b), (vl))
  #define SIMDE_RVV_VFSQRT_V_F32M1(a, vl)     vfsqrt_v_f32m1((a), (vl))
  #define SIMDE_RVV_VFSQRT_V_F64M1(a, vl)     vfsqrt_v_f64m1((a), (vl))
#else
  #define SIMDE_RVV_VFADD_VV_F32M1(a, b, vl)  __riscv_vfadd_vv_f32m1((a), (b), (vl))
  #define SIMDE_RVV_VFADD_VV_F64M1(a, b, vl)  __riscv_vfadd_vv_f64m1((a), (b), (vl))
  #define SIMDE_RVV_VFSUB_VV_F32M1(a, b, vl)  __riscv_vfsub_vv_f32m1((a), (b), (vl))
  #define SIMDE_RVV_VFSUB_VV_F64M1(a, b, vl)  __riscv_vfsub_vv_f64m1((a), (b), (vl))
  #define SIMDE_RVV_VFMUL_VV_F32M1(a, b, vl)  __riscv_vfmul_vv_f32m1((a), (b), (vl))
  #define SIMDE_RVV_VFMUL_VV_F64M1(a, b, vl)  __riscv_vfmul_vv_f64m1((a), (b), (vl))
  #define SIMDE_RVV_VFDIV_VV_F32M1(a, b, vl)  __riscv_vfdiv_vv_f32m1((a), (b), (vl))
  #define SIMDE_RVV_VFDIV_VV_F64M1(a, b, vl)  __riscv_vfdiv_vv_f64m1((a), (b), (vl))
  #define SIMDE_RVV_VFSQRT_V_F32M1(a, vl)     __riscv_vfsqrt_v_f32m1((a), (vl))
  #define SIMDE_RVV_VFSQRT_V_F64M1(a, vl)     __riscv_vfsqrt_v_f64m1((a), (vl))
#endif

/* ======================================================================
 * Saturating arithmetic
 * ====================================================================== */

#if defined(SIMDE_RISCV_V09_COMPAT)
  #define SIMDE_RVV_VSADD_VV_I8M1(a, b, vl)    vsadd_vv_i8m1((a), (b), (vl))
  #define SIMDE_RVV_VSADD_VV_I16M1(a, b, vl)   vsadd_vv_i16m1((a), (b), (vl))
  #define SIMDE_RVV_VSADDU_VV_U8M1(a, b, vl)   vsaddu_vv_u8m1((a), (b), (vl))
  #define SIMDE_RVV_VSADDU_VV_U16M1(a, b, vl)  vsaddu_vv_u16m1((a), (b), (vl))
  #define SIMDE_RVV_VSSUB_VV_I8M1(a, b, vl)    vssub_vv_i8m1((a), (b), (vl))
  #define SIMDE_RVV_VSSUB_VV_I16M1(a, b, vl)   vssub_vv_i16m1((a), (b), (vl))
  #define SIMDE_RVV_VSSUBU_VV_U8M1(a, b, vl)   vssubu_vv_u8m1((a), (b), (vl))
  #define SIMDE_RVV_VSSUBU_VV_U16M1(a, b, vl)  vssubu_vv_u16m1((a), (b), (vl))
#else
  #define SIMDE_RVV_VSADD_VV_I8M1(a, b, vl)    __riscv_vsadd_vv_i8m1((a), (b), (vl))
  #define SIMDE_RVV_VSADD_VV_I16M1(a, b, vl)   __riscv_vsadd_vv_i16m1((a), (b), (vl))
  #define SIMDE_RVV_VSADDU_VV_U8M1(a, b, vl)   __riscv_vsaddu_vv_u8m1((a), (b), (vl))
  #define SIMDE_RVV_VSADDU_VV_U16M1(a, b, vl)  __riscv_vsaddu_vv_u16m1((a), (b), (vl))
  #define SIMDE_RVV_VSSUB_VV_I8M1(a, b, vl)    __riscv_vssub_vv_i8m1((a), (b), (vl))
  #define SIMDE_RVV_VSSUB_VV_I16M1(a, b, vl)   __riscv_vssub_vv_i16m1((a), (b), (vl))
  #define SIMDE_RVV_VSSUBU_VV_U8M1(a, b, vl)   __riscv_vssubu_vv_u8m1((a), (b), (vl))
  #define SIMDE_RVV_VSSUBU_VV_U16M1(a, b, vl)  __riscv_vssubu_vv_u16m1((a), (b), (vl))
#endif

/* ======================================================================
 * Bitwise: and, or, xor, not
 * ====================================================================== */

#if defined(SIMDE_RISCV_V09_COMPAT)
  #define SIMDE_RVV_VAND_VV_I8M1(a, b, vl)   vand_vv_i8m1((a), (b), (vl))
  #define SIMDE_RVV_VAND_VV_U8M1(a, b, vl)   vand_vv_u8m1((a), (b), (vl))
  #define SIMDE_RVV_VAND_VV_U32M1(a, b, vl)  vand_vv_u32m1((a), (b), (vl))
  #define SIMDE_RVV_VAND_VV_U64M1(a, b, vl)  vand_vv_u64m1((a), (b), (vl))
  #define SIMDE_RVV_VOR_VV_U8M1(a, b, vl)    vor_vv_u8m1((a), (b), (vl))
  #define SIMDE_RVV_VOR_VV_U16M1(a, b, vl)   vor_vv_u16m1((a), (b), (vl))
  #define SIMDE_RVV_VOR_VV_U32M1(a, b, vl)   vor_vv_u32m1((a), (b), (vl))
  #define SIMDE_RVV_VOR_VV_U64M1(a, b, vl)   vor_vv_u64m1((a), (b), (vl))
  #define SIMDE_RVV_VXOR_VV_U8M1(a, b, vl)   vxor_vv_u8m1((a), (b), (vl))
  #define SIMDE_RVV_VXOR_VV_U16M1(a, b, vl)  vxor_vv_u16m1((a), (b), (vl))
  #define SIMDE_RVV_VXOR_VV_U32M1(a, b, vl)  vxor_vv_u32m1((a), (b), (vl))
  #define SIMDE_RVV_VXOR_VV_U64M1(a, b, vl)  vxor_vv_u64m1((a), (b), (vl))
  #define SIMDE_RVV_VNOT_V_U8M1(a, vl)       vnot_v_u8m1((a), (vl))
  #define SIMDE_RVV_VNOT_V_U32M1(a, vl)      vnot_v_u32m1((a), (vl))
  #define SIMDE_RVV_VNOT_V_U64M1(a, vl)      vnot_v_u64m1((a), (vl))
#else
  #define SIMDE_RVV_VAND_VV_I8M1(a, b, vl)   __riscv_vand_vv_i8m1((a), (b), (vl))
  #define SIMDE_RVV_VAND_VV_U8M1(a, b, vl)   __riscv_vand_vv_u8m1((a), (b), (vl))
  #define SIMDE_RVV_VAND_VV_U32M1(a, b, vl)  __riscv_vand_vv_u32m1((a), (b), (vl))
  #define SIMDE_RVV_VAND_VV_U64M1(a, b, vl)  __riscv_vand_vv_u64m1((a), (b), (vl))
  #define SIMDE_RVV_VOR_VV_U8M1(a, b, vl)    __riscv_vor_vv_u8m1((a), (b), (vl))
  #define SIMDE_RVV_VOR_VV_U16M1(a, b, vl)   __riscv_vor_vv_u16m1((a), (b), (vl))
  #define SIMDE_RVV_VOR_VV_U32M1(a, b, vl)   __riscv_vor_vv_u32m1((a), (b), (vl))
  #define SIMDE_RVV_VOR_VV_U64M1(a, b, vl)   __riscv_vor_vv_u64m1((a), (b), (vl))
  #define SIMDE_RVV_VXOR_VV_U8M1(a, b, vl)   __riscv_vxor_vv_u8m1((a), (b), (vl))
  #define SIMDE_RVV_VXOR_VV_U16M1(a, b, vl)  __riscv_vxor_vv_u16m1((a), (b), (vl))
  #define SIMDE_RVV_VXOR_VV_U32M1(a, b, vl)  __riscv_vxor_vv_u32m1((a), (b), (vl))
  #define SIMDE_RVV_VXOR_VV_U64M1(a, b, vl)  __riscv_vxor_vv_u64m1((a), (b), (vl))
  #define SIMDE_RVV_VNOT_V_U8M1(a, vl)       __riscv_vnot_v_u8m1((a), (vl))
  #define SIMDE_RVV_VNOT_V_U32M1(a, vl)      __riscv_vnot_v_u32m1((a), (vl))
  #define SIMDE_RVV_VNOT_V_U64M1(a, vl)      __riscv_vnot_v_u64m1((a), (vl))
#endif

/* ======================================================================
 * Comparisons (return vboolN_t mask)
 * ====================================================================== */

#if defined(SIMDE_RISCV_V09_COMPAT)
  #define SIMDE_RVV_VMSEQ_VV_I8M1(a, b, vl)    vmseq_vv_i8m1_b8((a), (b), (vl))
  #define SIMDE_RVV_VMSEQ_VV_I16M1(a, b, vl)   vmseq_vv_i16m1_b16((a), (b), (vl))
  #define SIMDE_RVV_VMSEQ_VV_I32M1(a, b, vl)   vmseq_vv_i32m1_b32((a), (b), (vl))
  #define SIMDE_RVV_VMSEQ_VV_I64M1(a, b, vl)   vmseq_vv_i64m1_b64((a), (b), (vl))
  #define SIMDE_RVV_VMSGT_VV_I8M1(a, b, vl)    vmsgt_vv_i8m1_b8((a), (b), (vl))
  #define SIMDE_RVV_VMSGT_VV_I16M1(a, b, vl)   vmsgt_vv_i16m1_b16((a), (b), (vl))
  #define SIMDE_RVV_VMSGT_VV_I32M1(a, b, vl)   vmsgt_vv_i32m1_b32((a), (b), (vl))
  #define SIMDE_RVV_VMSGT_VV_I64M1(a, b, vl)   vmsgt_vv_i64m1_b64((a), (b), (vl))
  #define SIMDE_RVV_VMSLT_VV_I8M1(a, b, vl)    vmslt_vv_i8m1_b8((a), (b), (vl))
  #define SIMDE_RVV_VMSLT_VV_I16M1(a, b, vl)   vmslt_vv_i16m1_b16((a), (b), (vl))
  #define SIMDE_RVV_VMSLT_VV_I32M1(a, b, vl)   vmslt_vv_i32m1_b32((a), (b), (vl))
  #define SIMDE_RVV_VMSLT_VX_I8M1(a, s, vl)    vmslt_vx_i8m1_b8((a), (s), (vl))
  #define SIMDE_RVV_VMSLT_VX_I32M1(a, s, vl)   vmslt_vx_i32m1_b32((a), (s), (vl))
  #define SIMDE_RVV_VMSLT_VX_I64M1(a, s, vl)   vmslt_vx_i64m1_b64((a), (s), (vl))
  #define SIMDE_RVV_VMSLTU_VV_U8M1(a, b, vl)   vmsltu_vv_u8m1_b8((a), (b), (vl))
  #define SIMDE_RVV_VMFEQ_VV_F32M1(a, b, vl)   vmfeq_vv_f32m1_b32((a), (b), (vl))
  #define SIMDE_RVV_VMFEQ_VV_F64M1(a, b, vl)   vmfeq_vv_f64m1_b64((a), (b), (vl))
  #define SIMDE_RVV_VMFLT_VV_F32M1(a, b, vl)   vmflt_vv_f32m1_b32((a), (b), (vl))
  #define SIMDE_RVV_VMFLT_VV_F64M1(a, b, vl)   vmflt_vv_f64m1_b64((a), (b), (vl))
  #define SIMDE_RVV_VMFLE_VV_F32M1(a, b, vl)   vmfle_vv_f32m1_b32((a), (b), (vl))
  #define SIMDE_RVV_VMFLE_VV_F64M1(a, b, vl)   vmfle_vv_f64m1_b64((a), (b), (vl))
  #define SIMDE_RVV_VMFGT_VV_F64M1(a, b, vl)   vmfgt_vv_f64m1_b64((a), (b), (vl))
  #define SIMDE_RVV_VMFGE_VV_F64M1(a, b, vl)   vmfge_vv_f64m1_b64((a), (b), (vl))
#else
  #define SIMDE_RVV_VMSEQ_VV_I8M1(a, b, vl)    __riscv_vmseq_vv_i8m1_b8((a), (b), (vl))
  #define SIMDE_RVV_VMSEQ_VV_I16M1(a, b, vl)   __riscv_vmseq_vv_i16m1_b16((a), (b), (vl))
  #define SIMDE_RVV_VMSEQ_VV_I32M1(a, b, vl)   __riscv_vmseq_vv_i32m1_b32((a), (b), (vl))
  #define SIMDE_RVV_VMSEQ_VV_I64M1(a, b, vl)   __riscv_vmseq_vv_i64m1_b64((a), (b), (vl))
  #define SIMDE_RVV_VMSGT_VV_I8M1(a, b, vl)    __riscv_vmsgt_vv_i8m1_b8((a), (b), (vl))
  #define SIMDE_RVV_VMSGT_VV_I16M1(a, b, vl)   __riscv_vmsgt_vv_i16m1_b16((a), (b), (vl))
  #define SIMDE_RVV_VMSGT_VV_I32M1(a, b, vl)   __riscv_vmsgt_vv_i32m1_b32((a), (b), (vl))
  #define SIMDE_RVV_VMSGT_VV_I64M1(a, b, vl)   __riscv_vmsgt_vv_i64m1_b64((a), (b), (vl))
  #define SIMDE_RVV_VMSLT_VV_I8M1(a, b, vl)    __riscv_vmslt_vv_i8m1_b8((a), (b), (vl))
  #define SIMDE_RVV_VMSLT_VV_I16M1(a, b, vl)   __riscv_vmslt_vv_i16m1_b16((a), (b), (vl))
  #define SIMDE_RVV_VMSLT_VV_I32M1(a, b, vl)   __riscv_vmslt_vv_i32m1_b32((a), (b), (vl))
  #define SIMDE_RVV_VMSLT_VX_I8M1(a, s, vl)    __riscv_vmslt_vx_i8m1_b8((a), (s), (vl))
  #define SIMDE_RVV_VMSLT_VX_I32M1(a, s, vl)   __riscv_vmslt_vx_i32m1_b32((a), (s), (vl))
  #define SIMDE_RVV_VMSLT_VX_I64M1(a, s, vl)   __riscv_vmslt_vx_i64m1_b64((a), (s), (vl))
  #define SIMDE_RVV_VMSLTU_VV_U8M1(a, b, vl)   __riscv_vmsltu_vv_u8m1_b8((a), (b), (vl))
  #define SIMDE_RVV_VMFEQ_VV_F32M1(a, b, vl)   __riscv_vmfeq_vv_f32m1_b32((a), (b), (vl))
  #define SIMDE_RVV_VMFEQ_VV_F64M1(a, b, vl)   __riscv_vmfeq_vv_f64m1_b64((a), (b), (vl))
  #define SIMDE_RVV_VMFLT_VV_F32M1(a, b, vl)   __riscv_vmflt_vv_f32m1_b32((a), (b), (vl))
  #define SIMDE_RVV_VMFLT_VV_F64M1(a, b, vl)   __riscv_vmflt_vv_f64m1_b64((a), (b), (vl))
  #define SIMDE_RVV_VMFLE_VV_F32M1(a, b, vl)   __riscv_vmfle_vv_f32m1_b32((a), (b), (vl))
  #define SIMDE_RVV_VMFLE_VV_F64M1(a, b, vl)   __riscv_vmfle_vv_f64m1_b64((a), (b), (vl))
  #define SIMDE_RVV_VMFGT_VV_F64M1(a, b, vl)   __riscv_vmfgt_vv_f64m1_b64((a), (b), (vl))
  #define SIMDE_RVV_VMFGE_VV_F64M1(a, b, vl)   __riscv_vmfge_vv_f64m1_b64((a), (b), (vl))
#endif

/* ======================================================================
 * Mask operations: and, not, store mask
 * ====================================================================== */

#if defined(SIMDE_RISCV_V09_COMPAT)
  #define SIMDE_RVV_VMAND_MM_B8(a, b, vl)    vmand_mm_b8((a), (b), (vl))
  #define SIMDE_RVV_VMAND_MM_B32(a, b, vl)   vmand_mm_b32((a), (b), (vl))
  #define SIMDE_RVV_VMAND_MM_B64(a, b, vl)   vmand_mm_b64((a), (b), (vl))
  #define SIMDE_RVV_VMNOT_M_B8(a, vl)        vmnot_m_b8((a), (vl))
  #define SIMDE_RVV_VMNOT_M_B32(a, vl)       vmnot_m_b32((a), (vl))
  #define SIMDE_RVV_VMNOT_M_B64(a, vl)       vmnot_m_b64((a), (vl))
  #define SIMDE_RVV_VSM_V_B8(ptr, mask, vl)  vsm_v_b8((ptr), (mask), (vl))
  #define SIMDE_RVV_VSM_V_B32(ptr, mask, vl) vsm_v_b32((ptr), (mask), (vl))
  #define SIMDE_RVV_VSM_V_B64(ptr, mask, vl) vsm_v_b64((ptr), (mask), (vl))
#else
  #define SIMDE_RVV_VMAND_MM_B8(a, b, vl)    __riscv_vmand_mm_b8((a), (b), (vl))
  #define SIMDE_RVV_VMAND_MM_B32(a, b, vl)   __riscv_vmand_mm_b32((a), (b), (vl))
  #define SIMDE_RVV_VMAND_MM_B64(a, b, vl)   __riscv_vmand_mm_b64((a), (b), (vl))
  #define SIMDE_RVV_VMNOT_M_B8(a, vl)        __riscv_vmnot_m_b8((a), (vl))
  #define SIMDE_RVV_VMNOT_M_B32(a, vl)       __riscv_vmnot_m_b32((a), (vl))
  #define SIMDE_RVV_VMNOT_M_B64(a, vl)       __riscv_vmnot_m_b64((a), (vl))
  #define SIMDE_RVV_VSM_V_B8(ptr, mask, vl)  __riscv_vsm_v_b8((ptr), (mask), (vl))
  #define SIMDE_RVV_VSM_V_B32(ptr, mask, vl) __riscv_vsm_v_b32((ptr), (mask), (vl))
  #define SIMDE_RVV_VSM_V_B64(ptr, mask, vl) __riscv_vsm_v_b64((ptr), (mask), (vl))
#endif

/* ======================================================================
 * Merge / broadcast
 * ====================================================================== */

#if defined(SIMDE_RISCV_V09_COMPAT)
  #define SIMDE_RVV_VMERGE_VXM_I8M1(mask, fv, ts, vl)   vmerge_vxm_i8m1((fv), (ts), (mask), (vl))
  #define SIMDE_RVV_VMERGE_VXM_I16M1(mask, fv, ts, vl)  vmerge_vxm_i16m1((fv), (ts), (mask), (vl))
  #define SIMDE_RVV_VMERGE_VXM_I32M1(mask, fv, ts, vl)  vmerge_vxm_i32m1((fv), (ts), (mask), (vl))
  #define SIMDE_RVV_VMERGE_VXM_I64M1(mask, fv, ts, vl)  vmerge_vxm_i64m1((fv), (ts), (mask), (vl))
  #define SIMDE_RVV_VMERGE_VXM_U32M1(mask, fv, ts, vl)  vmerge_vxm_u32m1((fv), (ts), (mask), (vl))
  #define SIMDE_RVV_VMERGE_VXM_U64M1(mask, fv, ts, vl)  vmerge_vxm_u64m1((fv), (ts), (mask), (vl))
  #define SIMDE_RVV_VMV_V_X_I8M1(s, vl)                 vmv_v_x_i8m1((s), (vl))
  #define SIMDE_RVV_VMV_V_X_I16M1(s, vl)                vmv_v_x_i16m1((s), (vl))
  #define SIMDE_RVV_VMV_V_X_I32M1(s, vl)                vmv_v_x_i32m1((s), (vl))
  #define SIMDE_RVV_VMV_V_X_I64M1(s, vl)                vmv_v_x_i64m1((s), (vl))
  #define SIMDE_RVV_VMV_V_X_U8M1(s, vl)                 vmv_v_x_u8m1((s), (vl))
  #define SIMDE_RVV_VMV_V_X_U32M1(s, vl)                vmv_v_x_u32m1((s), (vl))
  #define SIMDE_RVV_VMV_V_X_U64M1(s, vl)                vmv_v_x_u64m1((s), (vl))
#else
  #define SIMDE_RVV_VMERGE_VXM_I8M1(mask, fv, ts, vl)   __riscv_vmerge_vxm_i8m1((fv), (ts), (mask), (vl))
  #define SIMDE_RVV_VMERGE_VXM_I16M1(mask, fv, ts, vl)  __riscv_vmerge_vxm_i16m1((fv), (ts), (mask), (vl))
  #define SIMDE_RVV_VMERGE_VXM_I32M1(mask, fv, ts, vl)  __riscv_vmerge_vxm_i32m1((fv), (ts), (mask), (vl))
  #define SIMDE_RVV_VMERGE_VXM_I64M1(mask, fv, ts, vl)  __riscv_vmerge_vxm_i64m1((fv), (ts), (mask), (vl))
  #define SIMDE_RVV_VMERGE_VXM_U32M1(mask, fv, ts, vl)  __riscv_vmerge_vxm_u32m1((fv), (ts), (mask), (vl))
  #define SIMDE_RVV_VMERGE_VXM_U64M1(mask, fv, ts, vl)  __riscv_vmerge_vxm_u64m1((fv), (ts), (mask), (vl))
  #define SIMDE_RVV_VMV_V_X_I8M1(s, vl)                 __riscv_vmv_v_x_i8m1((s), (vl))
  #define SIMDE_RVV_VMV_V_X_I16M1(s, vl)                __riscv_vmv_v_x_i16m1((s), (vl))
  #define SIMDE_RVV_VMV_V_X_I32M1(s, vl)                __riscv_vmv_v_x_i32m1((s), (vl))
  #define SIMDE_RVV_VMV_V_X_I64M1(s, vl)                __riscv_vmv_v_x_i64m1((s), (vl))
  #define SIMDE_RVV_VMV_V_X_U8M1(s, vl)                 __riscv_vmv_v_x_u8m1((s), (vl))
  #define SIMDE_RVV_VMV_V_X_U32M1(s, vl)                __riscv_vmv_v_x_u32m1((s), (vl))
  #define SIMDE_RVV_VMV_V_X_U64M1(s, vl)                __riscv_vmv_v_x_u64m1((s), (vl))
#endif

/* ======================================================================
 * Shifts
 * ====================================================================== */

#if defined(SIMDE_RISCV_V09_COMPAT)
  #define SIMDE_RVV_VSLL_VX_U8M1(a, s, vl)    vsll_vx_u8m1((a), (s), (vl))
  #define SIMDE_RVV_VSLL_VX_U16M1(a, s, vl)   vsll_vx_u16m1((a), (s), (vl))
  #define SIMDE_RVV_VSLL_VX_U32M1(a, s, vl)   vsll_vx_u32m1((a), (s), (vl))
  #define SIMDE_RVV_VSLL_VX_U64M1(a, s, vl)   vsll_vx_u64m1((a), (s), (vl))
  #define SIMDE_RVV_VSRL_VX_U8M1(a, s, vl)    vsrl_vx_u8m1((a), (s), (vl))
  #define SIMDE_RVV_VSRL_VX_U16M1(a, s, vl)   vsrl_vx_u16m1((a), (s), (vl))
  #define SIMDE_RVV_VSRL_VX_U32M1(a, s, vl)   vsrl_vx_u32m1((a), (s), (vl))
  #define SIMDE_RVV_VSRL_VX_U64M1(a, s, vl)   vsrl_vx_u64m1((a), (s), (vl))
  #define SIMDE_RVV_VSRA_VX_I8M1(a, s, vl)    vsra_vx_i8m1((a), (s), (vl))
  #define SIMDE_RVV_VSRA_VX_I16M1(a, s, vl)   vsra_vx_i16m1((a), (s), (vl))
  #define SIMDE_RVV_VSRA_VX_I32M1(a, s, vl)   vsra_vx_i32m1((a), (s), (vl))
#else
  #define SIMDE_RVV_VSLL_VX_U8M1(a, s, vl)    __riscv_vsll_vx_u8m1((a), (s), (vl))
  #define SIMDE_RVV_VSLL_VX_U16M1(a, s, vl)   __riscv_vsll_vx_u16m1((a), (s), (vl))
  #define SIMDE_RVV_VSLL_VX_U32M1(a, s, vl)   __riscv_vsll_vx_u32m1((a), (s), (vl))
  #define SIMDE_RVV_VSLL_VX_U64M1(a, s, vl)   __riscv_vsll_vx_u64m1((a), (s), (vl))
  #define SIMDE_RVV_VSRL_VX_U8M1(a, s, vl)    __riscv_vsrl_vx_u8m1((a), (s), (vl))
  #define SIMDE_RVV_VSRL_VX_U16M1(a, s, vl)   __riscv_vsrl_vx_u16m1((a), (s), (vl))
  #define SIMDE_RVV_VSRL_VX_U32M1(a, s, vl)   __riscv_vsrl_vx_u32m1((a), (s), (vl))
  #define SIMDE_RVV_VSRL_VX_U64M1(a, s, vl)   __riscv_vsrl_vx_u64m1((a), (s), (vl))
  #define SIMDE_RVV_VSRA_VX_I8M1(a, s, vl)    __riscv_vsra_vx_i8m1((a), (s), (vl))
  #define SIMDE_RVV_VSRA_VX_I16M1(a, s, vl)   __riscv_vsra_vx_i16m1((a), (s), (vl))
  #define SIMDE_RVV_VSRA_VX_I32M1(a, s, vl)   __riscv_vsra_vx_i32m1((a), (s), (vl))
#endif

/* ======================================================================
 * Min / Max
 * ====================================================================== */

#if defined(SIMDE_RISCV_V09_COMPAT)
  #define SIMDE_RVV_VMIN_VV_I8M1(a, b, vl)    vmin_vv_i8m1((a), (b), (vl))
  #define SIMDE_RVV_VMIN_VV_I16M1(a, b, vl)   vmin_vv_i16m1((a), (b), (vl))
  #define SIMDE_RVV_VMAX_VV_I8M1(a, b, vl)    vmax_vv_i8m1((a), (b), (vl))
  #define SIMDE_RVV_VMAX_VV_I16M1(a, b, vl)   vmax_vv_i16m1((a), (b), (vl))
  #define SIMDE_RVV_VMINU_VV_U8M1(a, b, vl)   vminu_vv_u8m1((a), (b), (vl))
  #define SIMDE_RVV_VMAXU_VV_U8M1(a, b, vl)   vmaxu_vv_u8m1((a), (b), (vl))
  #define SIMDE_RVV_VMIN_VV_I32M1(a, b, vl)   vmin_vv_i32m1((a), (b), (vl))
  #define SIMDE_RVV_VMAX_VV_I32M1(a, b, vl)   vmax_vv_i32m1((a), (b), (vl))
  #define SIMDE_RVV_VMINU_VV_U16M1(a, b, vl)  vminu_vv_u16m1((a), (b), (vl))
  #define SIMDE_RVV_VMAXU_VV_U16M1(a, b, vl)  vmaxu_vv_u16m1((a), (b), (vl))
  #define SIMDE_RVV_VMINU_VV_U32M1(a, b, vl)  vminu_vv_u32m1((a), (b), (vl))
  #define SIMDE_RVV_VMAXU_VV_U32M1(a, b, vl)  vmaxu_vv_u32m1((a), (b), (vl))
  #define SIMDE_RVV_VFMIN_VV_F32M1(a, b, vl)  vfmin_vv_f32m1((a), (b), (vl))
  #define SIMDE_RVV_VFMIN_VV_F64M1(a, b, vl)  vfmin_vv_f64m1((a), (b), (vl))
  #define SIMDE_RVV_VFMAX_VV_F32M1(a, b, vl)  vfmax_vv_f32m1((a), (b), (vl))
  #define SIMDE_RVV_VFMAX_VV_F64M1(a, b, vl)  vfmax_vv_f64m1((a), (b), (vl))
#else
  #define SIMDE_RVV_VMIN_VV_I8M1(a, b, vl)    __riscv_vmin_vv_i8m1((a), (b), (vl))
  #define SIMDE_RVV_VMIN_VV_I16M1(a, b, vl)   __riscv_vmin_vv_i16m1((a), (b), (vl))
  #define SIMDE_RVV_VMAX_VV_I8M1(a, b, vl)    __riscv_vmax_vv_i8m1((a), (b), (vl))
  #define SIMDE_RVV_VMAX_VV_I16M1(a, b, vl)   __riscv_vmax_vv_i16m1((a), (b), (vl))
  #define SIMDE_RVV_VMINU_VV_U8M1(a, b, vl)   __riscv_vminu_vv_u8m1((a), (b), (vl))
  #define SIMDE_RVV_VMAXU_VV_U8M1(a, b, vl)   __riscv_vmaxu_vv_u8m1((a), (b), (vl))
  #define SIMDE_RVV_VMIN_VV_I32M1(a, b, vl)   __riscv_vmin_vv_i32m1((a), (b), (vl))
  #define SIMDE_RVV_VMAX_VV_I32M1(a, b, vl)   __riscv_vmax_vv_i32m1((a), (b), (vl))
  #define SIMDE_RVV_VMINU_VV_U16M1(a, b, vl)  __riscv_vminu_vv_u16m1((a), (b), (vl))
  #define SIMDE_RVV_VMAXU_VV_U16M1(a, b, vl)  __riscv_vmaxu_vv_u16m1((a), (b), (vl))
  #define SIMDE_RVV_VMINU_VV_U32M1(a, b, vl)  __riscv_vminu_vv_u32m1((a), (b), (vl))
  #define SIMDE_RVV_VMAXU_VV_U32M1(a, b, vl)  __riscv_vmaxu_vv_u32m1((a), (b), (vl))
  #define SIMDE_RVV_VFMIN_VV_F32M1(a, b, vl)  __riscv_vfmin_vv_f32m1((a), (b), (vl))
  #define SIMDE_RVV_VFMIN_VV_F64M1(a, b, vl)  __riscv_vfmin_vv_f64m1((a), (b), (vl))
  #define SIMDE_RVV_VFMAX_VV_F32M1(a, b, vl)  __riscv_vfmax_vv_f32m1((a), (b), (vl))
  #define SIMDE_RVV_VFMAX_VV_F64M1(a, b, vl)  __riscv_vfmax_vv_f64m1((a), (b), (vl))
#endif

/* ======================================================================
 * Permutation: vrgather, vslidedown, vslideup
 * ====================================================================== */

#if defined(SIMDE_RISCV_V09_COMPAT)
  #define SIMDE_RVV_VRGATHER_VV_I8M1(src, idx, vl)    vrgather_vv_i8m1((src), (idx), (vl))
  #define SIMDE_RVV_VRGATHER_VV_U8M1(src, idx, vl)    vrgather_vv_u8m1((src), (idx), (vl))
  #define SIMDE_RVV_VRGATHER_VV_I16M1(src, idx, vl)   vrgather_vv_i16m1((src), (idx), (vl))
  #define SIMDE_RVV_VRGATHER_VV_I32M1(src, idx, vl)   vrgather_vv_i32m1((src), (idx), (vl))
  #define SIMDE_RVV_VRGATHER_VV_I64M1(src, idx, vl)   vrgather_vv_i64m1((src), (idx), (vl))
  #define SIMDE_RVV_VSLIDEDOWN_VX_I8M1(src, off, vl)  vslidedown_vx_i8m1((src), (off), (vl))
  #define SIMDE_RVV_VSLIDEUP_VX_I8M1(dst, src, off, vl) vslideup_vx_i8m1((dst), (src), (off), (vl))
#else
  #define SIMDE_RVV_VRGATHER_VV_I8M1(src, idx, vl)    __riscv_vrgather_vv_i8m1((src), (idx), (vl))
  #define SIMDE_RVV_VRGATHER_VV_U8M1(src, idx, vl)    __riscv_vrgather_vv_u8m1((src), (idx), (vl))
  #define SIMDE_RVV_VRGATHER_VV_I16M1(src, idx, vl)   __riscv_vrgather_vv_i16m1((src), (idx), (vl))
  #define SIMDE_RVV_VRGATHER_VV_I32M1(src, idx, vl)   __riscv_vrgather_vv_i32m1((src), (idx), (vl))
  #define SIMDE_RVV_VRGATHER_VV_I64M1(src, idx, vl)   __riscv_vrgather_vv_i64m1((src), (idx), (vl))
  #define SIMDE_RVV_VSLIDEDOWN_VX_I8M1(src, off, vl)  __riscv_vslidedown_vx_i8m1((src), (off), (vl))
  #define SIMDE_RVV_VSLIDEUP_VX_I8M1(dst, src, off, vl) __riscv_vslideup_vx_i8m1((dst), (src), (off), (vl))
#endif

/* ======================================================================
 * Widening / Narrowing
 * ====================================================================== */

#if defined(SIMDE_RISCV_V09_COMPAT)
  #define SIMDE_RVV_VWADD_VV_I16M2(a, b, vl)      vwadd_vv_i16m2((a), (b), (vl))
  #define SIMDE_RVV_VWMUL_VV_I32M2(a, b, vl)      vwmul_vv_i32m2((a), (b), (vl))
  #define SIMDE_RVV_VWMULU_VV_U64M2(a, b, vl)     vwmulu_vv_u64m2((a), (b), (vl))
  #define SIMDE_RVV_VNSRA_WX_I16M1(w, s, vl)      vnsra_wx_i16m1((w), (s), (vl))
  #define SIMDE_RVV_VNCLIP_WX_I8M1(w, s, vl)      vnclip_wx_i8m1((w), (s), (vl))
  #define SIMDE_RVV_VNCLIPU_WX_U8M1(w, s, vl)     vnclipu_wx_u8m1((w), (s), (vl))
  #define SIMDE_RVV_VNCLIP_WX_I16M1(w, s, vl)     vnclip_wx_i16m1((w), (s), (vl))
  #define SIMDE_RVV_VMUL_VV_I16M1(a, b, vl)       vmul_vv_i16m1((a), (b), (vl))
  #define SIMDE_RVV_VMUL_VV_I32M1(a, b, vl)       vmul_vv_i32m1((a), (b), (vl))
  #define SIMDE_RVV_VWMULU_VV_U32M2(a, b, vl)     vwmulu_vv_u32m2((a), (b), (vl))
  #define SIMDE_RVV_VNSRL_WX_U16M1(w, s, vl)      vnsrl_wx_u16m1((w), (s), (vl))
#else
  #define SIMDE_RVV_VWADD_VV_I16M2(a, b, vl)      __riscv_vwadd_vv_i16m2((a), (b), (vl))
  #define SIMDE_RVV_VWMUL_VV_I32M2(a, b, vl)      __riscv_vwmul_vv_i32m2((a), (b), (vl))
  #define SIMDE_RVV_VWMULU_VV_U64M2(a, b, vl)     __riscv_vwmulu_vv_u64m2((a), (b), (vl))
  #define SIMDE_RVV_VNSRA_WX_I16M1(w, s, vl)      __riscv_vnsra_wx_i16m1((w), (s), (vl))
  #define SIMDE_RVV_VNCLIP_WX_I8M1(w, s, vl)      __riscv_vnclip_wx_i8m1((w), (s), (vl))
  #define SIMDE_RVV_VNCLIPU_WX_U8M1(w, s, vl)     __riscv_vnclipu_wx_u8m1((w), (s), (vl))
  #define SIMDE_RVV_VNCLIP_WX_I16M1(w, s, vl)     __riscv_vnclip_wx_i16m1((w), (s), (vl))
  #define SIMDE_RVV_VMUL_VV_I16M1(a, b, vl)       __riscv_vmul_vv_i16m1((a), (b), (vl))
  #define SIMDE_RVV_VMUL_VV_I32M1(a, b, vl)       __riscv_vmul_vv_i32m1((a), (b), (vl))
  #define SIMDE_RVV_VWMULU_VV_U32M2(a, b, vl)     __riscv_vwmulu_vv_u32m2((a), (b), (vl))
  #define SIMDE_RVV_VNSRL_WX_U16M1(w, s, vl)      __riscv_vnsrl_wx_u16m1((w), (s), (vl))
#endif

/* ======================================================================
 * Reinterpret casts
 * ====================================================================== */

#if defined(SIMDE_RISCV_V09_COMPAT)
  #define SIMDE_RVV_VREINTERPRET_U8M1_I8M1(v)   vreinterpret_v_i8m1_u8m1(v)
  #define SIMDE_RVV_VREINTERPRET_I8M1_U8M1(v)   vreinterpret_v_u8m1_i8m1(v)
  #define SIMDE_RVV_VREINTERPRET_U32M1_I32M1(v)  vreinterpret_v_i32m1_u32m1(v)
  #define SIMDE_RVV_VREINTERPRET_I32M1_U32M1(v)  vreinterpret_v_u32m1_i32m1(v)
  #define SIMDE_RVV_VREINTERPRET_U64M1_I64M1(v)  vreinterpret_v_i64m1_u64m1(v)
#else
  #define SIMDE_RVV_VREINTERPRET_U8M1_I8M1(v)   __riscv_vreinterpret_v_i8m1_u8m1(v)
  #define SIMDE_RVV_VREINTERPRET_I8M1_U8M1(v)   __riscv_vreinterpret_v_u8m1_i8m1(v)
  #define SIMDE_RVV_VREINTERPRET_U32M1_I32M1(v)  __riscv_vreinterpret_v_i32m1_u32m1(v)
  #define SIMDE_RVV_VREINTERPRET_I32M1_U32M1(v)  __riscv_vreinterpret_v_u32m1_i32m1(v)
  #define SIMDE_RVV_VREINTERPRET_U64M1_I64M1(v)  __riscv_vreinterpret_v_i64m1_u64m1(v)
#endif

#endif /* SIMDE_RISCV_V_COMPAT_H */
