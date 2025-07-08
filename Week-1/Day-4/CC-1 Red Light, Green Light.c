#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, K, count = 0;
        scanf("%d %d", &N, &K);

        for (int i = 0; i < N; i++) {
            int h;
            scanf("%d", &h);
            if (h > K) count++;
        }

        printf("%d\n", count);
    }

    return 0;
}
