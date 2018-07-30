int sign(int x) { return (x >> 31) | (!(!x)); }
int bitAnd(int x, int y) { return ~((~x) | (~y)); }
int bitXor(int x, int y) { return ~(x & y) & ~(~x & ~y); }
int getByte(int x, int n) {
  // n << 3 -> Multiply by 8
  // x >> (n << 3) -> Right Shift by 0, 8, 16 and 24 bytes
  return (x >> (n << 3) & (0xFF));
}
int logicalShift(int x, int n) {
  /* Use mask to mask out the leading bits. */
  int mask = ~(((1 << 31) >> n) << 1);
  return (x >> n) & mask;
}
int bang(int x) {
  int tmp = (((~x + 1) | x) >> 31);
  // 0 for +ve or -ve, 1 otherwise
  return tmp + 1;
}
int isPower2(int x) {
  /*
   * If a positive number is power of 2, the leading bit should be
   * 0 and (x-1)&x == 0
   */
  int sign = !(x >> 31);
  return (!!x) & sign & !((x + ~1 + 1) & x);
  // return (x & (-x))==x; if == allowed
}
int conditional(int x, int y, int z) {
  // int a = ((((x >> 31) | ((~x + 1) >> 31)) << 31) >> 31);
  int a = (x >> 31) | ((~x + 1) >> 31);
  return ((a & y) + (~a & z));
}
