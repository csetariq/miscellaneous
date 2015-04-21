#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 28123

char *abundant;
char *impossible;
int divsum(int n) {
	int sum = 1;
	for(int i = 2; i * i <= n; ++i) {
		int p = 1;
		while(n % i == 0) {
			p = p * i + 1;
			sum += n / i;
		}
		sum *= p;
	}

	if(n > 1)
		sum *= 1 + n;
	
	return sum;
}

int main(void) {
	abundant = (char *)calloc(sizeof(char) , (MAX + 1));
	impossible = (char *)calloc(sizeof(char) , (MAX + 1));

	for(int i = 1; i <= MAX; ++i)
		if(i < divsum(i)) {
			abundant[i] = 1;
		}
	
	for(int i = 1; i <= MAX; ++i)
		for(int j = i; j <= MAX; ++j)
			if(abundant[i] && abundant[j] && (i + j) <= MAX)
				impossible[i + j] = 1;

	long sum = 0;
	for(int i = 1; i <= MAX; ++i)
		if(impossible[i] == 0)
			sum += i;

	printf("%ld\n", sum);
	return 0;
}
