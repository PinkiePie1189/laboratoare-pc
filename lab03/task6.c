// Copyright [2019] <PinkiePie1189>
#include <stdio.h>
#define NMAX 100

void read_array(int n, int *v) {
        for (int i = 0; i < n; i++) {
                scanf("%d", &v[i]);
        }
}

int binarysearch(int n, int *v, int x) {
        int st = 0, dr = n - 1;
        while (st < dr) {
                int mid = (st + dr) / 2;
                if (x <= v[mid]) {
                        dr = mid;
                } else {
                        st = mid + 1;
                }
        }
        if (st == dr && v[st] == x) {
                return st;
        }
        return -2;
}

int main() {
        int n, x;
        scanf("%d%d", &n, &x);
        int v[NMAX];
        read_array(n, v);
        printf("%d", binarysearch(n, v, x));
}
