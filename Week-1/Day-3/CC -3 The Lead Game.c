#include <stdio.h>
#include <stdlib.h>  

int main() {
    int N;
    scanf("%d", &N);

    int player1_total = 0;
    int player2_total = 0;

    int max_lead = 0;
    int winner = 0;

    for (int i = 0; i < N; i++) {
        int s1, s2;
        scanf("%d %d", &s1, &s2);

        player1_total += s1;
        player2_total += s2;

        int current_lead = abs(player1_total - player2_total);
        int current_leader = (player1_total > player2_total) ? 1 : 2;

        if (current_lead > max_lead) {
            max_lead = current_lead;
            winner = current_leader;
        }
    }

    printf("%d %d\n", winner, max_lead);
    return 0;
}
