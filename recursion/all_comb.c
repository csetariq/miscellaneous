/**
*   Prints all permutation of a given string
*/

#include <stdio.h>
#include <string.h>

void swap(char *x, char *y) {
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *arr, int l, int r) {

    if (l == r)
        printf("%s\n", arr);
    else {
        for (int i = l; i <= r; ++i) {
            swap((arr+l), (arr+i));
            permute(arr, l+1, r);
            swap((arr+l), (arr+i));
        }
    }
}

int main(int argc, char *argv[]) {
    char c[100] = "ABC";
    if (argc > 1)
        strcpy(c, argv[1]);
    int n = strlen(c);
    permute(c, 0, n - 1);
    return 0;
}
