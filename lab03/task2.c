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

int sum_array(int n, int *v) {
        int s = 0;
        for (int i = 0; i < n; i++) {
                s += v[i];
        }
        return s;
}

int min_array(int n, int *v) {
        int min = v[0];
        for (int i = 1; i < n; i++) {
                if (v[i] < min) {
                        min = v[i];
                }
        }
        return min;
}

int posmax_array(int n, int *v) {
        int posmax = 0, max = v[0];
        for (int i = 1; i < n; i++) {
                if (v[i] > max) {
                        max = v[i];
                        posmax = i;
                }
        }
        return posmax;
}

double avg_array(int n, int *v) {
        return (double) sum_array(n, v) / n;
}

int find_array(int n, int *v, int x) {
        for (int i = 0; i < n; i++) {
                if (v[i] == x) {
                        return i;
                }
        }
        return -1;
}

int main() {
        int n, x;
        int v[NMAX];
        scanf("%d%d", &n, &x);
        read_array(n, v);
        print_array(n, v);
        printf("%d %d %d %lf %d", sum_array(n, v), min_array(n, v), posmax_array(n, v), avg_array(n, v), find_array(n, v, x));
        return 0;
}
