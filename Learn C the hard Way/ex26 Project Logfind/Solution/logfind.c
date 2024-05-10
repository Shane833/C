#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <glob.h>
//#include <ftw.h>

// Function to use the glob

void list_dir()
{
	glob_t pglob;
	glob("*.h",GLOB_NOSORT,NULL,&pglob);
	for(int i = 0;i < pglob.gl_pathc;i++)
	{
		printf("%s\n",pglob.gl_pathv[i]);
	}

}


int main(int argc,char *argv[])
{
	list_dir();
	printf("Something works!\n");
}