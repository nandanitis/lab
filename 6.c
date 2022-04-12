#include<stdio.h>

void towers(int n,char S, char D, char T)
{
    if(n==1)
        printf("\n move peg 1 from %c to %c ",S, D );
    else{
        towers(n-1,S,T,D);
        printf("move peg %d from %c to %c\n",n,S,D);
        towers(n-1,T,D,S);
    }
}

void main()
{
    int n;
    printf("enter the number of pegs : ");
    scanf("%d",&n);
    towers(n,'S','D','T');
}












int findMinRec(int A[], int n)
{
    if(n == 1)
        return A[0];
    return min(A[n-1], findMinRec(A, n-1));
}

int findMaxRec(int A[], int n)
{
    if(n == 1)
        return A[0];
    return max(A[n-1], findMaxRec(A, n-1));
}

int factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}


int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n-1) + fib(n-2);
}

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;
 
        if (arr[mid] == x)
            return mid;
 
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        return binarySearch(arr, mid + 1, r, x);
}
 
    return -1;
}