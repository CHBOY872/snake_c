#include "field.h"

void init_field(int (*field)[SIZE])
{
    int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
            field[i][j] = 0;
    }
}