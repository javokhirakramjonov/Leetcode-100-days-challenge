class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for(int i = 0, nn = n / 2, temp; i < nn; ++ i) {
            for(int j = i; j < n - 1 - i; ++ j) {
                temp = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
                matrix[n - 1 - i][n - j - 1] = temp;
            }
        }
    }
}
