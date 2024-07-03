#include <PQueue.h>
#include "minunit.h"
#include <string.h>

int intCompare(const int *a, const int *b )
{
	return *a > *b ? 1 : 0;
}

int floatCompare(const float *a, const float *b)
{
	return *a > *b ? 1 : 0;
}

int array[6] = {3,4,5,6,7,8};	
float f_arr[9] = {4.8f, 1.6f, 2.9f, 8.4f, 10.1f, 9.2f, 15.8f, 13.7f, 3.2f};
char* c_arr[5] = {"vini","anub", "laks", "shiv", "bhaw"};

char* creation_test()
{
	PQueue* pq = PQueue_Create(1, (PQ_Compare)intCompare);
	mu_assert(pq != NULL,"Failed to create the PQueue!");
	
	PQueue_Destroy(pq);
		
	return NULL;
}

char* array_test()
{
	PQueue* iq = PQueue_CreateFromStaticArray(array, 6, (PQ_Compare)intCompare);
	mu_assert(iq != NULL, "Failed to create the PQueue from array!");
	mu_assert(*(int*)iq->array[0] == 8, "Bubble up function failed!");
	
	PQueue* fq = PQueue_CreateFromStaticArray(f_arr, sizeof(f_arr)/sizeof(f_arr[0]), (PQ_Compare)floatCompare);
	mu_assert(fq != NULL, "Failed to create the PQueue from float array!");
	mu_assert(*(float*)fq->array[0] == 15.8f, "Bubble up function failed!");
	
	PQueue* cq = PQueue_CreateFromArray(c_arr, sizeof(c_arr)/sizeof(c_arr[0]), (PQ_Compare)strcmp);
	mu_assert(cq != NULL, "Failed to create the PQueue from character array!");
	
	/*
	for(int i = 0;i < PQueue_Size(cq);i++){
		printf("%s ", (char*)PQueue_Get(cq, i));
	}
	*/
	/*float* fp = NULL;
	PQueue* fq = PQueue_Create(sizeof(f_arr)/sizeof(f_arr[0]), (PQ_Compare)floatCompare);
	mu_assert(fq != NULL, "Failed t o create the PQueue!");
		
	for(int i = 0;i  < sizeof(f_arr)/sizeof(f_arr[0]);i++){
		fp = &f_arr[i];
		PQueue_Enqueue(fq, fp);
	}
	
	for(int i = 0;i < PQueue_Size(fq);i++){
		printf("%f ", *(float*)PQueue_Get(fq, i));
	}
	*/
	
	PQueue_Destroy(iq);
	PQueue_Destroy(fq);
	PQueue_Destroy(cq);
	
	return NULL;
}

char* removal_test()
{
	PQueue* iq = PQueue_CreateFromStaticArray(array, 6, (PQ_Compare)intCompare);
	mu_assert(iq != NULL, "Failed to create the PQueue from array!");
	
	int a = *(int*)PQueue_Dequeue(iq);
	mu_assert(a == 8, "Removal Wrong!");
	
	mu_assert(*(int*)iq->array[0] == 7, "Bubble down function failed!");
	
	
	PQueue* fq = PQueue_CreateFromStaticArray(f_arr, sizeof(f_arr)/sizeof(f_arr[0]), (PQ_Compare)floatCompare);
	mu_assert(fq != NULL, "Failed to create the PQueue from float array!");
	
	float b = *(float*)PQueue_Dequeue(fq);
	mu_assert(b == 15.8f, "Removal Wrong!");
	
	mu_assert(*(float*)fq->array[0] == 13.7f, "Bubble down function failed!");
	
	
	PQueue* cq = PQueue_CreateFromArray(c_arr, sizeof(c_arr)/sizeof(c_arr[0]), (PQ_Compare)strcmp);
	mu_assert(cq != NULL, "Failed to create the PQueue from character array!");
	
	char* c = (char*)PQueue_Dequeue(cq);
	mu_assert(strcmp(c, "vini") == 0, "Removal Wrong!");
	
	mu_assert(strcmp((char*)cq->array[0], "shiv") == 0, "Bubblde down function failed!");
	
	/*
	for(int i = 0;i < PQueue_Size(cq);i++){
		printf("%s ", (char*)PQueue_Get(cq, i));
	}
	*/
	
	PQueue_Destroy(iq);
	PQueue_Destroy(fq);
	PQueue_Destroy(cq);
	
	return NULL;
}

char* all_tests()
{
	mu_suite_start();
	mu_run_test(creation_test);
	mu_run_test(array_test);
	mu_run_test(removal_test);
	
	return NULL;
}

RUN_TESTS(all_tests);