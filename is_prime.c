#include <stdio.h>
#include <getopt.h>

int main(int argc, char **argv){
	int c;
	int testNum;
	int isPrime = 0;
	int ii = 2;
	int maxInt; 

	maxInt = (int) pow(2, (sizeof(int)*8));
	
	while((c = getopt(argc, argv, ":n:")) != -1){
		switch(c){
			case('n'):
				testNum = atoi(optarg);
				break;
		}
	}

	for(ii; ii<testNum; ii++){
		if((testNum % ii == 0) && testPrime(ii) == 1){
			printf("%d\n", ii);
		}
	}
	// for(ii; ii<10000; ii++){
	// 	isPrime = testPrime(ii);
	// 	if(isPrime == 1){
	// 		printf("%d\n", ii);
	// 	}
	// }

	isPrime = testPrime(testNum);
	if(isPrime == 1){
		printf("yes, the number is prime\n");
	}else{
		printf("no, the number is not prime\n");
	}

}
// int main(){
// 	int c;
// 	int testNum;
// 	int isPrime = 0;
// 	int ii = 2;
	
// 	// while((c = getopt(argc, argv, ":n:")) != -1){
// 	// 	switch(c){
// 	// 		case('n'):
// 	// 			testNum = atoi(optarg);
// 	// 			break;
// 	// 	}
// 	// }

	

// }

int testPrime(int num){
	int primes[20];
	int ii = 2;
	for(ii; ii<num; ii++){
		if(num % ii == 0){
			return 0;
		}
	}
	return 1;
}