#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n;
        scanf("%d", &n);
        
        int a, min = 10001; // since 0 <= Ai <= 10000
        long long sum = 0;
        
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            sum += a;
            if (a < min)
                min = a;
        }
        
        printf("%lld\n", sum - min);
    }
    
    return 0;
}
