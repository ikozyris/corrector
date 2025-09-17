#include <stdio.h>
#include "main.h"
#include "table/table-utils.c"
#include "tree/tree.c"
#include "tree-utils.c"

char weights[25][25];

uint diff2words(const char *a, const char *b) {
	int res = 0;
	while (*a && *b) {
		res += weights[*a - 97][*b - 97];
		a++; b++;
	}
	return res;
}

int main() {
	create_table(weights);
	uint res = diff2words("hello", "helll");
	printf("%u\n", res);
	return 0;
}
