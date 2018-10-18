#include <stdio.h>

//function to compute the sum of all natural numbers from 1 to n
int sum_from_one_to(int n) { 
	return n*(n+1)/2; //return the sum via the gaussian sum (easily proven by induction)
}

//function to compute the sum of the squares of all natural numbers from 1 to n
int sum_from_one_to_squared(int n) {
	return n*(n+1)*(2*n+1)/6; //return the sum via formula for sum (easily proven by induction)
}


int main() {
	int n;
	printf("enter a natural number\n");
	do {
	scanf("%i", &n);
	if(n<=0) {
		printf("number has to be at least 1\n");
	}
	} while(n<=0);
	
	printf("the sum of natural numbers up to %i is %i\n", n, sum_from_one_to(n));
	printf("the sum of squares of natural numbers up to %i is %i\n", n, sum_from_one_to_squared(n));
	return 0;
}