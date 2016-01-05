#include "arr_util.h"
#include <assert.h>

void test_create(){
	int size =sizeof(int);
	int length =10;
	ArrayUtil arr = create(size,length);
	assert(arr.length==length);
	assert(arr.typeSize==size);
	dispose(arr);
};

void test_resize(){
	int size =4;
	int length =10;
	int newlength =20;
	ArrayUtil arr = create(size,length);
	arr = resize(arr,newlength);
	assert(arr.length==newlength);
	dispose(arr);
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

	dispose(arr);
	dispose(arr1);
	dispose(a);
	dispose(b);
}

void test_findIndex(){
	ArrayUtil arr = create(4,10);
	*((int*)arr.base+0) = 78;
	*((int*)arr.base+1) = 79;
	*((int*)arr.base+2) = 90;
	*((int*)arr.base+3) = 92;


	int var = 92;
	assert(findIndex(arr,&var)==3);


	ArrayUtil darr = create(8,10);
	*((double*)darr.base+0) = 78;
	*((double*)darr.base+1) = 79;


	double dvar = 78;
	assert(findIndex(darr,&dvar)==0);

	dispose(arr);
	dispose(darr);
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

	dispose(arr);
	dispose(arr1);
	dispose(a);
	dispose(b);
};


void test_findFirst_isEven(){
	ArrayUtil util = create(4,10);
	*((int*)util.base+0) = 79;
	*((int*)util.base+1) = 80;

	int actual = *((int*)(findFirst(util,isEven,NULL)));
	int expected = 80;
	assert(actual==expected);
}


void test_findFirst_isEven_not_found(){
	ArrayUtil util = create(4,10);
	*((int*)util.base+0) = 79;
	*((int*)util.base+1) = 89;


	void *val = findFirst(util,isEven,NULL);
	void *expect = NULL;
	
	assert(expect==val);
}

void test_findFirst_isDivisible(){
	ArrayUtil util = create(4,10);

	*((int*)util.base+0) = 79;
	*((int*)util.base+1) = 84;

	int divisor = 4;
	void *hint = &divisor;

	int actual = *((int*)(findFirst(util,isDivisible, hint)));
	int expected = 84;
	assert(actual==expected);
}


void test_count_isEven(){
	ArrayUtil util = create(4,10);

	*((int*)util.base+0) = 79;
	*((int*)util.base+1) = 84;
	*((int*)util.base+2) = 34;
	*((int*)util.base+3) = 89;


	int actual = count(util,isEven,NULL);
	int expected = 2;
	assert(actual==expected);
}

void test_count_isDivisible(){
	ArrayUtil util = create(4,10);

	*((int*)util.base+0) = 9;
	*((int*)util.base+1) = 18;
	*((int*)util.base+2) = 27;
	*((int*)util.base+3) = 89;

	int divisor = 9;
	void *hint = &divisor;
	int actual = count(util,isDivisible,hint);
	int expected = 3;
	assert(actual==expected);
}


// int main(int argc, char const *argv[]){
// 	test_count_isDivisible();
// 	return 0;
// }