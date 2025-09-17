#pragma once
#include <stdlib.h>

typedef char u8;
typedef unsigned uint;
typedef unsigned long ulong;

ulong create_pair(uint a, uint b)
{
	return ((ulong)a | (ulong)b << 32);
}

void extract_pair(ulong pair, uint *a, uint *b)
{
	*a = pair;
	*b = pair >> 32;
}

typedef struct dynarray {
	uint cpt;
	uint len;
	ulong arr[128];
} dyna;
	
void reserve(dyna *a, uint size)
{
	//a->arr = (uint*)realloc(a->arr, size);
	a->cpt = size;
}

void append(dyna *a, ulong elem)
{
	if (a->len + 1 < a->cpt)
		reserve(a, a->cpt *= 2);
	a->arr[a->len++] = elem;
}
