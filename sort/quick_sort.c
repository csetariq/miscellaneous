#include <stdio.h>
#include <stdlib.h>

void swap(int A[], int i, int j) {
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

int is_sorted(int A[], int n) {
    int curr = A[0];
    for (int i = 1; i < n; ++i) {
        if (curr > A[i])
            return 0;
        curr = A[i];
    }
    return 1;
}

int partition(int A[], int lo, int hi) {
    int i = lo - 1;
    int j = hi + 1;
    int pivot = A[lo];

    while (1) {
        while (A[++i] < pivot);
        while (A[--j] > pivot);

        if (i < j)
            swap(A, i, j);
        else
            break;
    }
    return j;
}

void quick_sort(int A[], int lo, int hi) {
    if (lo < hi) {
        int p = partition(A, lo, hi);
        quick_sort(A, lo, p);
        quick_sort(A, p + 1, hi);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *A = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i)
        scanf("%d", A + i);

    quick_sort(A, 0, n - 1);

    if (is_sorted(A, n))
        printf("SORTED\n");
    else
        printf("NOT SORTED\n");

    return 0;
}


