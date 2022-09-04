#include <stdlib.h>
#include "field.h"
#include "snake.h"

void check_out_of_field(struct snake *sn, struct field *fld)
{
    int size = fld->size;
    if (sn->pos.x >= size)
        sn->pos.x = 0;
    if (sn->pos.y >= size)
        sn->pos.y = 0;
    if (sn->pos.x < 0)
        sn->pos.x = size - 1;
    if (sn->pos.y < 0)
        sn->pos.y = size - 1;
}

void init_snake(struct snake *sn)
{
    sn->pos.x = SIZE / 2;
    sn->pos.y = SIZE / 2;
    sn->next = NULL;
}

void move_snake(struct snake *sn, struct move_vector *mv, struct field *fld)
{
    struct snake *tmp = sn;
    while (tmp->next)
    {
        tmp->next->pos.x = tmp->pos.x;
        tmp->next->pos.y = tmp->pos.y;
        tmp = tmp->next;
    }
    sn->pos.x += mv->x;
    sn->pos.y += mv->y;
    check_out_of_field(sn, fld);
}