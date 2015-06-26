#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>

#define MAX 16
#define SIZE 10000001
char *hash;
int main() {
	hash = (char *)calloc(SIZE, sizeof(char));
	for(int i = 2; i <= MAX; ++i)
		for(int j = 2; j <= 21; ++j) {
			unsigned long long res = i;
			for(int k = 1; k < j; ++k)
				res *= i;
			if(hash[abs(res % SIZE)])
				fprintf(stdout, "%4d ^ %-4d : %llu hit\n", i, j, res);
			else {
				hash[abs(res % SIZE)] = 1;
				fprintf(stdout, "%4d ^ %-4d : %llu\n", i, j, res);
			}
		}
	return 0;
}
