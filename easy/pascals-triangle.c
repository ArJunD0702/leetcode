#include <stdio.h>
#include <stdlib.h>

int **generate(int numRows, int *returnSize, int **returnColumnSizes) {
    *returnSize = numRows;

    int **rows = malloc(numRows * sizeof(int*));
    *returnColumnSizes = malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i++) {
        int cols = i + 1;

        rows[i] = malloc(cols * sizeof(int));
        (*returnColumnSizes)[i] = cols;

        rows[i][0] = 1;
        rows[i][cols - 1] = 1;

        for (int j = 1; j < cols - 1; j++) {
            rows[i][j] = rows[i - 1][j - 1] + rows[i - 1][j];
        }
    }

    return rows;
}