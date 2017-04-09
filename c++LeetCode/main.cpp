#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
  vector<vector<int>> combinationSum2(vector<int> &candidates, int target){
    sort(candidates.begin(), candidates.end());
    vector<int> candidate_vector;
    len = candidates.size();
    tmpcandidate = candidates;
    dfs(candidate_vector, target, 0);
    return result;
  }
private:
  int len;
  vector<int> tmpcandidate;
  vector<vector<int>> result;

  void dfs(vector<int> &com, int reminder, int index){
    if(index >= len){
      return;
    }
    if(reminder == 0){
      result.push_back(com);
    }
    else{
      int pre = -1;
      for(int i = index; i < len; i++){
        if(pre == tmpcandidate[i]){
          continue;
        }
        if(reminder < tmpcandidate[i]){
          return;
        }
        pre = tmpcandidate[i];
        com.push_back(tmpcandidate[i]);
        dfs(com, reminder - tmpcandidate[i], i + 1);
        com.pop_back();
      }
    }
  }
};

int main(){
  Solution solution = Solution();
  vector<int> candidates = {1};
  int tar = 1;
  vector<vector<int>> ttt = solution.combinationSum2(candidates, tar);
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
