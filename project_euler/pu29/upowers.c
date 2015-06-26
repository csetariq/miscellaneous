#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int *minroot;
char *temp;
int logx(int x, int z) {
	int y = 0;
	while(z/=x)
		++y;
	return y;
}

int main() {
	minroot = (int *)calloc(MAX + 1, sizeof(int));
	temp = (char *)calloc(MAX + 1, sizeof(char));

	for(int i = MAX; i > 1; --i)
		for(int j = i * i; j <= MAX; j *= i)
			minroot[j] = i;
	//for(int i = 1; i <= MAX; ++i)
		//fprintf(stderr, "%4d : %-d\n", i, minroot[i]);

	int gtot = 0;
	for(int i = 2; i <= MAX; ++i) {
		int sum = 0;
		if(minroot[i]) {
			memset(temp, 0, MAX + 1);
			int y = logx(minroot[i], i);
			int ty = y;
			while(--ty) {
				int max = (MAX / y) * ty;
				int j;
				for(j = max; j > 1; j -= ty) {
					temp[j] = 1;
				}
				fprintf(stderr, "\n<--i %d mr %d y %d ty %d max %d min %d -->\n", i, minroot[i], y, ty, max, j + ty);
			}

			for(int i = 2; i <= MAX; ++i)
				if(temp[i] == 0)
					++sum;
		}
		else {
			sum = MAX - 1;
		}
		gtot += sum;
	}

	printf("%d\n", gtot);
	return 0;
}
