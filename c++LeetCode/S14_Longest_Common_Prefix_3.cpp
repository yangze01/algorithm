#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty() || strs.size() == 0){
            return "";
        }
        return longestCommon(strs,0,strs.size()-1);
    }
    string longestCommon(vector<string> &strs, int l,int r){
        if(l == r){
            return strs[l];
        }
        else{
            int mid = (l+r)/2;
            string leftlcp = longestCommon(strs, l, mid);
            string rightlcp = longestCommon(strs, mid+1, r);
            return commonPrefix(leftlcp,rightlcp);
        }
    }
    string commonPrefix(string left, string right){
        int min_len = min(left.length(),right.length());
        for(int i = 0;i < min_len;i++){
            if(left[i] != right[i]){
                return left.substr(0,i);
            }
        }
        return left.substr(0,min_len);
    }
};

int main(){
    vector<string> test = {"aasc", "aasb", "aaswqe"};
    Solution solution = Solution();
    cout<<solution.longestCommonPrefix(test);
//    string s= "abc";
//    string str_prefix = "abasd";
//    str_prefix.pop_back();
//    cout<<str_prefix;
}
