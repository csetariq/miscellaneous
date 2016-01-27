#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int t = 5;
    printf("%d\n", t);
    while (t--) {
        int n = rand(), item = rand();
        printf("%d %d\n", n, item);
        while (n--)
            printf("%d\n", rand());
    }
    return 0;
}
