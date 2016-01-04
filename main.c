#include "arr_util.h"
#include <stdio.h>
#include <assert.h>

void test_create(ArrayUtil arr,int length,int size){
	assert(arr.length==length);
	assert(arr.typeSize==size);
};

int main(void){
	int size =4;
	int length =10;
	ArrayUtil arr = create(size,length);
	test_create(arr,length,size);
	return 0;
};