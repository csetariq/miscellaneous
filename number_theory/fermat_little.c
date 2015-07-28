/**
*
*   Fermat's little theorem
*   
*       a^(m-2) = a^(-1) mod M
*
*   893583966 * 368080281 = 1 mod 1000000007
*/

#include <stdio.h>
#include <math.h>

#define max(a, b) (a > b) ? a : b
#define min(a, b) (a < b) ? a : b

int euclid_gcd(int a, int b) {
    if (b == 0)
        return a;
    return euclid_gcd(b, a % b);
}

long long power(long long x, long long y, long long m) {
    if (y == 0)
        return 1;

    long long p = power(x, y/2, m); 
    p = (p * p) % m;
    return (y % 2 == 0) ? p % m : (p * x) % m;
}

int findMMI(int a, int m) {

    return power(a, m-2, m);
}


int main() {
    int M = 1000000007;
    
    int a = 893583966;
    long long mmi = findMMI(a, M);

    printf("%10s %10d\n", "a:", a);
    printf("%10s %10lld\n", "MMI:", mmi);
    printf("%10s %10lld\n", "Remainder:", (a * mmi) % M);

    return 0;
}
