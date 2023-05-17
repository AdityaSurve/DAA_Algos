#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

int n;
int dp[MAX][1 << MAX];
int dist[MAX][MAX];

int tsp(int pos, int mask) {
    if (mask == (1 << n) - 1) {
        return dist[pos][0];
    }
    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }
    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(city, mask | (1 << city));
            if (newAns < ans) {
                ans = newAns;
            }
        }
    }
    return dp[pos][mask] = ans;
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    printf("Enter the distance matrix: ");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            scanf("%d", &dist[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (1 << n); j++) {
            dp[i][j] = -1;
        }
    }
    printf("The minimum distance is: %d\n", tsp(0, 1));
    return 0;
}