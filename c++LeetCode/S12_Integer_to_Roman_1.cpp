#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string s = "";
        vector<int> nums = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> roms = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for(int i = 0; i < nums.size();i++){
            while(num - nums[i]>=0){
                num -= nums[i];
                s += roms[i];
            }
        }
        return s;
    }
};

int main(){
    string s = string(3,'s');
    cout<<s<<endl;
//    Solution solution;
//    cout<<solution.intToRoman(123)<<endl;
}
