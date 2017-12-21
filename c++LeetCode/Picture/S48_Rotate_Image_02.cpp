#include <iostream>
using namespace std;
class Solution {
public:
  double myPow(double x, int n) {
    if (n < 0) {
      return 1 / Pow(x, -n);
    } else {
      return Pow(x, n);
    }
  }

private:
  double Pow(double x, int n) {
    if (n == 0) {
      return 1;
    }
    if (n == 1) {
      return x;
    }
    double val = Pow(x, n / 2);
    if (n % 2 == 0) {
      return val * val;
    } else {
      return val * val * x;
    }
  }
};

int main() {
  Solution solution = Solution();
  cout << solution.Pow(5, 3);
}
