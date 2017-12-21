class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret = {};
    if (nums.size() < 4) {
      return ret;
    }
    for (auto i = nums.begin(); i != nums.end() - 3; i++) {
      if (i != nums.begin() && *i == *(i - 1)) {
        continue;
      }
      for (auto j = i + 1; j != nums.end() - 2; j++) {
        if (j != i + 1 && *j == *(j - 1)) {
          continue;
        }
        auto left = j + 1;
        auto right = nums.end() - 1;
        // cout<<*left<<" "<<*right<<endl;

        while (left < right) {
          // cout<<"i:"<<*i<<"    j:"<<*j<<"    left:"<<*left<<"
          // right:"<<*right<<endl;
          int sum = *i + *j + *left + *right;
          if (sum == target) {
            vector<int> tmp;
            tmp.push_back(*i);
            tmp.push_back(*j);
            tmp.push_back(*left);
            tmp.push_back(*right);
            ret.push_back(tmp);
            left++;
            right--;
            while (left < right && *left == *(left - 1)) {
              left++;
            }
            while (left < right && *right == *(right + 1)) {
              right--;
            }
          } else if (sum > target) {
            right--;
          } else {
            left++;
          }
        }
      }
    }
    return ret;
  }
};
