#include <stdlib.h>
#include <stdio.h>

#ifndef __ARRAYUTIL_H_
#define __ARRAYUTIL_H_

typedef struct arr_util{
	int typeSize;
	int length;
	void *base;
}ArrayUtil;

ArrayUtil create(int typeSize, int length);

ArrayUtil resize(ArrayUtil util, int length);

int areEqual(ArrayUtil a, ArrayUtil b);

int findIndex(ArrayUtil util, void* element);

void dispose(ArrayUtil util);

#endif
