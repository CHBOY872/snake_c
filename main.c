#include <stdio.h>
#include <stdlib.h>

#include "field.h"
#include "snake.h"

static struct field fld;

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
    struct move_vector vct = {0, 1};
    move_snake(&sn, &vct, &fld);
    eat_snake(&sn, &vct);
    move_snake(&sn, &vct, &fld);
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