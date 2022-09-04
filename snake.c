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

void move_snake(struct snake **sn, struct move_vector *mv, struct field *fld)
{
    struct snake **p;
    int tmp_x = (*sn)->pos.x;
    int tmp_y = (*sn)->pos.y;
    int tmp2_x, tmp2_y;
    for (p = sn; (*p)->next; p = &((*p)->next))
    {
        tmp2_x = (*p)->next->pos.x;
        tmp2_y = (*p)->next->pos.y;
        (*p)->next->pos.x = tmp_x;
        (*p)->next->pos.y = tmp_y;
        tmp_x = tmp2_x;
        tmp_y = tmp2_y;
    }
    (*sn)->pos.x = mv->x;
    (*sn)->pos.y = mv->y;
    check_out_of_field(*sn, fld);
}

void eat_snake(struct snake **sn, struct move_vector *mv)
{
    struct snake *tmp = malloc(sizeof(struct snake));
    tmp->next = *sn;
    tmp->pos.x = (*sn)->pos.x - mv->x;
    tmp->pos.y = (*sn)->pos.y - mv->y;
    *sn = tmp;
}