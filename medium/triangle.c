// Problem: 120. Triangle
// Link: https://leetcode.com/problems/triangle/description/
// Time Complexity: O(n ^ 2)
// Memory Complexity: O(1)

int minimumTotal(int **triangle, int triangleSize, int *triangleColSize) {
    if (triangleSize == 0) {
        return 0;
    }

    for (int i = triangleSize - 2; i >= 0; i--) {
        for (int j = 0; j < triangleColSize[i]; j++) {
            int a = triangle[i + 1][j];
            int b = triangle[i + 1][j + 1];

            if (a < b) {
                triangle[i][j] += a;
            }
            else {
                triangle[i][j] += b;
            }
        }
    }

    return triangle[0][0];
}
