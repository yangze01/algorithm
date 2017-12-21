#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_val = 0;
        int i = 0, j = height.size()-1;
        max_val = 0;
        while(i<j){
            int tmp = (j-i)*min(height[i],height[j]);
            if(tmp>max_val){
                max_val = tmp;
            }
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return max_val;
    }
};
int main(){
    vector<int> v = {1,1};
    Solution solution;
    cout<<solution.maxArea(v)<<endl;
}
