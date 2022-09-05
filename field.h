#ifndef FIELD_H_SENTRY
#define FIELD_H_SENTRY

#ifndef SIZE
#define SIZE 20
#endif

struct field
{
    char field[SIZE][SIZE];
};

void init_field(struct field *fld);

#endif
