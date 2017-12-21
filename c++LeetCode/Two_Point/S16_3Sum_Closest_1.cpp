#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ret = INT_MAX;
        for(auto i = 0;i < nums.size()-2;i++){
            int left = i + 1;
            int right = nums.size()-1;
            while(left < right){
                int ssum = nums[i] + nums[left] + nums[right];
                if(ret == INT_MAX || abs(ssum - target) < abs(ret - target)){
                        ret = ssum;
                }
                if(ssum <= target){
                    left += 1;
                }
                else{
                    right -= 1;
                }
            }
        }
        return ret;
    }
};
int main(){
    vector<int> test = {0,1,2};
    Solution solution = Solution();
    cout<<solution.threeSumClosest(test,0);
}
