/* Integral */
#include <stdio.h>
#include <math.h>

double f(double x) {
  return 0.4*pow(x, 5)+pow(x, 3);
}

double integrate(double (*fct)(double), double left, double right, double stepsize) {
  // Trapezoidal rule
  double sum=0;
  for (int i=0; i*stepsize < right-left; i++) {
    sum += fct(left+i*stepsize)+fct(left+(i+1)*stepsize);
  }
  return sum*stepsize/2;
}

int main() {
  printf("Integral von Sinus [0, pi]: %lf\n", integrate(&sin, 0, M_PI, 0.0001));
  printf("Integral von Sinus [0, 2pi]: %lf\n", integrate(&sin, 0, 2*M_PI, 0.0001));
  printf("Integral von f(x)=0.4x^5+x^3 [0, 3]: %lf\n", integrate(&f, 0, 3, 0.0001));

  return 0;
}
