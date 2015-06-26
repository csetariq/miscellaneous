#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int main() {
	char str[13];
	int tot = 0;
	for(int i = 10; i <= INT_MAX; ++i) {
		sprintf(str, "%d", i);
		int sum = 0;
		int t;
		int j = 0;
		while(t = str[j++]) {
			sum += pow((t - '0'), 5);
		}
		//fprintf(stdout, "deb %d %d\n", i, sum);
		if(sum == i) {
			tot += sum;
			fprintf(stdout, "%d\n", i);
		}
	}
	printf("tot: %d\n", tot);
	return 0;
}
