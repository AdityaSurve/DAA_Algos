#include<stdio.h>

void merge(int arr[],int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int L[n1],R[n2];
    for(int i=0;i<n1;i++){
        L[i] = arr[p+i];
    }
    for(int j=0;j<n2;j++){
        R[j] = arr[q+j+1];
    }
    int i=0,j=0,k=p;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[],int p,int r){
    if(p<r){
        int q = (p+r)/2;
        mergeSort(arr,p,q);
        mergeSort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}
void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n\n");
}
int main(){
    int arr[] = {23,47,28,79,91,45,32,67};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Array before sorting:\n");
    printArray(arr,n);
    mergeSort(arr,0,n-1);
    printf("Array after sorting:\n");
    printArray(arr,n);
    return 0;
}