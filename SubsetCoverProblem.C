#include <stdio.h>
#include <stdbool.h>

#define MAX_SETS 100

void subsetCover(int universe[], int sets[][MAX_SETS], int numSets, int setSize) {
    bool isElementSelected[setSize];
    int numSelectedSets = 0;
    for (int i = 0; i < setSize; i++) {
        isElementSelected[i] = false;
    }
    while (numSelectedSets < numSets) {
        int maxUncovered = 0; 
        int maxSetIndex = -1;
        for (int i = 0; i < numSets; i++) {
            int uncovered = 0;
            for (int j = 0; j < setSize; j++) {
                if (sets[i][j] && !isElementSelected[j]) {
                    uncovered++;
                }
            }
            if (uncovered > maxUncovered) {
                maxUncovered = uncovered;
                maxSetIndex = i;
            }
        }
        if (maxSetIndex != -1) {
            for (int j = 0; j < setSize; j++) {
                if (sets[maxSetIndex][j]) {
                    isElementSelected[j] = true;
                }
            }
            printf("Set %d: ", maxSetIndex);
            for (int j = 0; j < setSize; j++) {
                if (sets[maxSetIndex][j]) {
                    printf("%d ", universe[j]);
                }
            }
            printf("\n");
            numSelectedSets++;
        }
    }
}

int main() {
    int universe[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sets[][MAX_SETS] = {
        {1, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1}
    };
    int numSets = 6;
    int setSize = 10;
    printf("Subset Cover:\n");
    subsetCover(universe, sets, numSets, setSize);
    return 0;
}
