#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void prepend0(char *num, int len) {
	int clen = strlen(num);
	while(clen < len)
		num[clen++] = '0';
	num[len] = '\0';
}

int add(char *num, char *addend) {
	int l1 = strlen(num);
	int l2 = strlen(addend);
	int maxlen = l1 > l2 ? l1 : l2;
	int carry = 0;
	int i = 0;

	if(l1 > l2)
		prepend0(addend, maxlen);
	else if(l2 > l1)
		prepend0(num, maxlen);
		
	for(i = 0 ; i < maxlen; ++i) {
		int sum = ((num[i] - '0') + (addend[i] - '0') + carry);
		num[i] = sum % 10 + '0';
		carry = sum / 10;
	}

	if(carry)
		num[i++] = carry + '0';
	num[i] = '\0';
	return i;
}

int convert(int num, char *numstr) {
	int ptr = 0;
	while(num) {
		numstr[ptr++] = num % 10 + '0';
		num /= 10;
	}
	numstr[ptr] = '\0';
	return ptr;
}

int main() {
	char *pnum = (char *)malloc(sizeof(char) * 1100);
	char *cnum = (char *)malloc(sizeof(char) * 1100);
	char *temp = (char *)malloc(sizeof(char) * 1100);
	char *t = (char *)malloc(sizeof(char) * 1100);
	convert(1, pnum);
	convert(1, cnum);
	printf("%d\n%d\n", 1, 1);
	int cnt = 2;
	int len = 1;
	while(len < 1000) {
		strcpy(temp, cnum);
		len = add(cnum, pnum);
		strcpy(pnum, temp);
		strcpy(t, cnum);
		strrev(t);
		printf("%s\n", t);
		++cnt;
	}
	printf("%d\n", cnt);
	return 0;
}
