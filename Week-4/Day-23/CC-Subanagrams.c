#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 105
#define ALPHA 26

int main() {
    int n;
    scanf("%d", &n);
    char str[105];
    int freq[ALPHA];
    for (int i = 0; i < ALPHA; i++) freq[i] = 101;

    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        int temp[ALPHA] = {0};
        for (int j = 0; str[j]; j++) {
            temp[str[j] - 'a']++;
        }
        for (int j = 0; j < ALPHA; j++) {
            if (temp[j] < freq[j]) freq[j] = temp[j];
        }
    }

    int found = 0;
    for (int i = 0; i < ALPHA; i++) {
        for (int j = 0; j < freq[i]; j++) {
            putchar('a' + i);
            found = 1;
        }
    }
    if (!found) printf("no such string");
    printf("\n");
    return 0;
}
