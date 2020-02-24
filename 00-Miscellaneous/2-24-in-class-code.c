#include <stdio.h>
#include <string.h>

typedef struct String {
    char* array;
    int length;
    int count;
} String;

String make(int length) {
    char s[length];
    String str = { s, length, 0 };
    return str;
}

void print(String s) {
    printf("String is : %s\n", s.array);
    printf("With length : %d\n", s.length);
    printf("With count  : %d\n", s.count);
}

// insert a single char
void insert(char c, String *s) {    // Since pointer to String, must use Arrow notation - NOT dot notation
    if(s->count == s->length) {
        char *t = (char *) realloc(s->array, s->length * 2 * sizeof(char));
        if (t == NULL) { perror("Error "); exit(1); }
        s->array = t;
        s->length *=2;
    }
    s->array[s->count] = c;
    s->count += 1;
}

void del(String *s) {
    if(s->array != NULL) { // only delete non-null strings
        free(s->array); 
        s->array = NULL;
        s->length = 0;
        s->count = 0;
    }
}

int main() {
    String s = make(4);

    insert('H', &s);
    insert('e', &s);
    insert('l', &s);
    insert('l', &s);
    insert('o', &s);

    del(&s);

    return 0;
}