Input        Output           
3             2
3             2
5             3
7
#include <stdio.h>
int maxHeight(int n) {
    int low = 0, high = n, ans = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        long long coins = (long long)mid * (mid + 1) / 2;
        if (coins <= n) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d\n", maxHeight(n));
    }
    return 0;
}
