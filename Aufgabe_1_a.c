#include <stdio.h>
#include <stdlib.h>

char* turn_word(char* word, int size) {
	char* turned = malloc(size * sizeof(char));
	
	if (turned == NULL) {
		printf("turn word failed!\n");
		return NULL;
	}
	for (int i = 0; i <size; i++) {
		turned[i]=word[size-1-i];
	}
	return turned;
}

int is_palindrome(char* word, int size) {
	char* turned = turn_word(word, size);
	for (int i = 0; i < size; i++) {
		if (word[i] != turned[i]) return 0;
	}
	return 1;
}

int main() {
	char* str = "reittier";
	printf("%i", is_palindrome(str, 8));

	return 0;
}