#include <stdio.h>
#include <math.h>

double largestTriangleArea(int** points, int pointsSize, int* pointsColSize) {
    double max = 0;

    for (int i = 0; i < pointsSize; i++) {
        for (int j = 0; j < pointsSize; j++) {
            if (points[i][j] < 0) {
                points[i][j] = -points[i][j];
            }
        }
    }


}

int main(void) {
    return 0;
}