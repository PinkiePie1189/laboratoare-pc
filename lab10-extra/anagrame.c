// Copyright [2019] <PinkiePie1189>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILENAME "anagrame.in"
#define MAXBUF 1000
#define MAXSIGMA 26

void check_file_error(FILE *fd, char *filename) {
    if (fd == NULL) {
        fprintf(stderr, "Can't open file %s\n", filename);
    }
}

void truncate(char *buf) { 
    int len = strlen(buf);
    if (buf[len - 1] == '\n') {
        buf[len - 1] = '\0';
    }
}

void to_lower(char *buf) {
    int len = strlen(buf);
    for (int i = 0; i < len; i++) {
        if ('A' <= buf[i] && buf[i] <= 'Z') {
            buf[i] = buf[i] - 'A' + 'a';
        }
    }
}

void check_alloc_error(void *ptr) {
    if (ptr == NULL) {
        fprintf(stderr, "Couldn't allocate memory\n");
        exit(-1);
    }
}

int get_words(char buf[], char delim[], char ***words) {
    char *word = strtok(buf, delim);
    int cnt = 0;
    *words = NULL;
    while (word != NULL) {
        to_lower(word);
        *words = (char **) realloc(*words, (cnt + 1) * sizeof(char**));
        check_alloc_error(*words);
        int len = strlen(word) + 1;
        (*words)[cnt] = (char*) malloc(len * sizeof(char));
        check_alloc_error((*words)[cnt]);
        strncpy((*words)[cnt], word, len); 
        cnt++;
        word = strtok(NULL, delim);
    }
    return cnt;
}

void sort_words(int n, char **words) {
    int sorted = 0;
    while (!sorted) {
        sorted = 1;
        for (int i = 1; i < n; i++) {
            if (strcmp(words[i - 1], words[i]) > 0) {
                    sorted = 0;
                    char *man = words[i];
                    words[i] = words[i - 1];
                    words[i - 1] = man;
            }
        }
    }
}


int remove_duplicates(int n, char **words) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || strcmp(words[i], words[i - 1])) {
            int len = strlen(words[i]) + 1;
            strncpy(words[cnt++], words[i], len);
        }
    }
    return cnt;
}

int is_anagram(char *word1, char *word2) {
    int fr[MAXSIGMA];
    memset(fr, 0, MAXSIGMA * sizeof(int));
    int len = strlen(word1);
    for (int i = 0; i < len; i++) {
        fr[word1[i] - 'a']++;
    }
    len = strlen(word2);
    for (int i = 0; i < len; i++) {
        fr[word2[i] - 'a']--;
    }

    for (int i = 0; i < MAXSIGMA; i++) {
        if (fr[i] != 0) {
            return 0;
        }
    }

    return 1;
}

void print_table(int n, char **words) {
    int cnt = 0;
    int *table_len = NULL;
    int **table = NULL;

    for (int i = 0; i < n; i++) {
        int found = 0, posfound = -1;
        for (int j = 0; j < cnt && !found; j++) {
            if (is_anagram(words[table[j][0]], words[i])) {
                found = 1;
                posfound = j;
            }
        }
        printf("%d\n", cnt);
        fflush(stdout);
        if (found) {
            printf("aici %s %s", words[i], words[table[j][0]]);
            int newlen = ++table_len[posfound];
            table[posfound] = (int *) realloc(table[posfound], newlen * sizeof(int));
            check_alloc_error(table[posfound]);
            table[posfound][newlen - 1] = i;
        } else {
            table = (int**) realloc(table, sizeof(int**) * (cnt + 1));
            check_alloc_error(table);
            table_len = (int *) realloc(table, sizeof(int*) * (cnt + 1)); 
            check_alloc_error(table_len);
            table[cnt] = (int *) malloc(sizeof(int));
            check_alloc_error(table[cnt]);
            table[cnt][0] = i;
            cnt++;
        }
    }

    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j < table_len[i]; j++) {
            printf("%s-", words[table[i][j]]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fin = fopen(FILENAME, "r");
    char buf[MAXBUF];
    fgets(buf, MAXBUF, fin);
    truncate(buf);
    char **words;
    int n = get_words(buf, ", -.", &words);
    sort_words(n, words);
    int new_cnt = remove_duplicates(n, words);
    print_table(new_cnt, words);
    // TODO free memory
}
