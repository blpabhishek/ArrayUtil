#include "arr_util.h"

ArrayUtil create(int typeSize, int length){
	ArrayUtil util = *(ArrayUtil *)malloc(sizeof(ArrayUtil));
	util.base = calloc(length,typeSize);
	util.length =length;
	util.typeSize =typeSize;
	return util;	
};

ArrayUtil resize(ArrayUtil util, int length) {
	util.base = realloc(util.base,length);
	util.length = length;
	return util;
};

int areEqual(ArrayUtil a, ArrayUtil b){
	int flag = 0;
	if(!(a.length==b.length))  return 0;
	if(!(a.typeSize==b.typeSize))  return 0;
	for(int i = 0; i < a.length *a.typeSize; i++){
		if(*((unsigned char*)a.base+i) == *((unsigned char*)b.base+i)){
			flag =1;
		}
		else{
			flag =0;
			break;
		}
	}
	return flag;
};

int findIndex(ArrayUtil util, void* element){
	int index = -1;
	for(int i = 0; i < util.length * util.typeSize; i++){
		if(*((unsigned char*)util.base+i)==*((unsigned char*)element)){
			index = i/util.typeSize;
			break;
		}
	}
	return index;
};

void dispose(ArrayUtil util){
	free(util.base);
}

