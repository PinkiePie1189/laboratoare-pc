// Copyright [2019] <PinkiePie1189>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 31
#define FILENAME "1-gigel.bin"

typedef struct __attribute__((__packed__)) {
    char name[NAME_LEN];
    int age;
} person_t;

void check_file_error(FILE *fd, char *name) {
    if (fd == NULL) {
        fprintf(stderr, "Cannot open file %s\n", name);
    }
}

void read_person_stdin(person_t *p) {
    memset(p, 0, sizeof(*p));
    scanf("%s %d", p->name, &p->age);
}

void read_person_file(person_t *p, FILE *fd) {
    memset(p, 0, sizeof(*p));
    fread(p, 1, sizeof(*p), fd);
}

void write_person(person_t *p, FILE *fd) {
    fwrite(p, 1, sizeof(*p), fd);
}

void write_person_stdin(person_t *p) {
    printf("%s %d\n", p->name, p->age);
}

int main() {
    // Subtask a
    FILE *fout = fopen(FILENAME, "wb");
    check_file_error(fout, FILENAME);
    person_t p;
    read_person_stdin(&p);
    write_person(&p, fout);
    fclose(fout);
    // Subtask b
    FILE *fin = fopen(FILENAME, "rb");
    check_file_error(fin, FILENAME);
    read_person_file(&p, fin);
    write_person_stdin(&p);
    fclose(fin);
    return 0;
}
