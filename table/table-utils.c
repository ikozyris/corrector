#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *rows[] = {
	"qwertyuiop",
	"asdfghjkl",
	"zxcvbnm"
};

uint get_dist(char a, char b) {
	if (a == b) return 0;
	int ax = -1, ay = -1, bx = -1, by = -1;
	for (uint y = 0; y < 3; ++y) {
		for (uint x = 0; rows[y][x] != '\0'; ++x) {
			if (rows[y][x] == a) {
				ax = x;
				ay = y;
			} else if (rows[y][x] == b) {
				bx = x;
				by = y;
			}
		}
	}
	uint res = abs(ax - bx) + abs(ay - by);
	return res > 4 ? 9 : 1 + res;
}

void create_table(char table[25][25]) {
	for (uint i = 'a'; i <= 'z'; ++i)
		for (uint j = 'a'; j <= 'z'; ++j)
			table[i - 97][j - 97] = get_dist(i, j);
}
