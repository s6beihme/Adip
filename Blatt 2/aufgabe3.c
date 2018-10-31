#include <stdio.h>

// Sums all divisors of a
unsigned long long int sumDivisors(unsigned int a) {
  unsigned long long int sum = 0;
  for (unsigned int i=1; i<a; i++) {
    if (a%i == 0) {
      sum += i;
    }
  }

  return sum;
}

// Checks if a given value a is perfect
int isPerfect(unsigned int a) {
  return sumDivisors(a) == a;
}

// Checks if a given value a is deficient
int isDeficient(unsigned int a) {
  return sumDivisors(a) < a;
}

// prints all perfect numbers up to max
void printPerfectNumbers(unsigned int max) {
  for (unsigned int i=1; i<=max; i++) {
    if (isPerfect(i)) {
      printf("%d\n", i);
    }
  }
}

// Counts all deficient numbers up to max
unsigned int countDeficientNumbers(unsigned int max) {
  unsigned int count = 0;
  for (unsigned int i=1; i<=max; i++) {
    if (isDeficient(i)) {
      count++;
    }
  }

  return count;
}

int main() {
  unsigned int vals[] = {14, 18, 25, 28, 51};
  for (int i=0; i<5; i++) {
    if (isPerfect(vals[i])) {
      printf("%u is perfect.\n", vals[i]);
    } else {
      printf("%u is not perfect.\n", vals[i]);
    }
    if (isDeficient(vals[i])) {
      printf("%u is deficient.\n", vals[i]);
    } else {
      printf("%u is not deficient.\n", vals[i]);
    }

    printf("\n");
  }

  printf("Perfect numbers up to 499:\n");
  printPerfectNumbers(499);
  printf("\n");
  printf("There are %u deficient numbers up to 499.\n", countDeficientNumbers(499));

  return 0;
}
