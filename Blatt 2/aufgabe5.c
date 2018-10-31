#include <stdio.h>

// n+1 Funktionsaufrufe, also für n=17 18 Funktionsaufrufe
double pot1(double a, unsigned int n) {
  if (n==0) {
    return 1;
  } else {
    return a*pot1(a, n-1);
  }
}

// [log(n)]+2 Funktionsaufrufe, wobei [...] die untere Gaußklammer sei,
// also für n=17 6 Funktionsaufrufe
double pot2(double a, unsigned int n) {
  if (n==0) {
    return 1;
  } else if (n%2 == 0) {
    double b = pot2(a, n/2);
    return b*b;
  } else {
    double b = pot2(a, n/2);
    return a*b*b;
  }
}

int main() {
  printf("%lf\n", pot1(2, 17));
  printf("%lf\n", pot2(2, 17));

  return 0;
}
