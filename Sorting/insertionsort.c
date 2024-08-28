#include <stdio.h>
#include <stdlib.h>

void insertionSort(int * arr, int n);
static int counter;

int main() {
    int n, i, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int * arr = (int*)malloc(n*sizeof(int));

    for (i=0; i<n; i++){
        printf("Enter element-%d: ", i+1);
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    printf("Sorted array is: ");
    for (i=0; i<n; i++){
        printf("%d, ", arr[i]);
    }

    printf("\nNo. of comparisons = %d", counter);
    return 0;
}

void insertionSort(int * arr, int n) {
    int i, j, key;
    for (j=1; j<n; j++)
    {
        key = arr[j];
        i = j-1;
        counter++;
        while (i>=0 && arr[i] > key)
        {
            counter++;
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
    }
}