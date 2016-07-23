#include <stdio.h>
#include "vector.h"
#include "ADTDefs.h"

void test1();
void test2();
void test3();
void test4();
void test5();
void test6();
void test7();

int main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();

	return 0;
}

void test1() //create with 0, 0
{
	Vector* vec;
	vec = VectorCreate(0,0);
	if(NULL == vec)
	{
		printf("Test1...................OK\n");
	}
	else
	{
		printf("Test1...................FAIL\n");
	}
}

void test2() //create with 0, 10
{
	Vector* vec = NULL;
	vec = VectorCreate(0, 10);
	if(NULL != vec)
	{
		printf("Test2...................OK\n");
	}
	else
	{
		printf("Test2...................FAIL\n");
	}
	
	VectorDestroy(vec);
}

void test3() //create with 10, 0
{
	Vector* vec = NULL;
	vec = VectorCreate(10, 0);
	if(NULL != vec)
	{
		printf("Test3...................OK\n");
	}
	else
	{
		printf("Test3...................FAIL\n");
	}
	
	VectorDestroy(vec);
}

void test4() //create with 10, 0 and try to add 15 values
{
	Vector* vec = NULL;
	int i;
	vec = VectorCreate(10, 0);
	for(i = 0; i < 15; i++)
	{
		if(VectorAdd(vec, i*10) == ERR_OVERFLOW && i == 10)
		{
			printf("Test4...................OK\n");	
			VectorDestroy(vec);
			return;
		}
	}
	printf("Test4...................FAIL\n");
}

void test5() //try to Delete from empty vector
{
	int item;
	Vector* vec = NULL;
	vec = VectorCreate(10, 10);
	if(VectorDelete(vec, &item) == ERR_UNDERFLOW)
	{
		printf("Test5...................OK\n");	
	}
	else
	{
		printf("Test4...................FAIL\n");
	}
	VectorDestroy(vec);
}

void test6() //add, delete values
{
	Vector* vec;
	int i;
	int item;
	size_t num; 
	int values[] = {1, 3, 4, 5, 6, 7, 4, 99, 23, 55};

	vec = VectorCreate(10,10);

	VectorItemsNum(vec, &num);
	if(num != 0)
	{
		printf("Test6...................FAIL\n");
		return;
	}

	for(i = 0; i < 10; i++)	
	{
		if((VectorAdd(vec, values[i])) != ERR_OK)
		{
			printf("Test6...................FAIL\n");
			return;
		}	

		VectorItemsNum(vec, &num);
		if(num != i + 1)
		{
			printf("Test6...................FAIL\n");
			return;
		}		
	
	}


	for(i = 0; i < 10; i++)	
	{
		VectorDelete(vec, &item);
		if(values[9 - i] != item)
		{
			printf("Test6...................FAIL\n");
			return;
		}
	}

	VectorDestroy(vec);
	VectorDestroy(vec);

	printf("Test6...................OK\n");
}

void test7() //add, set and get values
{
	Vector* vec;
	int i;
	int item; 
	size_t num; 
	int values[] = {1, 3, 4, 5, 6, 7, 4, 99, 23, 55};

	vec = VectorCreate(10,10);

	VectorItemsNum(vec, &num);
	if(num != 0)
	{
		printf("Test7...................FAIL\n");
		return;
	}

	for(i = 0; i < 10; i++)	
	{
		if((VectorAdd(vec, i)) != ERR_OK)
		{
			printf("Test7...................FAIL\n");
			return;
		}	

		VectorItemsNum(vec, &num);
		if(num != i + 1)
		{
			printf("Test7...................FAIL\n");
			return;
		}		
	
	}


	for(i = 0; i < 10; i++)	
	{
		VectorSet(vec, i, values[i]);
	}

	for(i = 0; i < 10; i++)	
	{
		VectorGet(vec, i, &item);
		if(values[i] != item)
		{
			printf("Test7...................FAIL\n");
			return;
		}
	}

	VectorDestroy(vec);
	VectorDestroy(vec);

	printf("Test7...................OK\n");
}























