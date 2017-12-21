#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    string longestCommonPrefix(vector<string> &strs){
        if(strs.empty()){
            return "";
        }
        int min_len = INT_MAX;
        for(auto str:strs){
            min_len = min(min_len, int(str.length()));
        }
        int low = 1;
        int high = min_len;
        while(low <= high){
            int midden = (low + high)/2;
            if(isCommonPrefix(strs,midden)){
                low = midden + 1;
            }
            else{
                high = midden -1;
            }
        }
        return strs[0].substr(0,(low + high)/2);
    }
    bool isCommonPrefix(vector<string> &strs, int len){
        string str1= strs[0].substr(0,len);
        for(auto str: strs){
            if(str.find(str1) != 0){
                return false;
            }
        }
        return true;
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
