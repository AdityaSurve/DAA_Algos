#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

bool isSafe(int vertex, int graph[MAX_VERTICES][MAX_VERTICES], int vertices[], int numVertices, int color) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[vertex][i] && color == vertices[i]) {
            return false;
        }
    }
    return true;
}

bool graphColoringUtil(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int numColors, int vertices[]) {
    if (numVertices == 0) {
        return true;
    }
    for (int color = 1; color <= numColors; color++) {
        if (isSafe(vertices[numVertices - 1], graph, vertices, numVertices, color)) {
            vertices[numVertices - 1] = color;
            if (graphColoringUtil(graph, numVertices - 1, numColors, vertices)) {
                return true;
            }
            vertices[numVertices - 1] = 0;
        }
    }
    return false;
}
void graphColoring(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices, int numColors) {
    int vertices[MAX_VERTICES];
    for (int i = 0; i < numVertices; i++) {
        vertices[i] = 0;
    }
    if (graphColoringUtil(graph, numVertices, numColors, vertices)) {
        printf("Graph can be colored using at most %d colors.\n", numColors);
        printf("Vertex Colors:\n");
        for (int i = 0; i < numVertices; i++) {
            printf("Vertex %d: Color %d\n", i + 1, vertices[i]);
        }
    } else {
        printf("Graph cannot be colored using %d colors.\n", numColors);
    }
}

int main() {
    int numVertices = 4;
    int numColors = 3;
    int graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    graphColoring(graph, numVertices, numColors);
    return 0;
}
