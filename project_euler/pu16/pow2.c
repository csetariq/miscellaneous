#include <stdio.h>
#include <stdlib.h>

struct bigint {
	char num[1000];
	int k;
};

struct bigint bignum;

void init(void);
char *toString(void);
void times(int mend);
char *pow2(int n);

int main(void) {
	int t, n;
	init();
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		printf("%s\n",pow2(n));
        int k = bignum.k;
        long long sum = 0;
        while (k--)
            sum += bignum.num[k];
        printf("%lld\n", sum);
		init();
	}
	return 0;
}

char *pow2(int n) {
	if(n == 0)
		return "1";
	do {
		times(2);
	} while(--n);
	return toString();	
}

void init() {
	bignum.num[0] = 1;
	bignum.k = 1;
}

void times(int mend) {
	int temp = 0;
	for(int i = 0; i < bignum.k; ++i) {
		temp += bignum.num[i] * mend;
		bignum.num[i] = temp % 10;
		temp /= 10;
	}

	while(temp != 0) {
		bignum.num[bignum.k++] = temp % 10;
		temp /= 10;
	}
}

char *toString() {
	int i = 0, k = bignum.k;
	char *c = (char *)malloc(sizeof(char)*(k+1));
	while(k--) {
		c[i++] = bignum.num[k] + '0';
	}
	c[i] = '\0';
	return c;
}

