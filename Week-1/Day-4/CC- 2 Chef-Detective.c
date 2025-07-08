#include <stdio.h>
#include <stdbool.h>

int main() {
    int N;
    scanf("%d", &N);

    int R[N + 1]; 
    bool is_reported_to[N + 1];  
    for (int i = 1; i <= N; i++) {
        is_reported_to[i] = false;
    }

    for (int i = 1; i <= N; i++) {
        scanf("%d", &R[i]);
        if (R[i] != 0) {
            is_reported_to[R[i]] = true;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (!is_reported_to[i]) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
