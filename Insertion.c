#include <stdio.h>
#include <stdlib.h>
#define N 8
#define FACTORIAL 40320

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int *a, int l, int r, int arr[][N], int *count) {
    if (l == r) {
        for (int i = 0; i < N; i++) {
            arr[*count][i] = a[i];
        }
        (*count)++;
    } else {
        for (int i = l; i <= r; i++) {
            swap((a + l), (a + i));
            permute(a, l + 1, r, arr, count);
            swap((a + l), (a + i));
        }
    }
}
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
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int a[FACTORIAL][N];
    int count = 0;

    permute(arr, 0, N - 1, a, &count);
    int comparisons = 0;

    insertionSort(arr, N, &comparisons);

    printf("Number of comparisons: %d\n", comparisons);

    if(comparisons==7){
        printf("There were %d comparisions. This is the Best Case scenario.",comparisons); 
    }else if(comparisons <= 21 && comparisons >= 19){
        printf("There were %d comparisions. This is Average Case scenario.",comparisons);
    }else if(comparisons >= 28){
        printf("There were %d comparisions. This is the Worst Case scenario.",comparisons);
    }else if(comparisons <= 18 && comparisons >= 8){
        printf("There were %d comparisions. This is pretty good.",comparisons);
    }else if(comparisons <= 27 && comparisons >= 22){
        printf("There were %d comparisions. This is pretty bad.",comparisons);
    }else{
        printf("Strange!!! This should not be possible!!!");
    }

    return 0;
}
