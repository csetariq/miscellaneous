#include <stdio.h>
#include <limits.h>
#include <math.h>

int main(void) {
	for(long i = 500; ; ++i) {
		long tr_num = i * (i + 1) / 2;
		long f_count = 1;
		long limit = sqrt(tr_num);
		for(long f = 1; f <= limit; ++f) {
			if(tr_num % f == 0)
				++f_count;
		}
		if((f_count << 1) > 500) {
			printf("%d\n", tr_num);
			break;
		}
	}
	return 0;
}
