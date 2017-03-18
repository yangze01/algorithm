class Solution {
public:
  int divide(int dividend, int divisor) {
    if (!divisor || (dividend == INT_MIN && divisor == -1)) {
      return INT_MAX;
    }
    long long a = labs(dividend);
    long long b = labs(divisor);
    int res = 0;
    while (a >= b) {
      long long inb = b, multiple = 1;
      while (a > (inb << 1)) {
        inb <<= 1;
        multiple <<= 1;
      }
      a -= inb;
      res += multiple;
    }
    return (divisor < 0) ^ (dividend < 0) ? -res : res;
  }
};
