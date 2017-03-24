#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> res = {-1, -1};
    int l = 0;
    int r = nums.size() - 1;
    int m;

    while (l < r - 1) {
      m = (l + r) / 2;
      if (target > nums[m]) {
        l = m;
      } else {
        r = m;
      }
    }
    if (nums[l] == target) {
      res[0] = l;
    } else if (nums[r] == target) {
      res[0] = r;
    } else {
      return res;
    }
    l = 0;
    r = nums.size() - 1;
    while (l < r - 1) {
      m = (l + r) / 2;
      if (target < nums[m]) {
        r = m;
      } else {
        l = m;
      }
    }
    if (nums[r] == target) {
      res[1] = r;
    } else if (nums[l] == target) {
      res[1] = l;
    } else {
      return res;
    }
    return res;
  }
};
int main() {
  int target = 3;
  vector<int> nums = {1, 2, 3, 3, 3, 4, 5, 6, 7, 8};
  Solution solution = Solution();
  vector<int> res = solution.searchRange(nums, target);

  for (auto i = res.begin(); i != res.end(); i++) {
    cout << *i << endl;
  }
}
