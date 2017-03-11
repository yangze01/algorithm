#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res ={};
        if(n == 0){
            return res;
        }
        int left = n;
        int right = n;
        recursion(res, left, right, "");
        return res;
    }
private:
    void recursion(vector<string> &res, int left, int right, string tmp){
        if(left == 0 && right == 0){
            res.push_back(tmp);
        }
        if(left > 0){
            recursion(res, left-1, right, tmp + '(');
        }
        if(right > 0 && left < right){
            recursion(res, left, right-1, tmp + ')');
        }
    }
};
int main(){
    Solution solution = Solution();
    vector<string> ret = solution.generateParenthesis(3);
    cout<<'[';
    for(auto s:ret){
        cout<<s<<endl;
    }
    cout<<']'<<endl;

}
