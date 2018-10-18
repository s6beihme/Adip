#include <stdio.h>
#include <stdlib.h>

//function to check weather given integer is prime (only to be used with small numbers)
int prime_test(int n) {
	if(n<0) { //check if given integer is negative
		printf("number has to be positive\n");
		return 0;
	}
	
	if(n<2) return 0; //0 and 1 are not prime
	
	int* array = malloc((n+1)*sizeof(int)); //create a boolean array representing each number from 0 to n

	for(int i=0; i<=n; i++) {
		array[i]=1;
	}
	
	for(int i=2; i*i<=n; i++) { //go through numbers from 2 to sqrareroot of namespace
		if(array[i]==1) { //if number is still marked as prime
			for(int j=2; j*i<=n; j++) {
				array[i*j]=0; //mark all multiples of number as not prime
			}
		}
	}
	int result=array[n]; //store result
	free(array); //delete the array
	return result;
}




int main() {
	int n;
	printf("enter number you want to check\n");
	scanf("%i", &n);
	
	if(prime_test(n)==1) printf("%i is prime\n", n);
	else printf("%i is not prime\n", n);
	return 0;
}