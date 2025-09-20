#include "tree-utils.c"
#include "tree.c"
#include <assert.h>

int main() {
	u8 *wordlist[] = {"heat", "head", "hopefully", "hope"};
	const uint len[] = {4, 4, 9, 4, 0};

	u8 array[32];
	u8 tmp[32];

	build_branch(wordlist, len, array, 3, 0, 0);
	puts("\n Array built ");
	assert(search_s(array, "heat", tmp));
	assert(search_s(array, "head", tmp));
	assert(search_s(array, "hope", tmp));
	assert(search_s(array, "hopefully", tmp));
	assert(!search_s(array, "hopeless", tmp));
	assert(!search_s(array, "hopes", tmp));
	assert(!search_s(array, "hea", tmp));
	assert(!search_s(array, "heading", tmp));
	assert(!search_s(array, "hello", tmp));
	assert(!search_s(array, "h", tmp));
}

