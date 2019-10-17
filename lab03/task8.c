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

int binarysearch(int n, int *v, int x, int y) {
        if (x > y) {
                int man = x;
                x = y;
                y = man;
        } 
        int st = 0, dr = n - 1, lastx = n - 1;
        // cautam cel mai mic numar >=x
        while (st <= dr) {
                int mid = (st + dr) / 2;
                if (v[mid] >= x) {
                        lastx = mid;
                        dr = mid - 1;
                } else {
                        st = mid + 1;
                }
        }
        st = 0, dr = n - 1;
        int lasty = 0;
        // cautam cel mai mare numar <= y
        while (st <= dr) {
                int mid = (st + dr) / 2;
                if (v[mid] <= y) {
                        st = mid + 1;
                        lasty = mid;
                } else {
                        dr = mid - 1;
                }
        }
        return lasty - lastx + 1;
}

int main() {
        int n, x, y;
        scanf("%d%d%d", &n, &x, &y);
        int v[NMAX];
        read_array(n, v);
        printf("%d", binarysearch(n, v, x, y));
        return 0;
}
