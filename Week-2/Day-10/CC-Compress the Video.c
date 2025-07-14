#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int N;
        scanf("%d", &N);
        
        int prev = -1, count = 0;
        for (int i = 0; i < N; ++i) {
            int x;
            scanf("%d", &x);
            if (x != prev) {
                count++;
                prev = x;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
