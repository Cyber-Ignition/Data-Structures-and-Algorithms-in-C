#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int * arr, int n);
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

    bubbleSort(arr, n);

    printf("Sorted array is: ");
    for (i=0; i<n; i++){
        printf("%d, ", arr[i]);
    }

    printf("\nNo. of comparisons = %d", counter);
    return 0;
}

void bubbleSort(int * arr, int n) {
    int j, temp, t, bound = n;
    do
    {
        t = 0;
        for (j=0; j < bound; j++)
        {
            counter++;
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                t = j;
            }
        }
        bound = t;
    } while (t>0);
}