#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Inits the random number generator with the current time as seed
void initRandom() {
  srand(time(NULL));
  rand();
}

int main() {
  int coins[] = {50, 20, 10, 5, 2, 1};

  initRandom();

  int amount = rand();
  int paid = 0;
  printf("Zu zahlen: %d Cent\n", amount);
  do {
    printf("Gib einen groesseren Betrag ein:\n");
    scanf("%d", &paid);
  } while (paid < amount);

  printf("\n\nWechselgeld:\n");

  int diff = paid-amount;
  for (int i = 0; i<6; i++) {
    if (diff/coins[i] != 0) {
      printf("%d x %d Cent\n", diff/coins[i], coins[i]);
    }
    diff %= coins[i];
  }
}
