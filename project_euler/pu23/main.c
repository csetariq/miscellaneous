#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NO 28123
#define PMAX MAX_NO / 2

char *prime;
char *abundant;
char *npnums;

int raise(int n, int to) {
	int res = n;
	while(--to)
		res *= n;
	return res;
}

void gen_prime() {
	prime = (char *)malloc(PMAX + 1);
	memset(prime, 1, PMAX + 1);
	for(int i = 2; i <= PMAX; ++i) {
		if(prime[i]) {
			int nxt = i + i;
			while(nxt <= PMAX) {
				prime[nxt] = 0;
				nxt += i;
			}
		}
	}
}

int divsum(int num) {
	int num_cpy = num;
	int sum = 1;
	for(int i = 2; i <= num; ++i) {
		int cnt = 0;
		if(prime[i] && num % i == 0) {
			while(num % i == 0) {
				++cnt;
				num /= i;
			}
			sum *= (raise(i, cnt + 1) - 1) / (i - 1);
		}
	}
	return sum - num_cpy;
}

void gen_abundant() {
	abundant = (char *)malloc(MAX_NO + 1);
	memset(abundant, 0, MAX_NO + 1);

	for(int i = 1; i <= MAX_NO; ++i) {
		if(divsum(i) > i) {
			abundant[i] = 1;
		}
	}

}

void gen_npnums() {
	npnums = (char *)malloc(MAX_NO + 1);
	memset(npnums, 0, MAX_NO + 1);

	for(int i = 1; i <= MAX_NO / 2; ++i) {
		if(abundant[i]) {
			for(int j = i; j <= MAX_NO; ++j) {
				if(abundant[j] && (i + j) <= MAX_NO)
					npnums[i + j] = 1;
			}
		}
	}
}

int main() {
	gen_prime();
	gen_abundant();
	gen_npnums();

	long sum = 0;

	for(int i = 1; i <= MAX_NO; ++i) {
		if(npnums[i] == 0) {
			sum += i;
		}
	}

	printf("%ld\n", sum);
	return 0;
}

