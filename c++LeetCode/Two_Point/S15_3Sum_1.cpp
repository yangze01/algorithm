#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res = {};
    if (nums.size() < 3) {
      return res;
    }
    for (int i = 0; i < nums.size() - 2; i++) {
      if (i && nums[i] == nums[i - 1]) {
        continue;
      }
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
        if (nums[i] + nums[left] + nums[right] == 0) {
          vector<int> tmp;
          tmp.push_back(nums[i]);
          tmp.push_back(nums[left]);
          tmp.push_back(nums[right]);
          res.push_back(tmp);
          left++;
          right--;
          while (left < right && nums[left] == nums[left - 1]) {
            left++;
          }
          while (left < right && nums[right] == nums[right + 1]) {
            right--;
          }
        } else if (nums[i] + nums[left] + nums[right] > 0) {
          right--;
        } else {
          left++;
        }
      }
    }
    return res;
  }
};

int main() {
  vector<int> test = {-1, 0, 1};
  Solution solution = Solution();
  vector<vector<int>> ttt = solution.threeSum(test);
  cout << "[";
  for (auto i = ttt.begin(); i != ttt.end(); i++) {
    cout << "[";
    vector<int> j = *i;
    for (auto k = j.begin(); k != j.end(); k++) {
      if (k == j.end() - 1) {
        cout << *k;
      } else {
        cout << *k << ",";
      }
    }
    if (i == ttt.end() - 1) {
      cout << "]";
    } else {
      cout << "],";
    }
  }
  cout << "]";
}
