#include <stdio.h>

int main() {
    int S = 11;
    int coins[] = {1, 3, 5};
    int min[S+1];

    for (int i = 0; i <= S; ++i)
        min[i] = 0x7fffffff;

    min[0] = 0;

    int num_coins = sizeof(coins) / sizeof(coins[0]);
    
    for (int i = 1; i <= S; ++i) {
        for (int j = 0; j < num_coins; ++j) {
            printf("i => %d; j => %d; Vj => %d; min[i - Vj] => %d, min[i] => %d\n", i, j, coins[j], min[i-coins[j]], min[i]);
            if (coins[j] <= i && min[i - coins[j]] + 1 < min[i]) {
                min[i] = min[i - coins[j]]+1;
                printf("Set min[i] = %d\n", min[i]);
            }
        }
    }

    for (int i = 0; i <= S; ++i)
        printf("%d => %d\n", i, min[i]);

    printf("%d\n", min[S]);
    return 0;
}
