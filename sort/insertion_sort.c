#include <stdio.h>
#include<stdlib.h>

int is_sorted(int A[], int n) {
    int curr = A[0];
    for (int i = 1; i < n; ++i) {
        if (curr > A[i])
            return 0;
        curr = A[i];
    }
    return 1;
}

void insertion_sort(int A[], int n) {
    for (int i = 1; i < n; ++i) {
        int temp = A[i];
        int j = i;
        while (--j >= 0 && temp < A[j])
            A[j + 1] = A[j];
        A[j + 1] = temp;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *A = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; ++i)
        scanf("%d", A + i);

    insertion_sort(A, n);

    if (is_sorted(A, n))
        printf("SORTED\n");
    else
        printf("NOT SORTED\n");

    return 0;
}


