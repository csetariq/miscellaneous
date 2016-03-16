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

void insertion_sort(int A[], int n) {
    for (int i = 1; i < n; ++i) {
        int temp = A[i];
        int j = i;
        while (--j >= 0 && temp < A[j])
            A[j + 1] = A[j];
        A[j + 1] = temp;
    }
}

int binary_search(int A[], int l, int r, int item) {
    if (l <= r) {
        int mid = l + (r - l) / 2;
        if (A[mid] == item)
            return 1;
        if (A[mid] > item)
            return binary_search(A, l, mid - 1, item);
        else
            return binary_search(A, mid + 1, r, item);
    }
    return 0;
}

int iterative_bin_search(int A[], int n, int item) {
    int l = 0, r = n - 1;

    while (r - l > 1) {
        int mid = l + (r - l) / 2;
    printf("before %d %d %d\n", l, r, mid);
        if (A[mid] <= item)
            l = mid;
        else
            r = mid;
    printf("after %d %d\n", l, r);
    }
    return l;
}

int main() {

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        int item;

        scanf("%d %d", &n, &item);
        
        int A[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", A + i);
        }
        quick_sort(A, 0, n-1);
        printf("%d\n", 
            iterative_bin_search(A, n, item));
    }

    return 0;
}

