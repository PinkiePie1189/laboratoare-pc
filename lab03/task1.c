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

int main() {
        int n;
        int v[NMAX];
        scanf("%d", &n);
        read_array(n, v);
        print_array(n, v);
        return 0;
}
