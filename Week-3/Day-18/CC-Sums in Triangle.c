
#include <stdio.h>

int triangle[100][100];  
int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        for (int i = 0; i < N; i++) {
            for (int j = 0; j <= i; j++) {
                scanf("%d", &triangle[i][j]);
            }
        }

        // Bottom-up DP
        for (int i = N - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                triangle[i][j] += max(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        printf("%d\n", triangle[0][0]);
    }

    return 0;
}
