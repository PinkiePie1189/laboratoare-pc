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

void zero_matrix(int n, int m, int mat[NMAX][NMAX]) {
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                        mat[i][j] = 0;
                }
        }
}

void identity_matrix(int n, int mat[NMAX][NMAX]) {
        zero_matrix(n, n, mat);
        for (int i = 0; i < n; i++) {
                mat[i][i] = 1;
        }
}

void copy_matrix(int n, int m, int dst[NMAX][NMAX], int src[NMAX][NMAX]) {
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                        dst[i][j] = src[i][j];
                }
        }
}

void multiply_matrix(int n, int m, int p, int a[NMAX][NMAX], int b[NMAX][NMAX], int c[NMAX][NMAX]) {
        int rez[NMAX][NMAX];
        zero_matrix(n, p, rez);
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < p; j++) {
                        for (int k = 0; k < m; k++) {
                                rez[i][j] += a[i][k] * b[k][j];
                        }
                }
        }
        copy_matrix(n, p, c, rez);
}

void power_matrix(int n, int a[NMAX][NMAX], int k, int b[NMAX][NMAX]) {
        int r[NMAX][NMAX];
        identity_matrix(n, r);
        while (k > 1) {
                if (k % 2 == 0) {
                        multiply_matrix(n, n, n, a, a, a);
                } else {
                        multiply_matrix(n, n, n, r, a, r);
                        multiply_matrix(n, n, n, a, a, a);
                }
                k /= 2;
        }
        multiply_matrix(n, n, n, r, a, b);
}
int main() {
        int n, k;
        scanf("%d%d", &n, &k);
        int a[NMAX][NMAX], b[NMAX][NMAX];
        read_matrix(n, n, a);
        power_matrix(n, a, k, b);
        print_matrix(n, n, b);
        return 0;
}
