#include <stdio.h>

char garden[55][55];

int countSquares(int n, int m) {
    int count = 0;
    for (int size = 2; size <= n && size <= m; size++) {
        for (int i = 0; i + size - 1 < n; i++) {
            for (int j = 0; j + size - 1 < m; j++) {
                char c1 = garden[i][j];
                char c2 = garden[i][j + size - 1];
                char c3 = garden[i + size - 1][j];
                char c4 = garden[i + size - 1][j + size - 1];
                if (c1 == c2 && c1 == c3 && c1 == c4)
                    count++;
            }
        }
    }
    return count;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            scanf("%s", garden[i]);
        }
        int result = countSquares(n, m);
        printf("%d\n", result);
    }
    return 0;
}
