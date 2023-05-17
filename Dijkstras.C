#include<stdio.h>

// Dijkstra's Algorithm

int min(int a,int b){
    return a<b?a:b;
}

int main(){
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter the adjacency matrix:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int dist[n];
    int visited[n];
    for(int i=0;i<n;i++){
        dist[i] = 999;
        visited[i] = 0;
    }
    int source;
    printf("Enter the source vertex: ");
    scanf("%d",&source);
    dist[source] = 0;
    for(int i=0;i<n-1;i++){
        int u = -1;
        for(int j=0;j<n;j++){
            if(!visited[j] && (u==-1 || dist[j]<dist[u])){
                u = j;
            }
        }
        visited[u] = 1;
        for(int v=0;v<n;v++){
            if(!visited[v] && a[u][v]!=0){
                dist[v] = min(dist[v],dist[u]+a[u][v]);
            }
        }
    }
    printf("The shortest distances from the source vertex %d are:\n",source);
    for(int i=0;i<n;i++){
        printf("%d ",dist[i]);
    }
    printf("\n");
    return 0;
}