#include "../main.h"

ulong count_unique(const char *words[], const uint *lenghts, uint n, uint from)
{
	char target = words[0][from];
	uint end = 0;
	uint pr_end = 0;

	// find count of all matches
	for (uint i = 0; i < n; ++i)
		if (lenghts[i] > from && words[i][from] == target)
			end = i;

	// extend len if possible
	uint cur = from;
	do {
		target = words[0][cur + 1];
		for (uint i = 0; i <= end; ++i) {
			if (lenghts[i] < cur + 1 || words[i][cur + 1] != target)
				goto a;
		}
		cur++;
	} while (from != cur);
a:
	target = words[0][cur];

	// count unique 
	u8 seen[256] = {};
	uint unique = 0;
	for (uint i = 0; i <= end; ++i) {
		if (lenghts[i] < cur)
			continue;
		unsigned char ch = words[i][cur + 1];
		if (!seen[ch] && ch != 0)
			unique++;
		seen[ch] = 1;
	}
	return create_pair(cur + 1 - from, unique);
}

ulong build_branch(const char *words[], const uint *lens, u8 *out, uint n, uint ari, uint wdi) 
{
	ulong lc_pair = count_unique(words, lens, n, wdi);
	uint len, cnt, done = 0;
	extract_pair(lc_pair, &len, &cnt);
	uint sum_ari = 0;
	// workaround for count_unique bug
	if (words[0][len + wdi - 1] == 0) { // end of word
		len--; // counted trailing 0
		cnt = 0;
		done++;
		sum_ari = 1;
	}
	memcpy(out + ari, words[0] + wdi, len);
	out[ari + len] = cnt;
	sum_ari += ari + len + cnt;
	for (uint i = 0; i < cnt; ++i) {
		out[ari + len + i] = sum_ari - ari - len - i;
		ulong ari_done_pair = build_branch(words + done, lens + done, out, n - done, sum_ari, wdi + len);
		uint tmp_done;
		extract_pair(ari_done_pair, &sum_ari, &tmp_done);
		done += tmp_done;
	}
	return create_pair(sum_ari, done); // where we stopped
}

