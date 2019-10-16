#include <stdio.h>


int main() {
	int x;
	scanf("%d", &x);
	//metoda1
	
	if(x % 2 == 0) {
		printf("PAR\n");
	} else {
		printf("IMPAR\n");
	}

	//metoda2
	
	if(2 * (x / 2) == x) {
		printf("PAR\n");
	} else {
		printf("IMPAR\n");
	}
	return 0;
}
