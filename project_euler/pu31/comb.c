#include <stdio.h>
#include <stdlib.h>

int count(int money, int *coins, int left, int right) {
	//fprintf(stderr, "money %d l %d r %d cnt %d\n", money, left, right, cnt);
	if(money < 0 || (right - left) < 0)
		return 0;
	else {
		if(money == 0)
			return 1;
		else
			return count(money - coins[left], coins, left, right) +
					count(money, coins, left + 1, right);
	}
}
int main() {
	int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
	int len = sizeof(coins)/sizeof(int);
	printf("len %d\n", len);
	int tot = count(200, coins, 0, len - 1);
	printf("%d\n", tot);
	return 0;
}
