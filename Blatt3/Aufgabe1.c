#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void initializegenerator() {
	srand(time(NULL));
}
int karteziehen() {
// Sie koennen Zufallszahlen generieren, indem Sie die Funktion rand() aufrufen
// z.B. int zufall = rand();
	return (rand()%9)+2;
}
int main() {
	initializegenerator();
	int val_dealer=karteziehen();
	printf("Dealer has drawn a %i\n", val_dealer);
	int self_card=0;
	int self_val=0; 	
	int draw=0;
	do {
		self_card=karteziehen();
		self_val+=self_card;
			if(self_val>21) {
				printf("your total value is %i, you have lost the game\n", self_val);
				return 0;
			}
		printf("you have drawn a %i\n", self_card);
		printf("your total value now is %i", self_val);
		printf("\n");
		printf("do you want to draw another card?\n");
		scanf("%i", &draw);
	}while(draw==1);
	
	while(val_dealer<=16) {
		val_dealer+=karteziehen();
	}
	if(val_dealer>21) {
		printf("total value of dealer is %i, You Win!!", val_dealer);
		return 0;
	}
	if(val_dealer>=self_val) {
		printf("total value of dealer is %i, You Lose!!", val_dealer);
	}
	else printf("total value of dealer is %i, You Win!!", val_dealer);
	// Code fuer den Spielablauf
return 0;
}