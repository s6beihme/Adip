#include <stdio.h>
#include <math.h>

int main() {
  const unsigned int max = 100;

  for (unsigned int a = 1; a <= max; a++) {
    for (unsigned int b = a+1; b <= max; b++) {
      unsigned int d = a*a + b*b;
      unsigned int c = lround(sqrt(d));
      if (d == c*c) {
        printf("(%u, %u, %u)\n", a, b, c);
      }
    }
  }
}
