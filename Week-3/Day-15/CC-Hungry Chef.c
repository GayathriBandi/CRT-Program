#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int X, Y, N;
        long long R;
        scanf("%d %d %d %lld", &X, &Y, &N, &R);
        
        if (1LL * N * X > R) {
            printf("-1\n");
            continue;
        }
        
        int maxPremium = (R - 1LL * N * X) / (Y - X);
        if (maxPremium > N) maxPremium = N;
        int normal = N - maxPremium;
        printf("%d %d\n", normal, maxPremium);
    }
    return 0;
}
