// Copyright [2019] <PinkiePie1189>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 31
#define FILENAME "3-gigel.bin"

typedef struct {
    char *name;
    int age;
} person_t;

void check_file_error(FILE *fd, char *name) {
    if (fd == NULL) {
        fprintf(stderr, "Cannot open file %s\n", name);
    }
}

void check_alloc_error(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Couldn't allocate memory\n");
    }
}

void read_person_stdin(person_t *p) {
    memset(p, 0, sizeof(*p));
    char buf[NAME_LEN];
    scanf("%30s %d", buf, &p->age);
    int len = strlen(buf) + 1;
    p->name = (char*) malloc(len * sizeof(char));
    check_alloc_error(p->name);
    strncpy(p->name, buf, len);
}

void read_person_file(person_t *p, FILE *fd) {
    memset(p, 0, sizeof(*p));
    int name_len;
    fread(&name_len, 1, sizeof(int), fd);
    p->name = (char*) malloc(name_len * sizeof(char));
    check_alloc_error(p->name);
    fread(p->name, 1, name_len, fd);
    fread(&p->age, 1, sizeof(int), fd);
}

void write_person(person_t *p, FILE *fd) {
    int name_len = strlen(p->name) + 1;
    fwrite(&name_len, 1, sizeof(int), fd);
    fwrite(p->name, 1, name_len, fd);
    fwrite(&p->age, 1, sizeof(int), fd);
}

void write_person_stdin(person_t *p) {
    printf("%s %d\n", p->name, p->age);
}

void free_person(person_t *p) {
    free(p->name);
}

int main() {
    int n;
    scanf("%d", &n);
    FILE *fout = fopen(FILENAME, "wb");
    check_file_error(fout, FILENAME);
    fwrite(&n, 1, sizeof(int), fout);
    for (int i = 0; i < n; i++) {
        person_t p;
        read_person_stdin(&p);
        write_person(&p, fout);
        free_person(&p);
    }
    fclose(fout);

    FILE *fin = fopen(FILENAME, "rb");
    check_file_error(fin, FILENAME);

    fread(&n, 1, sizeof(int), fin);
    person_t *v = (person_t*) malloc(n * sizeof(person_t));

    for (int i = 0; i < n; i++) {
        read_person_file(&v[i], fin);
    }

    for (int i = 0; i < n; i++) {
        write_person_stdin(&v[i]);
    }

    for (int i = 0; i < n; i++) {
        free_person(&v[i]);
    }

    free(v);
    fclose(fin);
    return 0;
}
