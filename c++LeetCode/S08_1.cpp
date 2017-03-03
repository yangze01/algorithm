#include <iostream>
using namespace std;
class Solution{
public:
    int myAtoi(string str){
        int index = 0;
        while(index < str.size() && str[index] == ' '){
            index += 1;
        }
        int flag = 1;
        if (index < str.size() && str[index] == '-'){
            flag = -1;
            index += 1;
        }
        else if(index < str.size() && str[index] == '+'){
            index +=1;
        }
        int res = 0;
        while(index < str.size()){
            if(str[index]<'0' || str[index]>'9'){
                return res * flag;
            }
            int digit = str[index] - '0';
            cout<<"m:"<<res*10+digit<<endl;
            cout<<"m.:"<<res*10.0+digit<<endl;
            if(flag == 1 && res*10.0+digit>INT_MAX)return INT_MAX;
            if(flag == -1 && -(res*10.0+digit)<INT_MIN) return INT_MIN;
            res = res*10 +digit;
            index += 1;
        }
        return res*flag;
    }
};
int main(){
    Solution solution;
    cout<<solution.myAtoi("2147483648")<<endl;
    cout<<"INT_MAX:"<<INT_MAX<<endl;
    cout<<"INT_MIN:"<<INT_MIN<<endl;
}
