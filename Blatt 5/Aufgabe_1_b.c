#include <stdio.h>
#include <stdlib.h>


void encr(char* s) {
	int pos = 0;
	while (s[pos] != '\0') {
		
		if (s[pos]<'a' || s[pos]>'z') {
			printf("invalid word\n");
			return;
		}
		
		if (((int)s[pos] + 13) > 122) {
			s[pos] = (char)( (((int)s[pos])-13) );
		}
		else {
			s[pos] = (char)(s[pos] + 13);
		}
		pos++;
	}
}

void decr(char* s) {
	int pos = 0;
	while (s[pos] != '\0') {

		if (s[pos]<'a' || s[pos]>'z') {
			printf("invalid word\n");
			return;
		}

		if (((int)s[pos] + -13) < 97) {
			s[pos] = (char)((((int)s[pos]) +13));
		}
		else {
			s[pos] = (char)(s[pos] - 13);
		}
		pos++;
	}
}

void encrk(char* s, int k) {
	int pos = 0;
	if (k < 0 || 27 <= k) {
		printf("encrk failed due to invalid second argument\n");
		return;
	}
	while (s[pos] != '\0') {

		if (s[pos]<'a' || s[pos]>'z') {
			printf("invalid word\n");
			return;
		}

		if (((int)s[pos] + k) > 122) {
			s[pos] = (char)((((int)s[pos]) - (26-k)));
		}
		else {
			s[pos] = (char)(s[pos] + k);
		}
		pos++;
	}
}


void decrk(char* s, int k) {
	int pos = 0;
	if (k < 0 || 27 <= k) {
		printf("encrk failed due to invalid second argument\n");
		return;
	}
	while (s[pos] != '\0') {

		if (s[pos]<'a' || s[pos]>'z') {
			printf("invalid word\n");
			return;
		}

		if (((int)s[pos] -k) < 97) {
			s[pos] = (char)((((int)s[pos]) + (26-k)));
		}
		else {
			s[pos] = (char)(s[pos] - k);
		}
		pos++;
	}
}


int main() {
	
	char s[] = "abcdefghijklmnopqrstuvwxyz";
	encr(s);
	printf("%s\n", s);
	decr(s);
	printf("%s\n", s);

	encrk(s, 12);
	printf("after encrk:%s\n", s);
	decrk(s, 12);
	printf("after decrk:%s\n", s);
	
	return 0;


}