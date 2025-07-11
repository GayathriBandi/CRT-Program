#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        int A[105];
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }
        int inversions = 0, local = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if (A[i] > A[j])
                    inversions++;
            }
        }
        for (int i = 0; i < N - 1; i++) {
            if (A[i] > A[i + 1])
                local++;
        }
        if (inversions == local)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
