// Copyright [2019] <PinkiePie1189>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 31
#define FILENAME "2-gigel.bin"

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
    person_t p;

    // Subtask a
    FILE *fout = fopen(FILENAME, "wb");
    check_file_error(fout, FILENAME);
    read_person_stdin(&p);
    write_person(&p, fout);
    fclose(fout);
    free_person(&p);
    // Subtask b
    FILE *fin = fopen(FILENAME, "rb");
    check_file_error(fin, FILENAME);
    read_person_file(&p, fin);
    write_person_stdin(&p);
    fclose(fin);
    free_person(&p);
    return 0;
}
