#include <stdio.h>
#include <stdbool.h>

#define MAX_ITEMS 100

int knapsack(int values[], int weights[], int n, int capacity, int currentWeight, int currentValue) {
    if (currentWeight > capacity) {
        return -9999;
    }
    if (n < 0) {
        return currentValue;
    }
    int includeItem = knapsack(values, weights, n - 1, capacity, currentWeight + weights[n], currentValue + values[n]);
    int excludeItem = knapsack(values, weights, n - 1, capacity, currentWeight, currentValue);
    return (includeItem > excludeItem) ? includeItem : excludeItem;
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int capacity = 50;
    int numItems = sizeof(values) / sizeof(values[0]);
    int maxValue = knapsack(values, weights, numItems - 1, capacity, 0, 0);
    printf("Maximum value that can be obtained: %d\n", maxValue);
    return 0;
}
