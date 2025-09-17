// reversible double hash function
void rdhash(char *word, unsigned *hash1, unsigned *hash2)
{
	unsigned cnt = 0;
	while (*word) {
		*hash1 += *word * *word;
		*hash2 += *word * cnt;
		++cnt; ++word;
	}
}
