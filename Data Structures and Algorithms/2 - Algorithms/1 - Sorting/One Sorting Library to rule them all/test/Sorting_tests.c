#include <Sorting.h>
#include "minunit.h"
#include <string.h>

// global arrays
static double d_arr[5] = {5.6l,2.4l,1.8l,8.5l,5.3l};
static char** c_arr = {"vini","nish","shiv","laks","anub"}; // Now what is the difference between char** and a char* [], also throws a warning : initialization of 'char **' from incompatible pointer type 'char *'
static char* string[] = {"vini","nish","shiv","laks","anub"};

// These algorithms don't seem to work with double data type I will research and try to understand later
/*
display_double_arr(d_arr, 5);
bool r =  Sort_bubble(d_arr, 5, (Compare)double_increasing_order);
mu_assert(r == true, "Bubble Sort Failed");
display_double_arr(d_arr, 5);

mu_assert(d_arr[0] == 1.8, "Checking if d_arr is sorted");
mu_assert(d_arr[4] == 8.5, "Checking if d_arr is sorted");
*/

int int_increasing_order(const int a, const int b)
{
	return a - b;
}

int float_increasing_order(const float a, const float b)
{
	float result = a - b;
	if(result > 0.0f) return 1; // must  take into 
	else if(result == 0.0f) return 0;
	else return -1;
}

int double_increasing_order(const double a, const double b)
{
	double result = a - b;
	printf("%lf - %lf = %lf\n", a, b, result);
	if(result > 0.0l) return 1; // must take into account all the values between 0.0 to 1.0 
	else return 0;
}

