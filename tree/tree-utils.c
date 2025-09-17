#include "../main.h"

#define ischar(ch) ch >= 'a'

u8 search(char *ar, char *word)
{
	uint arp = 0, wp = 0;
	while (ar[arp] == word[wp]) {
		wp++;
		if (ischar(ar[arp + 1]))
			arp++;
		else
			for (uint i = 1; i <= ar[arp + 1]; ++i)
				if (ar[ar[arp + i] + i + arp] == word[wp]) {
					arp += ar[arp + i] + i;
					break;
				}

		if (word[wp] + ar[arp + 1] == 0) // both 0
			return true;
		if (word[wp] == 0 || ar[arp] == 0) // basically a xor
			return false;
	}
	return false;
}
