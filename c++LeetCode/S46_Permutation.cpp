class Solution {
public:
  vector<vector<int>> permute(vector<int> &nums) {
    vector<int> candidate_vector;
    vector<bool> used(nums.size(), false);
    dfs(nums, used, candidate_vector);
    return result;
  }

private:
  vector<vector<int>> result;
  void dfs(vector<int> &nums, vector<bool> used, vector<int> candidate_vector) {
    if (candidate_vector.size() == nums.size()) {
      result.push_back(candidate_vector);
    } else {
      for (int i = 0; i < nums.size(); i++) {
        if (used[i] != true) {
          candidate_vector.push_back(nums[i]);
          used[i] = true;
          dfs(nums, used, candidate_vector);
          candidate_vector.pop_back();
          used[i] = false;
        }
      }
    }
  }
};

int main() {
  Solution solution = Solution();
  vector<int> nums = {1, 2, 3};
  vector<vector<int>> ttt = solution.permute(nums);
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
