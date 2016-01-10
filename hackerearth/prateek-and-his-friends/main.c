#include <stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int N;
		long long X;
		scanf("%d %lld", &N, &X);
		
		int cost[N];
		for (int i = 0; i < N; ++i)
			scanf("%d", cost + i);
			
		long long sum = 0LL;
		int lo = 0;
		int found = 0;
		for (int i = 0; i < N; ++i) {
			sum += cost[i];
			
			while (sum > X) {
				sum -= cost[lo++];
			}
			
			if (sum == X) {
				printf("YES\n");
				found = 1;
				break;
			}
		}
		if (!found)
			printf("NO\n");
	}
    
    return 0;
}

