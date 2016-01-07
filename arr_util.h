#include <stdlib.h>
#include <stdio.h>

#ifndef __ARRAYUTIL_H_
#define __ARRAYUTIL_H_

typedef int(MatchFunc)(void*,void*);
typedef void(ConvertFunc)(void*,void*,void*);
typedef void(OperationFunc)(void*,void*);
typedef void*(ReducerFunc)(void*,void*,void*);


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

void* findFirst(ArrayUtil util, MatchFunc *match, void* hint);

void* findLast(ArrayUtil util, MatchFunc *match, void* hint);

int count(ArrayUtil util, MatchFunc *match, void* hint);

int isEven(void* hint, void* item);

int isDivisible(void* hint, void* item);

int isSame(void* hint, void* item);

int filter(ArrayUtil util, MatchFunc *match, void* hint, void** destination, int maxItems );

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint);

void forEach(ArrayUtil util, OperationFunc* operation, void* hint);

void mapper(void* hint, void* sourceItem, void* destinationItem);

void multiply(void *hint,void *item);

void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue);

void* sum(void* hint, void* previousItem, void* item);

#endif


