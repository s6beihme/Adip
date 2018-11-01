#include <stdio.h>
#include <limits.h>

#define SIZE 8

// very inefficient recursive version
unsigned long long int fibRec(unsigned long int n) {
  if (n==0) {
    return 0;
  } else if (n==1) {
    return 1;
  } else {
    return fibRec(n-1)+fibRec(n-2);
  }
}

// Returns the nth Fibonacci number
unsigned long long int fib(unsigned long int n) {
  // save fib(n-1) and fib(n-2) in variables
  unsigned long long int f1 = 0;
  unsigned long long int f2 = 1;
  for (unsigned long int i = 1; i<n; i++) {
    f2 = f1+f2;
    f1 = f2-f1;
  }
  return f2;
}

// The following part uses "Super Long" numbers, i. e. unsigned int arrays,
// because unsigned long long int cannot store that large values

// adds b to a
void add(unsigned int* a, unsigned int*b) {
  long long int sum[SIZE];
  for (int i=0; i<SIZE; i++) {
    sum[i] = a[i] + b[i];
  }
  for (int i=SIZE-1; i>0; i--) {
    sum[i-1] += sum[i]/(10000);
    sum[i] %= 10000;
  }
  for (int i=0; i<SIZE; i++) {
    a[i] = (unsigned int)sum[i];
  }
}

// copys one int array into the other
void copy(unsigned int* from, unsigned int* to) {
  for (int i=0; i<SIZE; i++) {
    to[i] = from[i];
  }
}

void printSuperLong(unsigned int* a) {
  int onlyNull = 1;
  for (int i=0; i<SIZE; i++) {
    if (a[i] == 0 && onlyNull && i!=SIZE-1) {
      printf("    ");
    } else if (onlyNull) {
      printf("%4d", a[i]);
      onlyNull = 0;
    } else {
      printf("%04d", a[i]);
    }
  }
  printf("\n");
}

void initSuperLong(unsigned int* a) {
  for (int i=0; i<SIZE; i++) {
    a[i] = 0;
  }
}

// Prints the first 50 even Fibonacci numbers
void printEven() {
  // save fib(n-1) and fib(n-2) in variables
  unsigned int f1[SIZE];
  unsigned int f2[SIZE];
  initSuperLong(f1);
  initSuperLong(f2);
  f2[SIZE-1] = 1;
  unsigned int tmp[SIZE];
  unsigned int found = 0;
  for (unsigned int i=0; found<50; i++) {
    if (f1[SIZE-1]%2 == 0) {
      printSuperLong(f1);
      found++;
    }
    copy(f2, tmp);
    add(f2, f1);
    copy(tmp, f1);
  }
}

int main() {
  printf("The first 50 even Fibonacci numbers are:\n");
  printEven();

  return 0;
}
