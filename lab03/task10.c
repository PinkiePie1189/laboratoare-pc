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

void print_submatrix(int a[NMAX][NMAX], int x, int y, int p, int q) {
        for (int i = x; i <= p; i++) {
	        for (int j = y; j <= q; j++) {
                        printf("%d ", a[i][j]);
                }
                printf("\n");
        }        
}

void print_all_submatrix(int n, int a[NMAX][NMAX]) {
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        for (int k = i; k < n; k++) {
                                for (int l = j; l < n; l++) {
                                        //printf("%d %d %d %d\n", i, j, k, l);
                                        print_submatrix(a, i, j, k, l);
                                }
                        }
                }
        }
}


int sum_submatrix(int a[NMAX][NMAX], int x, int y, int p, int q) {
        int sum = 0;
        for (int i = x; i <= p; i++) {
	        for (int j = y; j <= q; j++) {
                        sum += a[i][j];
                }
        }
        return sum;
}

void find_maxsum_submatrix(int n, int a[NMAX][NMAX]) {
        int maxi = -1;
        int maxx = 0, maxy = 0, maxp = 0, maxq = 0; 
        for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                        for (int k = i; k < n; k++) {
                                for (int l = j; l < n; l++) {
                                        //printf("%d %d %d %d\n", i, j, k, l);
                                        int s = sum_submatrix(a, i, j, k, l);
                                        if (s > maxi) {
                                                maxx = i;
                                                maxy = j;
                                                maxp = k;
                                                maxq = l;
                                                maxi = s;
                                        }
                                }
                        }
                }
        }
        printf("%d\n", maxi);
        print_submatrix(a, maxx, maxy, maxp, maxq);
}

int main() {
	int n;
	scanf("%d", &n);
        int mat[NMAX][NMAX];
	read_matrix(n, n, mat);
	print_all_submatrix(n, mat);
        find_maxsum_submatrix(n, mat);
        return 0;
}

