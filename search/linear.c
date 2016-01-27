#include <stdio.h>

int linear_search(int A[], int n, int item) {
    for (int i = 0; i < n; ++i)
        if (A[i] == item)
            return 1;
    return 0;
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

        printf("%s\n", linear_search(A, n, item) ? "found" : "not found");
    }

    return 0;
}

