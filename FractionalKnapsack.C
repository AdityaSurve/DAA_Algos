#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of items: ");
    scanf("%d",&n);
    int w[n],p[n];
    float r[n];
    printf("Enter the weights of the items: ");
    for(int i=0;i<n;i++){
        scanf("%d",&w[i]);
    }
    printf("Enter the profits of the items: ");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    int c;
    scanf("%d",&c);
    for(int i=0;i<n;i++){
        r[i] = (float)p[i]/w[i];
    }
    float temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(r[i]<r[j]){
                temp = r[i];
                r[i] = r[j];
                r[j] = temp;
                temp = w[i];
                w[i] = w[j];
                w[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    int i=0;
    float profit = 0;
    while(c>0){
        if(w[i]<=c){
            profit = profit + p[i];
            c = c - w[i];
        }
        else{
            profit = profit + c*r[i];
            c = 0;
        }
        i++;
    }
    printf("The maximum profit is: %f\n",profit);
    return 0;
}