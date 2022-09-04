#include <stdio.h>
#include <stdlib.h>

#include "field.h"
#include "snake.h"

static struct field fld;
// static struct snake sn;
// static struct snake *sn_ptr = &sn;

int main()
{
    struct snake *sn = malloc(sizeof(struct snake));
    init_field(&fld);
    init_snake(sn);
    int x, y;
    for (y = 0; y < SIZE; y++)
    {
        for (x = 0; x < SIZE; x++)
        {
            if (x == sn->pos.x && y == sn->pos.y)
                printf("* ");
            else
                printf("  ", fld.field[y][x]);
        }
        printf("\n");
    }
    struct move_vector vct = {1, 1};
    move_snake(&sn, &vct, &fld);
    eat_snake(&sn, &vct);
    for (y = 0; y < SIZE; y++)
    {
        for (x = 0; x < SIZE; x++)
        {
            if (x == sn->pos.x && y == sn->pos.y)
                printf("* ");
            else
                printf("  ", fld.field[y][x]);
        }
        printf("\n");
    }

    free(sn);
    return 0;
}