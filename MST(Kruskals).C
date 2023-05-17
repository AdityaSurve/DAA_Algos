#include<stdio.h>

// minimum spanning tree using kruskals algorithm

int parent[100];
int find(int i){
    while(parent[i]){
        i = parent[i];
    }
    return i;
}
int uni(int i,int j){
    if(i!=j){
        parent[j] = i;
        return 1;
    }
    return 0;
}
int main(){
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    int a[n][n];
    printf("Enter the adjacency matrix: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int ne = 1;
    int min,mincost = 0;
    int u,v;
    while(ne<n){
        min = 999;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]<min){
                    min = a[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if(uni(u,v)){
            printf("Edge %d:(%d,%d) cost:%d\n",ne++,u,v,min);
            mincost += min;
        }
        a[u][v] = a[v][u] = 999;
    }
    printf("Minimum cost = %d\n",mincost);
    return 0;
}