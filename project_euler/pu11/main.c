#include <stdio.h>
#include <limits.h>

int main(void) {
	int grid[20][20];
	for(int i = 0; i < 20; ++i)
		for(int j = 0; j < 20; ++j)
			scanf("%d", &grid[i][j]);
	printf("read the input\n");
	
	// vertical bruteforce
	int max = INT_MIN;
	
	for(int j = 0; j < 20; ++j) {
		for(int i = 0; i <= 20 - 4; ++i) {
			int t = 4;
			int prod = 1;
			while(t--) {
				prod *= grid[i + t][j];
			}
			if(prod > max)
				max = prod;
		}
	}	
	
	// horizontal bruteforce
	for(int i = 0; i < 20; ++i) {
		for(int j = 0; j <= 20 - 4; ++j) {
			int t = 4;
			int prod = 1;
			while(t--) {
				prod *= grid[i][j + t];
			}
			if(prod > max)
				max = prod;
		}
	}

	// top-left  to bottom-right diagonal
	// from left
	
	for(int i = 0; i <= 20 - 4; ++i) {
		for(int ti = i, tj = 0; ti + 4 <= 20 && tj + 4 <= 20; ++ti, ++tj) {
				int t = 4;
				int prod = 1;
				while(t--) {
					prod *= grid[ti + t][tj + t];
				}
				if(prod > max)
					max = prod;
		}
	}
	
	// from top
	for(int j = 1; j <= 20 - 4; ++j) {
		for(int ti = 0, tj = j; ti + 4 <= 20 && tj + 4 <= 20; ++ti, ++tj) {
				int t = 4;
				int prod = 1;
				while(t--) {
					prod *= grid[ti + t][tj + t];
				}
				if(prod > max)
					max = prod;
		}
	}

	// bottom-left  to top-right diagonal
	// from left
	
	for(int i = 19; i >= 3; --i) {
		for(int ti = i, tj = 0; ti - 4 >= 0 && tj + 4 <= 20; --ti, ++tj) {
				int t = 4;
				int prod = 1;
				while(t--) {
					prod *= grid[ti - t][tj + t];
				}
				if(prod > max)
					max = prod;
		}
	}
	
	// from bottom
	for(int j = 1; j <= 20 - 4; ++j) {
		for(int ti = 19, tj = j; ti - 4 >= 0 && tj + 4 <= 20; --ti, ++tj) {
				int t = 4;
				int prod = 1;
				while(t--) {
					prod *= grid[ti - t][tj + t];
				}
				if(prod > max)
					max = prod;
		}
	}

	printf("\n%d\n", max);
	return 0;
}
