class Solution {
public:
  int strStr(string haystack, string needle) {
    int i, j, lenh = haystack.length(), lenn = needle.length();
    if (lenn == 0) {
      return 0;
    }
    for (int i = 0; i <= lenh - lenn; i++) {
      for (j = 0; j < lenn; j++) {
        if (haystack[i + j] != needle[j])
          break;
      }
      if (j == lenn)
        return i;
    }
    return -1;
  }
};
