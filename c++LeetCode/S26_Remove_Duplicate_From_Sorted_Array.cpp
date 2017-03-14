#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int count = 1;
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] == nums[i - 1]) {
        continue;
      } else {
        nums[count] = nums[i];
        count++;
      }
    }
    for (auto i = nums.begin(); i != nums.end(); i++) {
      cout << *i << " ";
    }
    cout << endl;
    return count;
  }
};
int main() {
  vector<int> test = {1, 1, 2, 4, 6, 6, 10};
  Solution solution = Solution();
  cout << solution.removeDuplicates(test);
}
