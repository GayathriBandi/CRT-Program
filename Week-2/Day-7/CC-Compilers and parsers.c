#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    char expr[1000001];

    while (T--) {
        scanf("%s", expr);
        int count = 0, max_len = 0;
        for (int i = 0; expr[i] != '\0'; i++) {
            if (expr[i] == '<') {
                count++;
            } else {
                count--;
            }
            if (count < 0) {
                break;
            }
            if (count == 0) {
                max_len = i + 1;
            }
        }
        printf("%d\n", max_len);
    }
    return 0;
}
