#include <stdio.h>
int main(){
	int arr[2]; 
	arr[0] = 123;
	arr[1] = 345;
	int results = funct(&arr);
	printf("%d\n", arr[0]);
	return 0;
}

int funct(int *arr){
	printf("%d\n", arr[0]);
	arr[0] = 2001;
	return 0;
}
