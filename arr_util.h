typedef struct arr_util{
	void *base;
	int typeSize;
	int length;
}ArrayUtil;

ArrayUtil create(int typeSize, int length);
