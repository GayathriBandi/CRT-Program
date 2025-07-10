Test Case 1: Given string S = ABCDE and T = EDCBA. The string M is:
• Comparing the first indices, A # E, thus, M[l] = B.
• Comparing the second indices, B # D, thus, M[2] = B.
• Comparing the third indices, C = C, thus, M[3] = G.
• Comparing the fourth indices, D # B, thus, M[4] = B.
• Comparing the fifth indices, E # A, thus, M[5] = B.
Thus, M = BBGBB.
Test Case 2: Given string S = ROUND and T = RINGS. The string M is:
Comparing the first indices, R = R, thus, M[l] = G.
Comparing the second indices, O # I, thus, M[2] = B.
Comparing the third indices, U # N, thus, M[3] = B.
Comparing the fourth indices, N # G, thus, M[4] = B.
Comparing the fifth indices, D S, thus, M[5] = B.
  
#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        char S[6], T[6], M[6];
        scanf("%s", S);
        scanf("%s", T);
        
        for (int i = 0; i < 5; i++) {
            if (S[i] == T[i])
                M[i] = 'G';
            else
                M[i] = 'B';
        }
        M[5] = '\0'; 
        printf("%s\n", M);
    }
    
    return 0;
}
