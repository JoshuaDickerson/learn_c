#include <stdio.h>
#include <math.h>
main(){
	long sizeInt; 

	sizeInt = (long)pow(2, (sizeof(long)*8));
	printf("%ld\n", sizeInt);
}