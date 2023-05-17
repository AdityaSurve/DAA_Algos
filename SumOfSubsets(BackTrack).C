#include <stdio.h>
#include <stdlib.h>

int x[100];
int count = 0;

int sum(int k, int n, int a[], int m) {
    int s = 0;
    for (int i = 1; i <= k; i++) {
        s = s + a[x[i]];
    }
    return s;
}

void SumOfSubsets(int k, int n, int a[], int m) {
    for (int i = 0; i <= 1; i++) {
        x[k] = i;
        if (sum(k, n, a, m) == m) {
            count++;
            printf("The solution %d is: ", count);
            for (int j = 1; j <= k; j++) {
                if (x[j] == 1) {
                    printf("%d ", a[j]);
                }
            }
            printf("\n");
        } else if (sum(k, n, a, m) < m) {
            SumOfSubsets(k + 1, n, a, m);
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements: ");
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int m;
    printf("Enter the sum: ");
    scanf("%d", &m);
    SumOfSubsets(1, n, a, m);
    return 0;
}