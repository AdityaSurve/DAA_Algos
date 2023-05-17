#include <stdio.h>
#include <limits.h>

#define MAX_COINS 100
#define INF INT_MAX

int coinChange(int coins[], int numCoins, int amount) {
    int dp[amount + 1];
    for (int i = 0; i <= amount; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < numCoins; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INF) {
                dp[i] = (dp[i - coins[j]] + 1) < dp[i] ? (dp[i - coins[j]] + 1) : dp[i];
            }
        }
    }
    return dp[amount];
}

int main() {
    int coins[] = {1, 5, 10, 25};
    int numCoins = 4;
    int amount = 30;
    int minCoins = coinChange(coins, numCoins, amount);
    printf("Minimum number of coins needed to make %d: %d\n", amount, minCoins);
    return 0;
}
