#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	int sum = 1;
	int level = argc > 1 ? atoi(argv[1]) : 1001;

	if(!(level & 1)) {
		fprintf(stderr, "error: invalid level. level must be an odd number.\n");
		return 1;
	}

	for(int l = 3; l <= level; l += 2) {
		sum += 4 * l * l - 6 * l + 6;
	}

	printf("sum %d\n", sum);
	return 0;
}
