#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
        string str_prefix = "";
        for(int i = 0; i < strs[0].length(); i++){
            for(auto str = strs.begin(); str != strs.end(); str++){
                if(i > (*str).length() || (*str)[i] != strs[0][i]){
                    return str_prefix;
                }
            }
            str_prefix.push_back(strs[0][i]);
        }
        return str_prefix;
    }
};

int main(){
    vector<string> test = {"a"};
    Solution solution = Solution();
    cout<<solution.longestCommonPrefix(test);
}
