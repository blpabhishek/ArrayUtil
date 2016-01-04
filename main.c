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
}

void test_areEqual_not(){
	ArrayUtil a = create(4,10);
	ArrayUtil b = create(8,10);
	assert(!areEqual(a,b));
}

void run_test(){
	test_create();
	test_resize();
	test_areEqual();
	test_areEqual_not();
}

int main(void){
	run_test();
	ArrayUtil arr = create(4,10);
	int a = 23;	
	int b = 33;
	arr.base[0] = &a;
	arr.base[1] = &b;
	printf("%d\n",*(int *)arr.base[0]);
	printf("%d\n",*(int *)arr.base[1]);

	ArrayUtil arr1 = create(1,10);
	char a1= 65;
	char b1 = 68;
	arr1.base[0] = &a1;
	arr1.base[1] = &b1;
	printf("%c\n",*(char *)arr1.base[0]);
	printf("%c\n",*(char *)arr1.base[1]);

	return 0;
};