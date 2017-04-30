// 棋盘的横坐标是x，纵坐标是y。
// 横、纵、左斜、右斜四个方向可以用四个一次函数表示
// 对于坐标[i,j ]对应的四条线分别是：
// 横线可以用x=i [0,n-1]
// 纵线是y=j [0,n-1]
// 反斜线是x-y=i-j [-n+1,n-1]
// 正斜线是x+y=i+j [0,2n-2]
// 因此用四个数组可以表示这棋盘上所有被杀点,
// 在实现时为了方便可以用一个长度为6n-2的数组来存储
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    if (n <= 0) {
      return result;
    }
    vector<int> cols;
    search(n, cols, result);
    return result;
  }
  void search(int n, vector<int> &cols, vector<vector<string>> &result) {
    if (cols.size() == n) {
      result.push_back(drawResult(cols, n));
    }
    for (int row = 0; row < n; row++) {
      if (!isValid(cols, row)) {
        continue;
      }
      cols.push_back(row);
      search(n, cols, result);
      cols.pop_back();
    }
  }

  bool isValid(vector<int> &cols, int row_try) {
    int cur_col = cols.size();
    for (int i = 0; i < cur_col; i++) {
      if (cols[i] == row_try) {
        return false;
      }
      if (i - cols[i] == cur_col - row_try) {
        return false;
      }
      if (i + cols[i] == cur_col + row_try) {
        return false;
      }
    }
    return true;
  }
  vector<string> drawResult(vector<int> &cols, int n) {
    vector<string> one_result;
    for (int i = 0; i < cols.size(); i++) {
      string temp(n, '.');
      temp[cols[i]] = 'Q';
      one_result.push_back(temp);
    }
    return one_result;
  }
};
int main() {
  Solution solution;
  vector<vector<string>> result = solution.solveNQueens(5);
  cout << "[" << endl;
  for (auto i = result.begin(); i != result.end(); i++) {
    cout << "[";
    vector<string> j = *i;
    for (auto k = j.begin(); k != j.end(); k++) {
      cout << *k << endl;
    }
    cout << "]" << endl;
  }
}
