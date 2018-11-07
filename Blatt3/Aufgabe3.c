#include <stdio.h>

void einser(int i) {
	switch(i) {
		case 0: return;
		case 1: {printf("ein und ");return;}
		case 2: {printf("zwie und ");  return;    }
		case 3: {printf("drei und ");  return;    }
		case 4: {printf("vier und ");  return;    }
		case 5: {printf("fünf und "); return;     }
		case 6: {printf("sechs und ");  return;   }
		case 7: {printf("sieben und "); return;   }
		case 8: {printf("acht und ");  return;    }
		case 9: {printf("neun und ");  return;    }
	}
}

void zehner(int i) {
	switch(i) {
		case 2: {printf("zwanzig"); return;}
		case 3: {printf("dreissig");return;}
		case 4: {printf("vierzig");return; }
		case 5: {printf("fünfzig");return; }
		case 6: {printf("sechzig");return; }
		case 7: {printf("siebzig");return; }
		case 8: {printf("achtzig");return; }
		case 9: {printf("neunzig");return; }
	}
}

int main() {
	int n=0;
	do {
		printf("gib eine zahl von 20 bis 69 ein\n");
		scanf("%i",&n);
	}while(20>n || 69<n);
	einser(n%10);
	zehner(n/10);
}
