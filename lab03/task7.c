// Copyright [2019] <PinkiePie1189>
#include <stdio.h>
#define NMAX 100
void read_array(int n, int *v) {
        for (int i = 0; i < n; i++) {
                scanf("%d", &v[i]);
        }
}

void print_array(int n, int *v) {
        for (int i = 0; i < n; i++) {
                printf("%d ", v[i]);
        }
}

int diff_array(int n, int *v, int m,  int *w, int *diff) {
        int nr = 0;
        for (int i = 0; i < n; i++) {
                int ok = 1;
                for (int j = 0; j < m; j++) {
                        if (v[i] == w[j]) {
                                ok = 0;
                        }
                }
                if (ok) {
                        diff[nr++] = v[i];
                }
        }
        return nr;
}

int main() {
        int n, m;
        scanf("%d%d", &n, &m);
        int v[NMAX], w[NMAX];
        read_array(n, v);
        read_array(m, w);
        int diff[NMAX];
        int d = diff_array(n, v, m, w, diff);
        print_array(d, diff);
        return 0;
}
