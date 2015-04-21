#include <stdio.h>

void destroy_nation(int planet[4][4], int x, int y, int N, int M, int *countries) {
	printf("came here\n");
	if (planet[x][y]) {
		planet[x][y] = 0;
		--*countries;
		
		int tx, ty;
		
		tx = x - 1;
		ty = y;
		if ( tx >= 1 && tx <= N && ty >= 1 && ty <= M && planet[tx][ty])
			destroy_nation(planet, tx, ty, N, M, countries);
			
		tx = x + 1;
		ty = y;
		if ( tx >= 1 && tx <= N && ty >= 1 && ty <= M && planet[tx][ty])
			destroy_nation(planet, tx, ty, N, M, countries);
			
		tx = x;
		ty = y - 1;
		if ( tx >= 1 && tx <= N && ty >= 1 && ty <= M && planet[tx][ty])
			destroy_nation(planet, tx, ty, N, M, countries);
		
		tx = x;
		ty = y + 1;
		if ( tx >= 1 && tx <= N && ty >= 1 && ty <= M && planet[tx][ty])
			destroy_nation(planet, tx, ty, N, M, countries);
		
	}
	else
		return;
}

int main()
{
	int planet[4][4];
//	printf("came here\n");
    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);
    printf("%d %d %d\n", N, M , Q);
    int countries = 0;
    for (int i = 1; i <= N; ++i)
    	for (int j = 1; j <= M; ++j) {
    		scanf("%d", &planet[i][j]);
    		if (planet[i][j])
    			++countries;
    	}

	while (Q--) {
		int x, y;
		scanf("%d %d", &x, &y);
		destroy_nation(planet, x, y, N, M, &countries);
	    printf("%d\n", countries);
	}
	
    
    return 0;
}

