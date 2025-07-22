#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);  // Number of test cases

    while (T--) {
        int N;
        int X;
        scanf("%d %d", &N, &X);  // N = number of houses, X = bomb strength

        int A[N];  // Array to store defense values
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }

        int max_destroyed = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] < X) {
                int destroyed = i + 1;  // i+1 houses destroyed if bomb dropped here
                if (destroyed > max_destroyed) {
                    max_destroyed = destroyed;
                }
            }
        }

        printf("%d\n", max_destroyed);
    }

    return 0;
}
