#include <stdio.h>

void recursivePrint(int a[], int n){
    if(n == 0)
        return;
    printf("%5d", a[n-1]); //at the end
    recursivePrint(a, n-1)
}

void main(){
    int a[] = {1,2,3,4};
    recursivePrint(a,4);
}