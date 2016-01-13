#include <stdio.h>

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

void selection_sort(int A[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i + 1; j < n; ++j) {
            if (A[j] < A[min])
                min = j;
        }
        swap(A, i, min);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int A[n];

    for (int i = 0; i < n; ++i)
        scanf("%d", A + i);

    selection_sort(A, n);

    if (is_sorted(A, n))
        printf("SORTED\n");
    else
        printf("NOT SORTED\n");

    return 0;
}


