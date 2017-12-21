#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) {
      return "";
    }
    string str_prefix = strs[0];
    for (auto str = strs.begin() + 1; str < strs.end(); str++) {
      while ((*str).find(str_prefix) != 0) {
        str_prefix.pop_back();
      }
    }
    return str_prefix;
  }
};

int main() {
  vector<string> test = {"aas", "aasb", "aaswqe"};
  Solution solution = Solution();
  cout << solution.longestCommonPrefix(test);
  //    string s= "abc";
  //    string str_prefix = "abasd";
  //    str_prefix.pop_back();
  //    cout<<str_prefix;
}
