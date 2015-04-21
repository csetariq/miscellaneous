#include <stdio.h>
#include <string.h>

char *times(char *numStr, int time) {
	int i = 0;
	int temp;
	int p_result = 0;

	while((temp = numStr[i]) != '\0') {
		p_result += (temp - '0') * time;
		numStr[i++] = p_result % 10 + '0';
		p_result /= 10;
	}

	while(p_result) {
		numStr[i++] = p_result % 10 + '0';
		p_result /= 10;
	}
	numStr[i] = '\0';
	return numStr;
}

char *fact(int n, char *num) {

	int temp = n;
	int i = 0;
	while(temp) {
		num[i++] = temp % 10 + '0';
		temp /= 10;
	}
	num[i] = '\0';

	while(--n) {
		times(num, n);
	}
	return num;
}

void strrev(char *num) {
	int len = strlen(num);
	
	for(int i = len - 1; i >= len / 2; --i) {
		int temp = num[i];
		num[i] = num[len - 1 - i];
		num[len - 1 - i] = temp;
	}
}
int main(void) {
	int t;
	char num[1000];
	scanf("%d", &t);
	fact(t, num);
	strrev(num);
	printf("%s", num);
	int sum = 0;
	t = strlen(num);
	while(t--) {
		sum += num[t] - '0';
	}
	printf("\n%d\n", sum);
	return 0;
}
