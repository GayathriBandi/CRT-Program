#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, B;
        scanf("%d %d", &N, &B);

        int max_area = 0;

        for (int i = 0; i < N; i++) {
            int W, H, P;
            scanf("%d %d %d", &W, &H, &P);

            if (P <= B) {
                int area = W * H;
                if (area > max_area) {
                    max_area = area;
                }
            }
        }

        if (max_area == 0) {
            printf("no tablet\n");
        } else {
            printf("%d\n", max_area);
        }
    }

    return 0;
}
