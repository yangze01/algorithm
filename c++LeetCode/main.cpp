#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 0 || nums.size() == 1){
            return;
        }
        auto i = nums.end()-2;
        auto ii = nums.end()-1;
        while(!(*i<*ii) && i != nums.begin()){
            i--;
            ii--;
        }
        if(i == nums.begin() && !(*i<*ii)){
            reverse(nums.begin(), nums.end());
        }
        else{
            auto j = nums.end()-1;
            while(!(*i < *j)){
                j--;
            }
            swap(*i, *j);
            reverse(ii, nums.end());
        }
        return;
    }
};
int main() {
    vector<int> nums = {1,3,2};
    Solution solution = Solution();
    solution.nextPermutation(nums);
    for(auto i = nums.begin(); i!=nums.end();i++){
        cout<<*i<<" ";
    }

}
