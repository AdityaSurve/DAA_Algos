#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_CITIES 10

int numCities;
int graph[MAX_CITIES][MAX_CITIES];
bool visited[MAX_CITIES];
int bestPath[MAX_CITIES + 1];
int minCost = INT_MAX;

void inputGraph() {
    printf("Enter the number of cities: ");
    scanf("%d", &numCities);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

void printSolution() {
    printf("Optimal Path: ");
    for (int i = 0; i <= numCities; i++) {
        printf("%d ", bestPath[i]);
    }
    printf("\n");

    printf("Minimum Cost: %d\n", minCost);
}

void branchAndBoundTSP(int currCity, int level, int currCost) {
    if (level == numCities) {
        if (graph[currCity][0] != 0 && currCost + graph[currCity][0] < minCost) {
            minCost = currCost + graph[currCity][0];
            bestPath[level] = 0;
            bestPath[numCities] = minCost;
        }
        return;
    }

    for (int i = 0; i < numCities; i++) {
        if (!visited[i] && graph[currCity][i] != 0) {
            visited[i] = true;
            bestPath[level] = i;
            branchAndBoundTSP(i, level + 1, currCost + graph[currCity][i]);
            visited[i] = false;
        }
    }
}

int main() {
    inputGraph();

    visited[0] = true;
    bestPath[0] = 0;

    branchAndBoundTSP(0, 1, 0);

    printSolution();

    return 0;
}
