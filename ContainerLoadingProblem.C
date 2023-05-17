#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of containers: ");
    scanf("%d",&n);
    int c[n];
    printf("Enter the capacity of each container: ");
    for(int i=0;i<n;i++){
        scanf("%d",&c[i]);
    }
    int m;
    printf("Enter the number of boxes: ");
    scanf("%d",&m);
    int b[m];
    printf("Enter the weight of each box: ");
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }
    int a[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            a[i][j] = 0;
        }
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==0){
                if(b[j]<=c[i]){
                    a[i][j] = 1;
                    c[i] = c[i] - b[j];
                    sum = sum + b[j];
                }
            }
        }
    }
    printf("The maximum weight that can be loaded is: %d\n",sum);
    printf("The boxes loaded in each container are: \n");
    for(int i=0;i<n;i++){
        printf("Container %d: ",i+1);
        for(int j=0;j<m;j++){
            if(a[i][j]==1){
                printf("%d ",j+1);
            }
        }
        printf("\n");
    }
    return 0;
}