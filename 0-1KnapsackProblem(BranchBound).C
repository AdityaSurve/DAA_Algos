#include <stdio.h>
#include <stdbool.h>

#define MAX_ITEMS 100

typedef struct {
    int value;
    int weight;
} Item;

int calculateUpperBound(Item items[], int numItems, int capacity, int currentValue, int currentWeight, int currentIndex) {
    int remainingCapacity = capacity - currentWeight;
    int upperBound = currentValue;
    while (currentIndex < numItems && items[currentIndex].weight <= remainingCapacity) {
        upperBound += items[currentIndex].value;
        remainingCapacity -= items[currentIndex].weight;
        currentIndex++;
    }
    if (currentIndex < numItems) {
        upperBound += (remainingCapacity * items[currentIndex].value) / items[currentIndex].weight;
    }

    return upperBound;
}

int knapsackBranchBound(Item items[], int numItems, int capacity) {
    for (int i = 0; i < numItems - 1; i++) {
        for (int j = 0; j < numItems - i - 1; j++) {
            double valuePerWeight1 = (double)items[j].value / items[j].weight;
            double valuePerWeight2 = (double)items[j + 1].value / items[j + 1].weight;

            if (valuePerWeight1 < valuePerWeight2) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }

    int maxValue = 0;
    int currentValue = 0;
    int currentWeight = 0;
    int currentIndex = 0;

    bool includedItems[MAX_ITEMS] = {false};

    while (true) {
        int upperBound = calculateUpperBound(items, numItems, capacity, currentValue, currentWeight, currentIndex);

        if (upperBound <= maxValue || currentWeight > capacity) {
            if (currentWeight <= capacity && currentValue > maxValue) {
                maxValue = currentValue;
            }

            if (currentIndex == 0) {
                break;
            }

            currentIndex--;
            currentWeight -= items[currentIndex].weight;
            currentValue -= items[currentIndex].value;
            includedItems[currentIndex] = false;
        } else {
            currentWeight += items[currentIndex].weight;
            currentValue += items[currentIndex].value;
            includedItems[currentIndex] = true;

            if (currentWeight <= capacity && currentValue > maxValue) {
                maxValue = currentValue;
            }

            currentIndex++;
        }
    }

    printf("Included Items:\n");
    for (int i = 0; i < numItems; i++) {
        if (includedItems[i]) {
            printf("Item %d\n", i + 1);
        }
    }
    return maxValue;
}

int main() {
    int numItems = 4;
    int capacity = 10;
    Item items[MAX_ITEMS] = {
    {40, 5},
    {30, 4},
    {50, 6},
    {10, 2}
    };

    int maxValue = knapsackBranchBound(items, numItems, capacity);

    printf("Maximum value that can be obtained: %d\n", maxValue);

    return 0;
}