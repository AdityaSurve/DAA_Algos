//  Optimal Storage of Tapes using Greedy Approach in C

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Enter the number of tapes: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the size of each tape: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int temp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum + a[i];
    }
    printf("The optimal storage of tapes is: %d\n",sum);
    return 0;
}
