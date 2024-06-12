#include <stdio.h>
#include <stdlib.h>

struct Yo{
	int a;
	int b;
};

int main(int argc, char* argv[])
{
	int* p = malloc(sizeof(int));
	*p = 5;
	
	char* c = malloc(sizeof(char));
	*c = 'c';
	
	float* f = malloc(sizeof(float));
	*f = 6.78F;
	
	double* d = malloc(sizeof(double));
	*d = 3.14L;
	
	struct Yo *b = malloc(sizeof(struct Yo));
	*b = (struct Yo){.a = 5, .b = 7};
	
	printf("%p : %d\n",p, *p);
	printf("%p : %c\n",c, *c);
	printf("%p : %f\n",f, *f);
	printf("%p : %lf\n",d, *d);
	printf("%p : %d %d\n",b, (*b).a,b->b);
	return 0;
}