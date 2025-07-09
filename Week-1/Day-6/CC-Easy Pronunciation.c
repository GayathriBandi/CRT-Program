Words that contain many consecutive consonants, like "schtschurowskia", are generally considered somewhat hard to pronounce.
We say that a word is hard to pronounce if it contains 4 or more consonants in a row; otherwise it is easy to pronounce. For example, "apple" and "polish" are easy to pronounce, but "schtschurowskia" is hard to pronounce.

#include <stdio.h>
#include <string.h>

int is_vowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        char S[101];  // Max length is 100 + 1 for null-terminator
        scanf("%d", &N);
        scanf("%s", S);

        int consonant_count = 0;
        int hard = 0;

        for (int i = 0; i < N; i++) {
            if (!is_vowel(S[i])) {
                consonant_count++;
                if (consonant_count >= 4) {
                    hard = 1;
                    break;
                }
            } else {
                consonant_count = 0;
            }
        }

        if (hard)
            printf("NO\n");
        else
            printf("YES\n");
    }

    return 0;
}
