#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //cout<<nums[0];
        int num = 1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] <= 0){
                continue;
            }
            if(i>0 && nums[i] == nums[i-1]){
                    continue;
                }
            if(nums[i] != num){
                return num;
            }
            else{
                num++;
            }
        }
        return num++;
    }
};
int main(){
    Solution solution = Solution();
    vector<int> nums = {0, 1, 1, 2, 2};
    cout<<solution.firstMissingPositive(nums);
}
