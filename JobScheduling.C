#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d",&n);
    int p[n],d[n],j[n];
    printf("Enter the profits of the jobs: ");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("Enter the deadlines of the jobs: ");
    for(int i=0;i<n;i++){
        scanf("%d",&d[i]);
    }
    for(int i=0;i<n;i++){
        j[i] = i+1;
    }
    int temp;
    for(int i=0;i<n;i++){
        for(int k=i+1;k<n;k++){
            if(p[i]<p[k]){
                temp = p[i];
                p[i] = p[k];
                p[k] = temp;
                temp = d[i];
                d[i] = d[k];
                d[k] = temp;
                temp = j[i];
                j[i] = j[k];
                j[k] = temp;
            }
        }
    }
    int a[n];
    for(int i=0;i<n;i++){
        a[i] = 0;
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        for(int k=d[i]-1;k>=0;k--){
            if(a[k]==0){
                a[k] = j[i];
                sum = sum + p[i];
                break;
            }
        }
    }
    printf("The maximum profit is: %d\n",sum);
    printf("The sequence of jobs is: ");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}