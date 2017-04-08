#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());
      len = candidates.size();
      vector<int> combination_vector;
      tmpcondidates = candidates;
      dfs(combination_vector, target, 0);
      return result;
    }
private:
    int len;
    vector<int> tmpcondidates;
    vector<vector<int>> result;

    void dfs(vector<int>& com, int reminder, int index){
        if(index >= len){
          return;
        }
        if(reminder == 0){
          result.push_back(com);
          return;
        }
        else{
          for(int i = index;i < len; i ++){
            if(reminder < tmpcondidates[i]){
              return;
            }
            com.push_back(tmpcondidates[i]);
            dfs(com, reminder - tmpcondidates[i], i);
            com.pop_back();
          }
        }
    }
};


int main(){
  Solution solution = new Solution()
  vector<int> candidates = {2, 3, 6, 7};
  int tar = 7;
  solution.combinationSum(candidates, tar);

}