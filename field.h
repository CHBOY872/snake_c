#ifndef FIELD_H_SENTRY
#define FIELD_H_SENTRY

#define SIZE 30

typedef int (*field)[SIZE];

struct field
{
    int field[SIZE][SIZE];
    int size;
};

void init_field(struct field *fld);

#endif