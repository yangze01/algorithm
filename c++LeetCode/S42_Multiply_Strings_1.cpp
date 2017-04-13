class Solution {
public:
  string multiply(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    vector<int> tmp_num(n1 + n2, 0);
    int k = n1 + n2 - 2;
    for (int i = 0; i < n1; i++) {
      for (int j = 0; j < n2; j++) {
        tmp_num[k - i - j] += (num1[i] - '0') * (num2[j] - '0');
      }
    }
    int carry = 0;
    for (int i = 0; i < n1 + n2; i++) {
      tmp_num[i] += carry;
      carry = tmp_num[i] / 10;
      tmp_num[i] = tmp_num[i] % 10;
    }
    int n = tmp_num.size() - 1;
    while (tmp_num[n] == 0)
      n--;
    string res = "";
    for (int i = n; i >= 0; i--) {
      res.push_back(tmp_num[i] + '0');
    }
    if (res == "") {
      return "0";
    } else {
      return res;
    }
  }
};

int main() {
  Solution solution;
  cout << solution.multiply("99", "99");
}
