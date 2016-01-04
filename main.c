#include "arr_util.h"
#include <assert.h>

void test_create(){
	int size =4;
	int length =10;
	ArrayUtil arr = create(size,length);
	assert(arr.length==length);
	assert(arr.typeSize==size);
};

void test_resize(){
	int size =4;
	int length =10;
	int newlength =20;
	ArrayUtil arr = create(size,length);
	arr = resize(arr,newlength);
	assert(arr.length==newlength);

};

void test_areEqual(){
	ArrayUtil a = create(4,10);
	ArrayUtil b = create(4,10);

	assert(areEqual(a,b));

	ArrayUtil arr = create(4,10);
	*((int*)arr.base+0) = 78;
	*((int*)arr.base+1) = 79;

	ArrayUtil arr1 = create(4,10);
	*((int*)arr1.base+0) = 78;
	*((int*)arr1.base+1) = 79;

	assert(areEqual(arr,arr1));
}

void test_findIndex(){
	ArrayUtil arr = create(4,10);
	*((int*)arr.base+0) = 78;
	*((int*)arr.base+1) = 79;
	*((int*)arr.base+2) = 90;
	*((int*)arr.base+3) = 92;


	int var = 92;
	assert(findIndex(arr,&var)==3);
}

void test_areEqual_not(){
	ArrayUtil a = create(4,10);
	ArrayUtil b = create(8,10);

	assert(!areEqual(a,b));

	ArrayUtil arr = create(8,10);
	*((double*)arr.base+0) = 78;
	*((double*)arr.base+1) = 79;

	ArrayUtil arr1 = create(8,10);
	*((double*)arr1.base+0) = 78;
	*((double*)arr1.base+1) = 79;
	*((double*)arr1.base+2) = 80;


	assert(!areEqual(arr,arr1));
}

void run_test(){
	test_create();
	test_resize();
	test_areEqual();
	test_areEqual_not();
	test_findIndex();
	//test_dispose();
}

int main(void){
	run_test();
	return 0;
};