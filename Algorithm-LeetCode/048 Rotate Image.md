# LeetCode 048
## Rotate Image
题目链接：https://leetcode-cn.com/problems/rotate-image/
解法1 语言:C 时间复杂度 O(n*n) 空间复杂度 O(1)
```
void rotate(int** matrix, int matrixRowSize, int *matrixColSizes) {
    int n = matrixRowSize;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][n - j - 1];
            matrix[i][n - j - 1] = tmp;
        }
    }
}
```