#include <stdio.h>
#include <stdlib.h>

#include "draw_game.h"

/* FIRST INDEX - Y, SECOND - X */

void draw_field(struct field *fld, struct snake *sn, struct food *fod)
{
    int x, y;
    for (y = 0; y < SIZE; y++)
    {
        for (x = 0; x < SIZE; x++)
            fld->field[y][x] = ' ';
    }
    fld->field[fod->pos.y][fod->pos.x] = '!';
    struct snake *tmp = sn;
    fld->field[tmp->pos.y][tmp->pos.x] = '%';
    tmp = tmp->next;
    while (tmp)
    {
        fld->field[tmp->pos.y][tmp->pos.x] = '*';
        tmp = tmp->next;
    }
    for (y = 0; y < SIZE; y++)
    {
        for (x = 0; x < SIZE; x++)
            printf("%c ", fld->field[y][x]);
        printf("\n");
    }
}