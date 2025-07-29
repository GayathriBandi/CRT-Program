#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, U, D;
        scanf("%d %d %d", &N, &U, &D);

        int hills[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &hills[i]);
        }

        int parachute_used = 0;
        int i;
        for (i = 0; i < N - 1; i++) {
            int diff = hills[i+1] - hills[i];

            if (diff == 0) {
                continue;
            } else if (diff > 0) {
                if (diff <= U) {
                    continue;
                } else {
                    break;
                }
            } else {
                if (-diff <= D) {
                    continue;
                } else if (!parachute_used) {
                    parachute_used = 1;
                    continue;
                } else {
                    break;
                }
            }
        }

        printf("%d\n", i + 1);
    }

    return 0;
}
