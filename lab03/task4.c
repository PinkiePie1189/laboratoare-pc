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


int main() {
        int n, m, p;
        scanf("%d%d%d", &n, &m, &p);
        int a[NMAX][NMAX], b[NMAX][NMAX], c[NMAX][NMAX];
        read_matrix(n, m, a);
        read_matrix(m, p, b);
        multiply_matrix(n, m, p, a, b, c);
        print_matrix(n, p, c);
        return 0;
}
