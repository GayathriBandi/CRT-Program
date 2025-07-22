#include <stdio.h>

#define MAX 1000000000

long long dp[1000000] = {0};

long long maxDollars(long long n) {
    if (n < 1000000 && dp[n] != 0)
        return dp[n];
    
    if (n == 0)
        return 0;

    long long val = maxDollars(n / 2) + maxDollars(n / 3) + maxDollars(n / 4);
    long long res = val > n ? val : n;

    if (n < 1000000)
        dp[n] = res;

    return res;
}

int main() {
    long long n;
    while (scanf("%lld", &n) != EOF) {
        printf("%lld\n", maxDollars(n));
    }
    return 0;
}
