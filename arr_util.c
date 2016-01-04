#include "arr_util.h"
#include <stdlib.h>

ArrayUtil create(int typeSize, int length){
	ArrayUtil *arr =(ArrayUtil*)malloc(sizeof(ArrayUtil));
	arr->base = NULL;
	arr->length =length;
	arr->typeSize =typeSize;
	return *arr;	
};



