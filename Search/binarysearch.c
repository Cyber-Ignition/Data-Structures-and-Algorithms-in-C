#include <stdio.h>
#include <stdlib.h>

int binarySearch(int * arr, int value, int start, int end);

int main() {
    int n, i, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int * arr = (int*)malloc(n*sizeof(int));

    for (i=0; i<n; i++){
        printf("Enter element-%d: ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &k);

    int result = binarySearch(arr, k, 0, n-1);
    printf("%d", result);
    return 0;
}

int binarySearch(int * arr, int value, int start, int end) {
    while (start <= end){
        int middle = start + (end-start)/2;
        if (arr[middle] == value)
            return middle;
        else if (arr[middle] < value)
            start = middle + 1;
        else
            end = middle - 1;
    }
    return -1;
}