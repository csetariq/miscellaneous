#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int is_sorted(int A[], int n) {
    int curr = A[0];
    for (int i = 1; i < n; ++i) {
        if (curr > A[i])
            return 0;
        curr = A[i];
    }
    return 1;
}

int * counting_sort(int A[], int n, int k) {
    int *B = (int *)malloc(n * sizeof(int));
    int *C = (int *)calloc(k + 1, sizeof(int));

    for (int i = 0; i < n; ++i)
        C[A[i]]++;

    for (int i = 1; i <= k; ++i)
        C[i] += C[i - 1]; //Beware, 1-based indices

    for (int j = n - 1; j >= 0; --j)
        B[--C[A[j]]] = A[j];

    free(C);
    return B;
}

int main() {
    int n;
    scanf("%d", &n);

    int *A = (int *)malloc(n * sizeof(int));

    int k = INT_MIN;
    for (int i = 0; i < n; ++i) {
        scanf("%d", A + i);
        if (A[i] > k)
            k = A[i];
    }

    int *B = counting_sort(A, n, k);

    if (is_sorted(B, n))
        printf("SORTED\n");
    else
        printf("NOT SORTED\n");

    return 0;
}

