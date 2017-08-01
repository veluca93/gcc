/* { dg-do compile } */
/* { dg-options "-O3" } */
/* { dg-skip-if "Tiny model won't generate adrp" { *-*-* } { "-mcmodel=tiny" } { "" } } */

double d0(void)
{
  double x = 0.0d;
  return x;
}

double dn1(void)
{
  double x = -0.0d;
  return x;
}


double d1(void)
{
  double x = 1.5d;
  return x;
}

double d2(void)
{
  double x = 123256.0d;
  return x;
}

double d3(void)
{
  double x = 123256123456.0d;
  return x;
}

double d4(void)
{
  double x = 123456123456123456.0d;
  return x;
}

/* { dg-final { scan-assembler-times "movi\td\[0-9\]+, #?0"                 1 } } */

/* { dg-final { scan-assembler-times "adrp\tx\[0-9\]+, \.LC\[0-9\]"         2 } } */
/* { dg-final { scan-assembler-times "ldr\td\[0-9\]+, \\\[x\[0-9\], #:lo12:\.LC\[0-9\]\\\]" 2 } } */

/* { dg-final { scan-assembler-times "fmov\td\[0-9\]+, 1\\\.5e\\\+0"        1 } } */

/* { dg-final { scan-assembler-times "mov\tx\[0-9\]+, 25838523252736"       1 { target aarch64-*-* } } } */
/* { dg-final { scan-assembler-times "movk\tx\[0-9\]+, 0x40fe, lsl 48"      1 { target aarch64-*-* } } } */
/* { dg-final { scan-assembler-times "mov\tx\[0-9\]+, -9223372036854775808" 1 { target aarch64-*-* } } } */
/* { dg-final { scan-assembler-times "mov\tx\[0-9\]+, 6016"                 1 { target aarch64_be-*-* } } } */
/* { dg-final { scan-assembler-times "movk\tx\[0-9\]+, 0x40fe, lsl 16"      1 { target aarch64_be-*-* } } } */
/* { dg-final { scan-assembler-times "mov\tx\[0-9\]+, 2147483648"           1 { target aarch64_be-*-* } } } */
/* { dg-final { scan-assembler-times "fmov\td\[0-9\]+, x\[0-9\]+"           2 } } */

