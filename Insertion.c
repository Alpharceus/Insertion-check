#include <stdio.h>
#define N 8

void insertionSort(int arr[], int n, int *comparisons) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        (*comparisons)++;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            (*comparisons)++;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int arr[N] = {1, 2, 3, 4, 5, 6, 7, 8};
    int comparisons = 0;

    insertionSort(arr, N, &comparisons);

    printf("Sorted array: \n");
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("Number of comparisons: %d\n", comparisons);

    return 0;
}
