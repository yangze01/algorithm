#include<iostream>
#include<vector>
#include<algorithm>
#include<typeinfo>
using namespace std;

class Solution {
public:
    const vector<string> keyboard = { "", "", "abc", "def", // '0','1','2',...
            "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    vector<string> letterCombinations(const string &digits) {
        vector<string> result;
        if (digits == ""){
            return {};
        }
        dfs(digits, 0, "", result);
        return result;
    }
    vector<string> dfs(const string &digits, size_t cur,string temp, vector<string> &result){
        if(cur == digits.size()){
            result.push_back(temp);
            return result;
        }
        else{
            for(auto letter:keyboard[digits[cur]-'0']){
                dfs(digits, cur+1, temp + letter, result);
            }
        }
        return result;
    }
};

int main(){
    //string test1 = "a";
    //string test2 = "b";
    string test = "23";
    Solution solution = Solution();
    vector<string> solu = solution.letterCombinations(test);
    for(auto s:solu){
        cout<<s<<endl;
    }
}
