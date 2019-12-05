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

void extract_diagonals(int n, int m, int col, int mat[NMAX][NMAX]) {
        int lin = 0;
        int ccol = col;
        int start = mat[0][col];
        while (lin < n && col < m) {
                printf("%d ", mat[lin][col]);
                mat[lin][col] = 0;
                lin++;
                col++;
        }
        printf("\n");
        lin = 1, col = ccol - 1;
        printf("%d ", start);
        while (lin < n && col >= 0) {
                printf("%d ", mat[lin][col]);
                mat[lin][col] = 0;
                lin++;
                col--;
        }
        printf("\n");
}

int main () {
        int n, m, col;
        scanf("%d%d%d", &n, &m, &col);
        int mat[NMAX][NMAX];
        read_matrix(n, m, mat);
        extract_diagonals(n, m, col, mat);
        print_matrix(n, m, mat); 
        return 0;
}
