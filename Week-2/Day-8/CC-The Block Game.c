#include <stdio.h>

int isPalindrome(int n) {
    int original = n;
    int reversed = 0;

    while (n > 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n = n / 10;
    }

    return original == reversed;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        if (isPalindrome(N))
            printf("wins\n");
        else
            printf("loses\n");
    }

    return 0;
}
