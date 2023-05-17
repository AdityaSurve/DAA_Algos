#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100

int numVertices;
int graph[MAX_VERTICES][MAX_VERTICES];

void inputGraph() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

int findMinKey(int key[], bool mstSet[]) {
    int minKey = INT_MAX;
    int minIndex = -1;

    for (int v = 0; v < numVertices; v++) {
        if (mstSet[v] == false && key[v] < minKey) {
            minKey = key[v];
            minIndex = v;
        }
    }

    return minIndex;
}

void printMST(int parent[]) {
    printf("Edge   Weight\n");
    for (int v = 1; v < numVertices; v++) {
        printf("%d - %d    %d\n", parent[v], v, graph[v][parent[v]]);
    }
}

void primMST() {
    int parent[MAX_VERTICES];
    int key[MAX_VERTICES];
    bool mstSet[MAX_VERTICES];

    for (int i = 0; i < numVertices; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = findMinKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < numVertices; v++) {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent);
}

int main() {
    inputGraph();

    primMST();

    return 0;
}
