#include <iostream>

using namespace std;
class Solution {
public:
    int reverse(int x) {
        int xx = x;
        int tmp = 0, ret = 0;
        while(xx!=0){
            tmp = ret * 10 + xx % 10;
            xx /= 10;
            if(tmp/10!=ret){
                ret = 0;
            }
        }
        return ret;
    }
};
int main()
{
    Solution solution;
    cout<<solution.reverse(1534236469);
}
