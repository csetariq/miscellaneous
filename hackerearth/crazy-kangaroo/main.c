#include <stdio.h>
#include <math.h>

int main()
{
	int N;
	scanf("%d", &N);
	
	while(N--) {
		/*
		double A, B;
		double M;
		scanf("%lf %lf %lf", &A, &B, &M);
		
		if (M == 0.0)
			A = B;
		long long start = ceil(A/M) * M;
		long long end = floor(B/M) * M;
		
		// printf("%d %d\n", start, end);
		
		if (M && A < B && start && end && start <= end)
			printf("%d\n", ((end - start) / (int)M) + 1);
		else
			printf("0\n");
		*/
		
		// naive approach
		long long A, B;
		long long M;
		scanf("%lld %lld %lld", &A, &B, &M);
		
		int count=0;
		for (long long i = A; i <= B; ++i) {
			if (i % M == 0)
				++count;
		}
		printf("%d\n", count);
		
	}
    
    return 0;
}
