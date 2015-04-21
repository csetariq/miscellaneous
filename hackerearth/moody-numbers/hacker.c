#include <stdio.h>

int sumofdigits(long long n) {
    int sum = 0;

    while (n) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int main()
{
    int t;
    scanf("%d", &t);
    
    while (t--) {
    	long long n;
    	scanf("%lld", &n);    	
    	
    	//printf("testing %lld\n", n);
    	int sod = sumofdigits(n);
    	
    	if (sod && sod < 3) {
    		printf("YES\n");
    		continue;
    	}
    	
    	sod = sumofdigits(sumofdigits(n * n));
    	
    	if (sod == 1)
    		printf("YES\n");
    	else
    		printf("NO\n");
    }
    return 0;
}

