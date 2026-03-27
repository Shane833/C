#include <stdio.h>

int main(){
	#if defined (_WIN64)
		printf("OS : Windows 64 bit!\n");
	#elif defined (_WIN32)
		printf("OS : Windows 32 bit!\n");
	#elif defined (__linux__)
		printf("OS : Linux\n");
	#elif defined (__ANDROID__)
		printf("OS : Android\n");
	#elif defined (__APPLE__)
		printf("OS : macOS or iOS\n");
	#elif defined (__unix__)
		printf("OS : Generic Unix-like\n");
	#else
		printf("OS : Unknown!\n");
	#endif

	return 0;
}