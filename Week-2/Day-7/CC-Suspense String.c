#include <stdio.h>
#include <string.h>

#define MAX 2005

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int N;
        char S[MAX], T[MAX];
        scanf("%d", &N);
        scanf("%s", S);
        
        int l = 0, r = N - 1;
        int front = MAX / 2, back = MAX / 2;
        int isAliceTurn = 1;

        while (l <= r) {
            char ch;
            if (isAliceTurn) {
                ch = S[l++];
                if (ch == '0') T[--front] = ch;
                else T[back++] = ch;
            } else {
                ch = S[r--];
                if (ch == '1') T[--front] = ch;
                else T[back++] = ch;
            }
            isAliceTurn ^= 1;
        }

        for (int i = front; i < back; i++) {
            putchar(T[i]);
        }
        putchar('\n');
    }

    return 0;
}
