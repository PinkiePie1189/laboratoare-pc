#include <stdio.h>


int main() {
	short int a;
	int b;
	long int c;

	//metoda1
	printf("%ld %ld %ld\n", sizeof(short int), sizeof(int), sizeof(long int));
	//metoda2
	printf("%ld %ld %ld\n", sizeof(a), sizeof(b), sizeof(c));

	//unitatea de masura este byte-ul
	return 0;
}
