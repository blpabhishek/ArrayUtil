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


void test_findLast_isDivisible(){
	ArrayUtil util = create(4,10);

	*((int*)util.base+0) = 79;
	*((int*)util.base+1) = 84;
	*((int*)util.base+2) = 69;
	*((int*)util.base+3) = 44;
	*((int*)util.base+4) = 64;


	int divisor = 4;
	void *hint = &divisor;

	int actual = *((int*)(findLast(util,isDivisible, hint)));
	int expected = 64;
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
};
void test_filter_isDivisible(){
	int val = 65;
	ArrayUtil util = create(sizeof(int),10);
	int *base = (int *)util.base;
	for (int i = 0; i < util.length; ++i,val++)
		base[i] = val;

	int maxItems = 8;
	ArrayUtil destination = create(sizeof(int),maxItems);

	int divisor = 2;
	void *hint = &divisor;
	int count = filter(util,isDivisible,hint,&(destination.base),maxItems);
	assert(5 == count);
	val = 66;
	for (int i = 0; i < 3; ++i,val=val+2){
		assert(val == *((int*)destination.base+i));
	}
};


void test_filter_isSame(){
	int val = 65;
	ArrayUtil util = create(sizeof(char),10);
	char *base = (char *)util.base;
	for (int i = 0; i < util.length; ++i,val++)
		base[i] = val;

	int maxItems = 5;
	ArrayUtil destination = create(sizeof(int),maxItems);

	int search = 66;
	void *hint = &search;
	int count = filter(util,isSame,hint,&(destination.base),maxItems);
	assert(1 == count);
	assert(66 == *((char*)destination.base+0));
	assert(destination.length==maxItems);
};

void test_map_mapper(){
	ArrayUtil source = create(sizeof(int),10);
	ArrayUtil destination = create(sizeof(int),10);
	int val =65;
	int *base = (int *)source.base;
	for (int i = 0; i < source.length; ++i,val++)
		base[i] = val;
	int no = 2;
	int *hint = &no;
	map(source,destination,mapper,hint);
	val = 67;
	for (int i = 0; i < 3; ++i,val++){
		assert(val== *((int*)destination.base+i));
	}
};


void test_forEach_operation(){
	ArrayUtil array = create(sizeof(int),10);
	int val =5;
	int *base = (int *)array.base;
	for (int i = 0; i < array.length; ++i,val++)
		base[i] = val;
	int no = 2;
	int *hint = &no;
	forEach(array,multiply,hint);

	assert(10== *((int*)array.base+0));
	assert(12== *((int*)array.base+1));
	assert(14== *((int*)array.base+2));
};

void test_reduce_sum(){
	ArrayUtil array = create(sizeof(int),10);
	int val =5;
	int *base = (int *)array.base;
	for (int i = 0; i < array.length; ++i,val++)
		base[i] = val;
	int iniail_val = 0;
	void *red = reduce(array,sum,NULL,&iniail_val);
	assert(*((int *)red) == 95);
}
