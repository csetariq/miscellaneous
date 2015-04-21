#include <stdio.h>

int mDiff[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};

int findDay(int day, int month, int year) {
	int l2g = year - 1900;
	int y = month < 3 ? l2g - 1 : l2g;
	int sum = day + mDiff[month - 1] + l2g + (y / 4);
	return sum % 7;
}

int main(void) {
	int count = 0;
	for(int y = 1901; y <= 2000; ++y)
		for(int m = 1; m <= 12; ++m)
			if(!findDay(1, m, y))
				++count;
	printf("%d %d\n", findDay(3, 1, 1904), count);
	return 0;
}
