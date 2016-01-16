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

void bubble_sort(int A[], int n) {
    for (int k = n - 1; k >= 0; --k) {
        for (int i = 0; i < k; ++i) {
            if (A[i] > A[i + 1])
                swap(A, i, i + 1);
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *A = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i)
        scanf("%d", A + i);

    bubble_sort(A, n);

    if (is_sorted(A, n))
        printf("SORTED\n");
    else
        printf("NOT SORTED\n");

    return 0;
}


