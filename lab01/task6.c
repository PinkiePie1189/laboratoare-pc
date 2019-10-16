#include <stdio.h>


int main() {
	int n;
	scanf("%d", &n);
	int primes = 0;
	while (n >= 0) {
		int is_prime = 1;
		for (int d = 2; d * d <= n; d++) {
			if (n % d == 0) {
				is_prime = 0;
				printf("%d ", d);
				if (d != (n / d)) {
					printf("%d ", n / d);
				}
			}
		}

		if (is_prime) {
			printf("PRIM");
			primes++;
		}
		printf("\n");
		scanf("%d", &n);
	}

	printf("S-au gasit %d numere prime\n", primes);

	return 0;
}
