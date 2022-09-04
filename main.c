#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "field.h"
#include "snake.h"

static struct field fld;
static struct food fod;
static struct snake *sn;

int main()
{
    enum state st;
    srand(time(NULL));
    init_field(&fld);
    init_snake(&sn);
    init_food(&fod);

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
    eat_snake(&sn, &vct, &fod);
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

    delete_snake(&sn);
    return 0;
}