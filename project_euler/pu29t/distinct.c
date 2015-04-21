#include <stdio.h>
#include <stdlib.h>

#define MAX 100

char *sdiv;

int logx(int x, int z) {
	int y = 0;
	while(z /= x)
		++y;
	return y;
}

int main() {
	sdiv = (char *)calloc(MAX + 1, sizeof(char));
	
	for(int i = 2; i <= MAX; ++i)
		for(int j = i * i; j <= MAX; j *= i)
			sdiv[j] = i;
	for(int i = 0; i <= MAX; ++i) {
		fprintf(stderr, "%3d : %-3d\n", i, sdiv[i]);	
	}
	
	int gtot = 0;
	
	for(int i = 2; i <= MAX; ++i) {
		int sum;
		if(sdiv[i]) {
			int y = logx(sdiv[i], i);
			sum = (MAX - 1) - (MAX / y - 1);
			gtot += sum;
		}
		else {
			sum = MAX - 1;
			gtot += sum;
		}
		fprintf(stdout, "%3d : %-3d\n", i, sum);
	}
	fprintf(stdout, "grand total: %d\n", gtot);
	return 0;
}