void display_int_arr(int* arr, size_t size)
{
	for(int i = 0;i < size;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void display_float_arr(float* arr, size_t size)
{
	for(int i = 0;i < size;i++){
		printf("%f ", arr[i]);
	}
	printf("\n");
}

void display_double_arr(double* arr, size_t size)
{
	for(int i = 0;i < size;i++){
		printf("%lf ", arr[i]);
	}
	printf("\n");
}

void display_string(char** arr, size_t size)
{
	for(int i = 0;i < size;i++){
		puts(arr[i]);
	}
	printf("\n");
}

char* test_Sort_bubble()
{	
	char* strings[] = {"vini","nish","shiv","laks","anub"};
	int i_arr[5] = {9,3,7,5,4};	
	float f_arr[5] = {5.6f,2.4f,1.8f,8.5f,5.3f};

	bool r = Sort_bubble(i_arr, 5, (Compare)int_increasing_order);
	mu_assert(r == true, "Bubble Sort Failed for i_arr");
	
	mu_assert(i_arr[0] == 3, "Checking if i_arr is sorted");
	mu_assert(i_arr[4] == 9, "Checking if i_arr is sorted");
	
	r =  Sort_bubble(f_arr, 5, (Compare)float_increasing_order);
	mu_assert(r == true, "Bubble Sort Failed for f_arr");
	
	mu_assert(f_arr[0] == 1.8f, "Checking if f_arr is sorted");
	mu_assert(f_arr[4] == 8.5f, "Checking if f_arr is sorted");
	
	r = Sort_bubble(strings, 5, (Compare)strcmp);
    mu_assert(r == true, "Bubble Sort Failed at strings");
	
	mu_assert(strcmp(strings[0], "anub") == 0, "Checking if strings is sorted");
	mu_assert(strcmp(strings[4], "vini") == 0, "Checking if strings is sorted");
	
	return NULL;
}

char* test_Sort_selection()
{
	char* strings[] = {"vini","nish","shiv","laks","anub"};
	int i_arr[5] = {9,3,7,5,4};
	float f_arr[5] = {5.6f,2.4f,1.8f,8.5f,5.3f};
	
	bool r = Sort_selection(i_arr, 5, (Compare)int_increasing_order);
	mu_assert(r == true, "Selection sort failed for i_arr");
	
	mu_assert(i_arr[0] == 3, "Checking if i_arr is sorted");
	mu_assert(i_arr[4] == 9, "Checking if i_arr is sorted");
	
	r =  Sort_selection(f_arr, 5, (Compare)float_increasing_order);
	mu_assert(r == true, "Bubble Sort Failed for f_arr");
	
	mu_assert(f_arr[0] == 1.8f, "Checking if f_arr is sorted");
	mu_assert(f_arr[4] == 8.5f, "Checking if f_arr is sorted");
	
	r = Sort_selection(strings, 5, (Compare)strcmp);
    mu_assert(r == true, "Bubble Sort Failed for strings");
	
	mu_assert(strcmp(strings[0], "anub") == 0, "Checking is strings is sorted");
	mu_assert(strcmp(strings[4], "vini") == 0, "Checking is strings is sorted");
	
	return NULL;
}

char* test_Sort_insertion()
{
	char* strings[] = {"vini","nish","shiv","laks","anub"};
	int i_arr[5] = {9,3,7,5,4};	
	float f_arr[5] = {5.6f,2.4f,1.8f,8.5f,5.3f};
	
	bool r = Sort_insertion(i_arr, 5, (Compare)int_increasing_order);
	mu_assert(r == true, "Selection sort failed for i_arr");

	mu_assert(i_arr[0] == 3, "Checking if i_arr is sorted");
	mu_assert(i_arr[4] == 9, "Checking if i_arr is sorted");
	
	r =  Sort_insertion(f_arr, 5, (Compare)float_increasing_order);
	mu_assert(r == true, "Bubble Sort Failed for f_arr");
	
	mu_assert(f_arr[0] == 1.8f, "Checking if f_arr is sorted");
	mu_assert(f_arr[4] == 8.5f, "Checking if f_arr is sorted");
	
	r = Sort_insertion(strings, 5, (Compare)strcmp);
    mu_assert(r == true, "Bubble Sort Failed for strings");
	
	mu_assert(strcmp(strings[0], "anub") == 0, "Checking is strings is sorted");
	mu_assert(strcmp(strings[4], "vini") == 0, "Checking is strings is sorted");

	return NULL;
}

char* test_Sort_merge()
{

	char* strings[] = {"vini","nish","shiv","laks","anub"};
	int i_arr[5] = {9,3,7,5,4};	
	float f_arr[5] = {5.6f,2.4f,1.8f,8.5f,5.3f};
	
	/*
	bool r = merge_sort(i_arr, 5, sizeof(int), (Compare)int_increasing_order);
	mu_assert(r == true, "Selection sort failed for i_arr");

	mu_assert(i_arr[0] == 3, "Checking if i_arr is sorted");
	mu_assert(i_arr[4] == 9, "Checking if i_arr is sorted");
	*/
	
	
	bool r =  Sort_merge(f_arr, 5,(Compare)float_increasing_order);
	mu_assert(r == true, "Merge Sort Failed for f_arr");
	
	mu_assert(f_arr[0] == 1.8f, "Checking if f_arr is sorted");
	mu_assert(f_arr[4] == 8.5f, "Checking if f_arr is sorted");
	
	/*
	r = merge_sort(strings, 5, (Compare)strcmp);
    mu_assert(r == true, "Bubble Sort Failed for strings");
	
	mu_assert(strcmp(strings[0], "anub") == 0, "Checking is strings is sorted");
	mu_assert(strcmp(strings[4], "vini") == 0, "Checking is strings is sorted");
	*/
	return NULL;
}

char* test_swap()
{
	int i_arr[5] = {9,3,7,5,4};
	swap(i_arr, 0, 1);
	
	mu_assert(i_arr[0] == 3, "Failed value at 0th index not 3");
	mu_assert(i_arr[1] == 9, "Failed value at 1st index not 9");
	
	return NULL;
}

char* all_tests()
{
	mu_suite_start();
	/*
	mu_run_test(test_Sort_bubble);
	mu_run_test(test_Sort_insertion);
	mu_run_test(test_Sort_selection);
	*/
	mu_run_test(test_Sort_merge);
	return NULL;
}

RUN_TESTS(all_tests);


/*
int ch_cmp(const char a, const char b)
{
	//printf("%c - %c = %d\n", a, b, a - b);
	
	return (int)(a - b);
}

int int_increasing_order(const int a, const int b)
{
	printf("%d - %d = %d\n", a, b, a - b);
	return a - b;
}

// Checking if I can use a void pointer to traverse other datatypes (more than usual 4 bytes)
display(void** array, size_t size, size_t element_size)
{
	// void** temp = malloc(element_size);
	// I must create a char pointer to the void array and must it by the size of the data structure
	
	// Got it bitchhhhhhhhhhh
	char* temp = (char*)array;
	for(int i = 0; i < size; i++){
		printf("%lf ",*(double*)temp);
		temp = temp + element_size;
		
	}
}

int main(int argc, char* argv[])
{	
	int i_arr[8] = {9,3,7,5,4,2,1,8};
	double ld_arr[8] = {9.0L,3.0L,7.0L,5.0L,4.0L,2.0L,1.0L,8.0L};	
	//merge_sort(i_arr, 8, (Compare)int_increasing_order);
	display(ld_arr, 8, sizeof(double));
	//display(i_arr, 8, sizeof(int));
	return 0;
}

*/