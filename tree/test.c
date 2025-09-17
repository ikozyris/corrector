#include "tree-utils.c"
#include "tree.c"
#include <assert.h>

const char *wordlist[] = {"heat", "head", "hope"};
const uint len[] = {4, 4, 4, 4};

int main() {
	build_branch(wordlist, len, 3, 0, 0);
	puts("\n Array built ");
	assert(search(array, "heat"));
	assert(search(array, "head"));
	assert(search(array, "hope"));
	assert(!search(array, "hopefully"));
	assert(!search(array, "hopeless"));
	assert(!search(array, "hopes"));
	assert(!search(array, "hea"));
	assert(!search(array, "heading"));
	assert(!search(array, "hello"));
	assert(!search(array, "h"));
}

