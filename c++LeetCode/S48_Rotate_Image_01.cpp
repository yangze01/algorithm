class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int matrix_size = matrix.size();
    if (matrix_size == 1) {
      return;
    }

    for (int i = 0; i < matrix_size; i++) {
      for (int j = i; j < matrix_size; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = tmp;
      }
    }

    for (int i = 0; i < matrix_size; i++) {
      for (int j = 0; j < matrix_size / 2; j++) {
        int tmp = matrix[i][j];
        matrix[i][j] = matrix[i][matrix_size - j - 1];
        matrix[i][matrix_size - j - 1] = tmp;
      }
    }
  }
};
