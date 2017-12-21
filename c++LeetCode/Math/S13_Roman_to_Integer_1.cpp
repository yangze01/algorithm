#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int ssum = m[s[s.size()-1]];
        for(int i = s.size()-2; i>=0 ;i--){
//            cout<<"i = "<<i<<" ";
//            cout<<"ssum = "<<ssum<<endl;
            if( m[s[i]] < m[s[i+1]] ){
                ssum -= m[s[i]];
            }
            else{
                ssum += m[s[i]];
            }
        }
        return ssum;
    }
};

int main(){
    Solution solution;
    cout<<solution.romanToInt("MMMCMXCIX")<<endl;
}
