#include <stdio.h>
#define MAX 1000000000000000

int main() {

    long long pf = 1, cf = 1;

    printf("%lld\n", cf);

    while (cf < MAX) {
        long long tmp = cf;
        cf += pf;
        pf = tmp;
        printf("%lld\n", cf);
    }

    return 0;
}
