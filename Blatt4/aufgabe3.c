#include <stdio.h>
#include <math.h>

#define PI 3.14159265359d

double factorial(unsigned int n) {
  double res = 1;

  for (unsigned int i=2; i<=n; i++) {
    res *= i;
  }

  return res;
}

// Approximated sinus function
double sinus(double x) {
  double res = 0;
  for (int i=0; i<=5; i++) {
    res += ((i%2 == 0) ? 1 : -1) * pow(x, 2*i+1)/factorial(2*i+1);
  }

  return res;
}

// Approximated cosinus function
double cosinus(double x) {
  double res = 0;
  for (int i=0; i<=5; i++) {
    res += ((i%2 == 0) ? 1 : -1) * pow(x, 2*i)/factorial(2*i);
  }

  return res;
}

// Approximated exp function
double exponential(double x) {
  double res = 0;
  for (int i=0; i<=10; i++) {
    res += pow(x, i)/factorial(i);
  }

  return res;
}

int main() {
  printf("sin(pi/4) = %lf\n", sinus(PI/4));
  printf("cos(pi/4) = %lf\n", cosinus(PI/4));
  printf("sin(pi/2) = %lf\n", sinus(PI/2));
  printf("cos(pi/2) = %lf\n", cosinus(PI/2));
  printf("e = %lf\n", exponential(1));
}
