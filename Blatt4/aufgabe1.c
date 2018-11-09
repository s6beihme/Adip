#include <stdio.h>

unsigned int factorial(unsigned int n) {
  unsigned int res = 1;

  for (unsigned int i=2; i<=n; i++) {
    res *= i;
  }

  return res;
}

unsigned int binomial(unsigned int n, unsigned int k) {
  return factorial(n)/factorial(k)/factorial(n-k);
}

unsigned int lotto(unsigned int n, unsigned int k) {
  return factorial(n)/factorial(n-k);
}
