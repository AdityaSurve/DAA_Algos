#include<stdio.h>

int max,min;
int a[100];

void maxmin (int i,int j){
    int max1,min1,mid;
    if(i==j){
        max=min=a[i];
    }
    else if(i==j-1){
        if(a[i]<a[j]){
            max=a[j];
            min=a[i];
        }
        else{
            max=a[i];
            min=a[j];
        }
    }
    else{
        mid=(i+j)/2;
        maxmin(i,mid);
        max1=max;
        min1=min;
        maxmin(mid+1,j);
        if(max<max1){
            max=max1;
        }
        if(min>min1){
            min=min1;
        }
    }
}
int main(){
    int i,num;
    printf("Enter the number of elements: ");
    scanf("%d",&num);
    printf("Enter the elements: ");
    for(i=0;i<num;i++){
        scanf("%d",&a[i]);
    }
    maxmin(0,num-1);
    printf("Maximum element is: %d\n",max);
    printf("Minimum element is: %d\n",min);
    return 0;
}