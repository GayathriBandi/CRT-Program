#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        char word[1005];
        scanf("%s", word);
        
        int len = strlen(word);
        int instructions = 1;
        int curr = word[0] - 'a';
        instructions++;
        
        for (int i = 1; i < len; i++) {
            int next = word[i] - 'a';
            int steps = (next - curr + 26) % 26;
            instructions += steps + 1;
            curr = next;
        }
        
        if (instructions <= 11 * len)
            printf("YES\n");
        else
            printf("NO\n");
    }
    
    return 0;
}
