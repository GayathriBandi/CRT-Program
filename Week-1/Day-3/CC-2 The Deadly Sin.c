#include <stdio.h>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long X, Y;
        scanf("%lld %lld", &X, &Y);
        if (X == 0 || Y == 0)
            printf("%lld\n", X + Y);
        else
            printf("%lld\n", gcd(X, Y) * 2);
    }
    return 0;
}
