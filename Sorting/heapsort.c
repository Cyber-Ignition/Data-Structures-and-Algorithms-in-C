#include <stdio.h>
#include <stdlib.h>

static int counter = 0;

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapify(int arr[], int N, int i)
{
    counter++;
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])
        largest = left;

    if (right < N && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}

void build_max_heap(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
}

void heapSort(int arr[], int N)
{
    build_max_heap(arr, N);

    for (int i = N - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n, i, k;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int * arr = (int*)malloc(n*sizeof(int));

    for (i=0; i<n; i++){
        printf("Enter element-%d: ", i+1);
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    printf("Sorted array is: ");
    for (i=0; i<n; i++){
        printf("%d, ", arr[i]);
    }

    printf("\nNo. of comparisons = %d", counter);
    return 0;
}