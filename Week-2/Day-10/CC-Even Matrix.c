#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        
        int odd = 1, even = 2;
        int matrix[N][N];
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if ((i + j) % 2 == 0) {
                    matrix[i][j] = odd;
                    odd += 2;
                } else {
                    matrix[i][j] = even;
                    even += 2;
                }
            }
        }
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
