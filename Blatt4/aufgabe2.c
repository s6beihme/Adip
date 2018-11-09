#include <stdio.h>

// Gibt den Nachfolger des ¨ubergebenen Wertes zur¨uck
int succ(int x) {
  return ++x;
}

// Gibt den Vorg¨anger des ¨ubergebenen Wertes zur¨uck
int pre(int x) {
  return --x;
}

// Adds two numbers
int add(int x, int y) {
  if (y>0) {
    return add(succ(x), pre(y));
  } else if (y<0) {
    return add(pre(x), succ(y));
  } else {
    return x;
  }
}

// Subtracts two numbers
int sub(int x, unsigned int y) {
  if (y>0) {
    return sub(pre(x), pre(y));
  } else {
    return x;
  }
}

// Multiplies two numbers
int mult(int x, unsigned int y) {
  if (y>1) {
    return add(x, mult(x, pre(y)));
  } else if (y==1) {
    return x;
  } else {
    return 0;
  }
}

int main() {
  printf("2 + 0 = %d\n", add(2, 0));
  printf("2 - 0 = %d\n", sub (2, 0));
  printf("2 x 0 = %d\n", mult(2, 0));
  printf("\n");
  printf("-3 + 2 = %d\n", add(-2, 3));
  printf("-3 - 2 = %d\n", sub(-2, 3));
  printf("-3 * 2 = %d\n", mult(-2, 3));

  return 0;
}
