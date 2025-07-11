#include <stdio.h>

int canWin(int A[], int N, int H, int X) {
    for (int i = 0; i < N; i++) {
        if (A[i] > X) {
            if (H <= A[i])
                return 0;
            H -= A[i];
        }
    }
    return H > 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, H;
        scanf("%d %d", &N, &H);
        int A[N], maxA = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
            maxA = max(maxA, A[i]);
        }

        int low = 0, high = maxA, ans = maxA;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (canWin(A, N, H, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
