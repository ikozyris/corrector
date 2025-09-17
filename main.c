#include <stdio.h>
#include "table-utils.c"
//#include "wordlist.h"

char weights[25][25];

int diff2words(const char *a, const char *b) {
	int res = 0;
	while (*a && *b) {
		res += weights[*a - 97][*b - 97];
		a++; b++;
	}
	return res;
}

int main() {
	create_table(weights);
	int res = diff2words("hello", "helll");
	printf("%d\n", res);
	return 0;
}
