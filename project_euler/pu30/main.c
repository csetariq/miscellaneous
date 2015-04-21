#include <stdio.h>
#include <math.h>
#include <limits.h>

#define MAX 0x7fffffffffffffffLL

long long f(long long num) {
    long long sum = 0;
    while (num) {
        sum += pow(num % 10, 5);
        num /= 10;
    }

    return sum;
}

int main() {
    for (long long num = 10; num <= MAX; ++num) {
        if (num == f(num))
            fprintf(stderr, "%lld\n", num);
        else {
            //fprintf(stdout, "%lld\n", num);
        }
    }
    return 0;
}
