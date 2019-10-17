// Copyright [2019] <PinkiePie1189>
#include <stdio.h>
#define NMAX 100

void read_matrix(int n, int m, int mat[NMAX][NMAX]) {
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                        scanf("%d", &mat[i][j]);
                }
        }
}

void print_matrix(int n, int m, int mat[NMAX][NMAX]) {
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                        printf("%d ", mat[i][j]);
                }
                printf("\n");
        }
}


void print_matrix_border(int a[NMAX][NMAX], int x, int y, int p, int q) {
	for (int i = y; i < q; i++) {
		printf("%d ", a[0][i]);
	}
	
	for (int i = x + 1; i < p; i++) {
		printf("%d ", a[i][q - 1]);
	}

	for (int i = q - 1; i >= y; i--) {
		printf("%d ", a[p - 1][i]);
	}
	
	for (int i = p - 1; i > x; i--) {
		printf("%d ", a[i][0]);
	}
}

void print_spiral_recursive(int a[NMAX][NMAX], int x, int y, int p, int q) {
	if (x <= p && y <= q) {
		print_matrix_border(a, x, y, p, q);
		print_spiral_recursive(a, x + 1, y + 1, p + 1, q + 1);
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int mat[NMAX][NMAX];
	read_matrix(n, n, mat);
	print_spiral_recursive(mat, 0, 0, n, n);
	return 0;
}
