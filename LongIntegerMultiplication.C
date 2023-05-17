// long integer multiplication using divide and conquer

#include <stdio.h>
#include <math.h>

int main(){
    long long int x,y;
    printf("Enter the first number: ");
    scanf("%lld",&x);
    printf("Enter the second number: ");
    scanf("%lld",&y);
    int n = (int)fmax(log10(x),log10(y))+1;
    if(n%2!=0){
        n++;
    }
    long long int a,b,c,d;
    a = x/pow(10,n/2);
    b = x%(long long int)pow(10,n/2);
    c = y/pow(10,n/2);
    d = y%(long long int)pow(10,n/2);
    long long int ac = a*c;
    long long int bd = b*d;
    long long int ad = a*d;
    long long int bc = b*c;
    long long int sum = ac*pow(10,n)+ad*pow(10,n/2)+bc*pow(10,n/2)+bd;
    printf("The product of %lld and %lld is: %lld\n",x,y,sum);
    return 0;
}