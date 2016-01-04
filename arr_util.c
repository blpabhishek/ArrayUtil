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
	for(int i = 0; i < a.length; i++){
		flag =(a.base[i]==b.base[i])?1:0;
	}
	return flag;
};