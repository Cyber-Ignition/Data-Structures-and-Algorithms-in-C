#include <stdio.h>
#include <stdlib.h>

/*
position formula derivation:
arr[start] = m*start + c (I)
arr[end] = m*end + c (II)

Substracting eq I and II, we get
m = (arr[end] - arr[start])/(end - start) (III)

x = m*pos + c (IV)
Substracting eq IV and I we get
x - arr[start] = m*(pos - start)
=> pos = start + (x-arr[start])/m
=> pos = start + (x-arr[start])*(end-start)/(arr[end] - arr[start])
*/

int interpolationSearch(int * arr, int x, int start, int end);

int main() {
    int n, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int * arr = (int*)malloc(n*sizeof(int));

    for (i=0; i<n; i++){
        printf("Enter element-%d: ", i+1);
        scanf("%d", &arr[i]);
    }

    int pos = interpolationSearch(arr, 5, 0, n-1);
    printf("%d", pos);
    return 0;
}

int interpolationSearch(int * arr, int x, int start, int end){
    int pos;
    if (start <= end && x >= arr[start] && x <= arr[end]){
        pos = start + ((x-arr[start])*(end-start)/(x-arr[start]));

        if (arr[pos] == x)
            return pos;
        
        if (arr[pos] < x)
            return interpolationSearch(arr, x, pos+1, end);
        
        if (arr[pos] > x)
            return interpolationSearch(arr, x, start, pos-1);
    }
    return -1;
}