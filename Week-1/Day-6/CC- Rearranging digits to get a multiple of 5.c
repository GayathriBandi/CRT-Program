A number is a multiple of 5 if and only if it ends in 0 or 5.
So, to determine whether we can rearrange the digits of N to make a multiple of 5, we just need to check if N contains a digit 0 or 5.

#include <stdio.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int D;
        char N[1001];  
        
        scanf("%d", &D);   
        scanf("%s", N);  
        
        int found = 0;
        for (int i = 0; i < D; i++) {
            if (N[i] == '0' || N[i] == '5') {
                found = 1;
                break;
            }
        }
        
        if (found)
            printf("Yes\n");
        else
            printf("No\n");
    }
    
    return 0;
}
