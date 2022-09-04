#ifndef FIELD_H_SENTRY
#define FIELD_H_SENTRY

#define SIZE 15

struct field
{
    char field[SIZE][SIZE];
};

void init_field(struct field *fld);

#endif