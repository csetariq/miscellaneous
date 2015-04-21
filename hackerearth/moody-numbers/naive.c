#include <stdio.h>

#define MAX 1024

int sumofdigits(int n) {
    int sum = 0;

    while (n) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int contains(int *coll, int limit, int element) {
    for (int i = 0; i < limit; ++i) {
        if (coll[i] == element)
            return 1;
    }
    return 0;
}

void printcycle(int n) {
    int seen[100];
    int idx = 0;

    while (1) {
        n *= n;
        int res = sumofdigits(n);
        
        if (!contains(seen, idx, res)) {
            printf("\t%d\n", res);
            seen[idx++] = res;
            n = res;
        }
        else
            return;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
    	long long n;
    	scanf("%lld", &n);    	
    	int seen[10];
        int idx = 0;

        while (1) {
            n *= n;
            int res = sumofdigits(n);
        
            if (res == 1 || res == 4) {
                printf("YES\n");
                break;
            }
            if (!contains(seen, idx, res)) {
                seen[idx++] = res;
                n = res;
            }
            else {
                printf("NO\n");
                break;
            }
        }
    }
    return 0;
}
