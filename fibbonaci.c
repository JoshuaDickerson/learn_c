#include <stdio.h>
#include <getopt.h>
int main(int argc, char **argv){
	printf("working\n");

	int maxInt; 
	maxInt = (int) pow(2, (sizeof(int)*8));

	// long ar = getopt_long(argc, arg[0]);
	int c;
	int numDigits;

	// the string ":a:bc" tells the compiler that options a and options b take an argument, but option c does not
	// http://linuxprograms.wordpress.com/2012/06/22/c-getopt-example/
	while((c = getopt(argc, argv, ":a:bc")) != -1){
		switch(c){
			case('a'):
				numDigits = atoi(optarg);
				break;
			case('b'):
				printf("california\n");
				break;
			case('d'):
				printf("deleware\n");
				break;
		}
	}
	int values[numDigits];
	values[0] = 0;
	values[1] = 1;

	long results = fibbonaci(2, &values, numDigits);
	int ii=0;

	for(ii; ii<(sizeof(values)/sizeof(values[0])); ii++){
		printf("%i\n", values[ii]);
	}

	return 0;

}

int fibbonaci(int n, int* val, int numDigits){
	if(n == numDigits){
		return 0;
	}else if((val[n-1]+val[n-2]) < 0){
		printf("We reached the limit of int, using long\n");
		printf("numdigits: %i\n", numDigits);
		printf("n: %i\n", n);
		// we have reached the limit of int, we need to allocate a new long array that is the size of 
		// n - the current size of the val array plus the previous 2 ints (to get the ball rolling here)
		long *longVal = malloc (sizeof (long) * ((numDigits - n) + 2));
		longVal[0] = (long) val[n-2];
		longVal[1] = (long) val[n-1];
		int x = 2;
		return longFibbonaci(x, longVal, numDigits-n);
	}else{
		printf("Std fibonnaci\n");
		val[n] = val[n-1]+val[n-2];
		return fibbonaci(n+1, val, numDigits);
	}
}

int longFibbonaci(int x, long* longVal, int numDigits){
	printf("in long fib\n");
	if(x == numDigits){
		return 0;
	}else{
		longVal[x] = longVal[x-1]+longVal[x-2];
		return longFibbonaci(x+1, longVal, numDigits);
	}
}