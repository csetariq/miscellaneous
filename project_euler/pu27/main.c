#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int is_prime(int n) {
	if(n < 1)
		return 0;
	for(int i = 2; i * i <= n; ++i)
		if(n % i == 0)
			return 0;
	return 1;
}

int max_cons(int a, int b) {
	int i = 0;

	while(1) {
		int n = i*i + a*i + b;
		if(!is_prime(n))
			return i;
		++i;
	}
}
int main() {
	int max = INT_MIN;
	int maxA = INT_MIN;
	int maxB = INT_MIN;

	for(int i = 1; i <= 1000; ++i) {
		if(is_prime(i)) {
			for(int j = 1; j <= 1000; ++j) {
				if(is_prime(j)) {
					int tmax = max_cons(i,j);
					if(tmax > max) {
						maxA = i;
						maxB = j;
						max = tmax;
					}
					fprintf(stderr, "test %d, %d : %d\n", i, j, tmax);

					tmax = max_cons(-i, j);
					if(tmax > max) {
						maxA = -i;
						maxB = j;
						max = tmax;
					}
					fprintf(stderr, "test %d, %d : %d\n", i, j, tmax);
					
					tmax = max_cons(i, -j);
					if(tmax > max) {
						maxA = i;
						maxB = -j;
						max = tmax;
					}
					fprintf(stderr, "test %d, %d : %d\n", i, j, tmax);
					
					tmax = max_cons(-i, -j);
					if(tmax > max) {
						maxA = -i;
						maxB = -j;
						max = tmax;
					}
					fprintf(stderr, "test %d, %d : %d\n", i, j, tmax);
				}
			}
		}
	}
	printf("%d * %d = %d : %d\n", maxA, maxB, maxA*maxB, max);
	printf("%d\n", max_cons(-79, 1601));
	return 0;
}
