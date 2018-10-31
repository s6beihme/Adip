#include <stdio.h>

int main(){
  char x1,x2,result;

  // Beispiel 1:
  x1 = 35;
  x2 = 85;
  result = x1 + x2;
  printf("Beispiel 1: %hi + %hi = %hi\n",x1 ,x2, result);
  // Ausgabe: 120
  // 120 liegt im darstellbaren Bereich, also gibt es keinen Overflow und das
  // richtige Ergebnis wird ausgegeben

  // Beispiel 2:
  x1 = 85;
  x2 = 85;
  result = x1 + x2;
  printf("Beispiel 2: %hi + %hi = %hi\n",x1 ,x2, result);
  // Ausgabe: -86
  // 85 + 85 = 170 liegt nicht mehr im darstellbaren Bereich, also entsteht ein
  // Overflow. 170 = -86 (modulo 256), denn 170-256 = -86.

  return 0;
}
