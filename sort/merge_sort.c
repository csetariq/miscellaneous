#include <stdio.h>

int is_sorted(int A[], int n) {
    int curr = A[0];
    for (int i = 1; i < n; ++i) {
        if (curr > A[i])
            return 0;
        curr = A[i];
    }
    return 1;
}

void merge(int A[], int lo, int mid, int hi) {
    int p = lo;
    int q = mid + 1;
    int *aux = (int *)malloc((hi - lo + 1)* sizeof(int));
    int t = 0;
    
    while (p <= mid && q <= hi)
        if (A[p] < A[q])
            aux[t++] = A[p++];
        else
            aux[t++] = A[q++];

    while (p <= mid)
        aux[t++] = A[p++];
    while (q <= hi)
        aux[t++] = A[q++];
    
    for (int i = lo, j = 0; i <= hi; ++i, ++j)
        A[i] = aux[j];
}

void merge_sort(int A[], int lo, int hi) {
    if (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        merge_sort(A, lo, mid);
        merge_sort(A, mid + 1, hi);
        merge(A, lo, mid, hi);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *A = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i)
        scanf("%d", A + i);

    merge_sort(A, 0, n - 1);

    if (is_sorted(A, n))
        printf("SORTED\n");
    else
        printf("NOT SORTED\n");

    return 0;
}


