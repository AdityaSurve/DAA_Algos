#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of coins: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the value of each coin: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int m;
    printf("Enter the amount: ");
    scanf("%d",&m);
    int count = 0;
    for(int i=n-1;i>=0;i--){
        while(m>=a[i]){
            m = m - a[i];
            count++;
        }
    }
    printf("The minimum number of coins required is: %d\n",count);
    return 0;
}