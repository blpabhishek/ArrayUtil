#include "arr_util.h"
#include <string.h>

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
	for(int i = 0; i < util.length; i++)
		if(memcmp(util.base+(i*util.typeSize), element, util.typeSize)==0)
			return i;
	return index;
};

void dispose(ArrayUtil util){
	free(util.base);
};

void* findFirst(ArrayUtil util, MatchFunc *match, void* hint){
	void *item;
	for (int i = 0; i < util.length; ++i){
		item = util.base+(i*util.typeSize);
		if(match(hint,item))
			return item;
	};
	return NULL;
};


int count(ArrayUtil util, MatchFunc *match, void* hint){
	int all_count = 0;
	void *item;
	for (int i = 0; i < util.length; ++i){
		item = util.base+(i*util.typeSize);
		if(match(hint,item))
			all_count++;
	};
	return all_count;
}

int isEven(void* hint, void* item){
	int num = *((int*)item);
	if(num==0) return 0;
	return (num%2==0);
};

int isDivisible(void* hint, void* item){
	int num = *((int*)item);
	int divisor = *((int*)hint);
	if(num==0) return 0;
	return (num%divisor==0);
}

void* findLast(ArrayUtil util, MatchFunc *match, void* hint){
	void *item;
	for (int i = util.length; i > 0; i--){
		item = util.base+(i*util.typeSize);
		if(match(hint,item))
			return item;
	};
	return NULL;
}

int filter(ArrayUtil util, MatchFunc *match, void* hint, void** destination, int maxItems ){
	int all_count = 0;
	void *item ;
	for (int i = 0; i < util.length; i++){
		item = util.base+(i*util.typeSize);
		if(match(hint,item)){
			memcpy(*destination+(util.typeSize*all_count),item,util.typeSize);
			all_count++;
		}
		if(all_count >= maxItems) break;
	};
	return all_count;	
};

int isSame(void* hint, void* item){
	char character =  *((char*)item);
	char criteria =  *((char*)hint);
	return (character==criteria);
}

void mapper(void* hint, void* sourceItem, void* destinationItem){
	*(int*)destinationItem = *(int*)sourceItem + *(int*)hint ;
};

void multiply(void *hint,void *item){
	*(int*)item = *(int*)item * *(int*)hint ;
};

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* hint){
	void *item;
	for (int i = 0; i < source.length; i++){
		item = source.base+(i*source.typeSize);
		convert(hint,item,destination.base+(i*source.typeSize));
	};
};

void forEach(ArrayUtil util, OperationFunc* operation, void* hint){
	void *item;
	for (int i = 0; i < util.length; i++){
		item = util.base+(i*util.typeSize);
		operation(hint,item);
	};
};

void* reduce(ArrayUtil util, ReducerFunc* reducer, void* hint, void* intialValue){
	void *item;
	for (int i = 0; i < util.length; i++){
		item = util.base+(i*util.typeSize);
		intialValue = reducer(hint,intialValue,item);
	};
	return item;
};
 

void* sum(void* hint, void* previousItem, void* item){
	*(int*)item = *(int*)item + *(int*)previousItem ;
	return item;
};


