#include "field.h"

void init_field(struct field *fld)
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
            fld->field[i][j] = 0;
    }
    fld->size = SIZE;
}