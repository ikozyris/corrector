#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char *rows[] = {
	"qwertyuiop",
	"asdfghjkl",
	"zxcvbnm"
};

int get_dist(char a, char b) {
	if (a == b) return 0;
	int ax = -1, ay = -1, bx = -1, by = -1;
	for (int y = 0; y < 3; ++y) {
		for (int x = 0; rows[y][x] != '\0'; ++x) {
			if (rows[y][x] == a) {
				ax = x;
				ay = y;
			} else if (rows[y][x] == b) {
				bx = x;
				by = y;
			}
		}
	}
	int res = abs(ax - bx) + abs(ay - by);
	return res > 4 ? 9 : 1 + res;
}

/*void convert2act(char orig[27][27], char dest[25][25]) {
	for (int i = 1; i <= 25; ++i) {
		for (int j = 1; j <= 25; ++j) {
			char res;
			if (orig[i][j] == '.')
				res = 9;
			else if (orig[i][j] == '`')
				res = 0;
			else
				res = orig[i][j] - 48;
			dest[i - 1][j - 1] = res;
		}
		//memcpy(dest[i - 1], orig[i] + 1, 25);
	}
}*/

void create_table(char table[25][25]) {
	for (int i = 'a'; i <= 'z'; ++i)
		for (int j = 'a'; j <= 'z'; ++j)
			table[i - 97][j - 97] = get_dist(i, j);
}
