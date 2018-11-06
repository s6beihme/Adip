#include <stdio.h>

double arith_mean(double* array, int n) {
	double sum =0;
	for(int i=0; i<n; i++) {
		sum+=array[i];
	}
	return sum/n;
}

double sampl_var(double* array, int n, double x_) {
	double sum=0;
	for(int i=0; i<n; i++) {
		sum+=(array[i]-x_)*(array[i]-x_);
	}
	return sum/(n-1);
}

int main() {
	
	int n=0;
	
	printf("how many entries does sampling have (number has to be >1) ?\n");
	do {
		scanf("%i", &n);
	} while(n<2);
	
	double array[n];
	printf("please enter each value (has to be double) and press enter after each one\n");
	for(int i=0; i<n; i++) {
		scanf("%lf", &array[i]);
	}
	
	double x_= arith_mean(array,n);
	printf("\nthe arithmetrc mean of sampling is %lf\n", x_);
	printf("the samplin varince is %lf", sampl_var(array, n, x_));
	return 0;
}