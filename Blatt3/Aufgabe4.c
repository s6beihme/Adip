#include <stdio.h>

//exact result: 0.002/63

float alg_sum(float* a, int n) {
	float S=0;
	float D=0;
	float Sa=0;
	for(int i=0; i<n; i++) {
		Sa=S;
		S+=a[i];
		D+=a[i]-(S-Sa);
	}
	return S+D;
}

double alg_sum2(double* a, int n) {
	double S=0;
	double D=0;
	double Sa=0;
	for(int i=0; i<n; i++) {
		Sa=S;
		S+=a[i];
		D+=a[i]-(S-Sa);
	}
	return S+D;
}

int main() {
	float a[5]={10000, -1.0e-3/9, 25.0e2, 1.0e-3/7, -12.5e3};
	float sum=0;
	for(int i=0; i<5; i++) {
		sum+=a[i];
	}
	printf("sum as float: %f", sum);
	
	double a2[5]={10000, -1.0e-3/9, 25.0e2, 1.0e-3/7, -12.5e3};
	double sum2=0;
	for(int i=0; i<5; i++) {
		sum2+=a2[i];
	}
	printf("sum as double: %f\n", sum);
	
	printf("with alg_sum the sum is %f\n", alg_sum(a, 5));
	printf("alg_sum yields better result, because the 'mistakes' the computer makes are stored in D and then negated (for proof see Alma1)\n");
	
	printf("with alg_sum as double: %lf", alg_sum2(a2,5));
}