#include "../main.h"

// to avoid offsets larger than characters (133)
// 230 < code < 256
#define ascii2code(ch) (ch + 133)
#define code2ascii(code) (code - 133)
#define iscode(code) (code >= ascii2code('a'))

u8 search(const u8 *ar, const u8 *word)
{
	uint arp = 0, wp = 0;
	while (ar[arp] == word[wp]) {
		wp++;
		if (iscode(ar[arp + 1]))
			arp++;
		else
			for (uint i = 1; i <= ar[arp + 1]; ++i)
				if (ar[ar[arp + i] + i + arp] == word[wp]) {
					arp += ar[arp + i] + i;
					break;
				}

		if (word[wp] + ar[arp + 1] <= 1) // both ended
			return true;
		if (word[wp] == 0 || ar[arp] == 0) // basically a xor
			return false;
	}
	return false;
}

u8 search_s(const u8 *ar, const char *word, u8 *tmp) 
{
	const u8 *cword = tmp;
	while (*word) {
		*tmp = ascii2code(*word);
		++tmp; ++word;
	}
	return search(ar, cword);
}
