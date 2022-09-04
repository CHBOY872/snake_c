#include <stdlib.h>
#include "field.h"
#include "snake.h"

void check_out_of_field(struct snake *sn, struct field *fld)
{
    if (sn->pos.x >= SIZE)
        sn->pos.x = 0;
    if (sn->pos.y >= SIZE)
        sn->pos.y = 0;
    if (sn->pos.x < 0)
        sn->pos.x = SIZE - 1;
    if (sn->pos.y < 0)
        sn->pos.y = SIZE - 1;
}

int is_pos_equals(struct position *pos_1, struct position *pos_2)
{
    return pos_1->x == pos_2->x && pos_1->y == pos_2->y;
}

void init_snake(struct snake **sn)
{
    *sn = malloc(sizeof(struct snake));
    (*sn)->pos.x = SIZE / 2;
    (*sn)->pos.y = SIZE / 2;
    (*sn)->next = NULL;
}

void delete_snake(struct snake **sn)
{
    while (*sn)
    {
        struct snake *tmp = (*sn)->next;
        free(*sn);
        *sn = tmp;
    }
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
    (*sn)->pos.x += mv->x;
    (*sn)->pos.y += mv->y;
    check_out_of_field(*sn, fld);
}

void eat_snake(struct snake **sn, struct move_vector *mv, struct food *fod)
{
    struct snake *tmp = malloc(sizeof(struct snake));
    tmp->next = NULL;
    tmp->pos.x = (*sn)->pos.x - mv->x;
    tmp->pos.y = (*sn)->pos.y - mv->y;
    struct snake *main_tmp = *sn;
    while (main_tmp->next)
        main_tmp = main_tmp->next;
    main_tmp->next = tmp;
    init_food(fod);
}

void init_food(struct food *fod)
{
    fod->pos.x = rand() % SIZE;
    fod->pos.y = rand() % SIZE;
}

void is_snake(struct snake *sn, enum state *st)
{
    struct position *head_pos = &sn->pos;
    struct snake *tmp = sn->next;
    while (tmp)
    {
        if (is_pos_equals(head_pos, &tmp->pos))
        {
            *st = is_snake_state;
            return;
        }
        tmp = tmp->next;
    }
}

void is_food(struct snake *sn, struct food *fod, enum state *st)
{
    struct position *head_pos = &sn->pos;
    if (is_pos_equals(head_pos, &fod->pos))
        *st = is_food_state;
}

void handle_snake(struct snake *sn, struct food *fod, enum state *st, struct move_vector *mv)
{
    switch (*st)
    {
    case is_none_state:
        *st = is_free_state;
        break;
    case is_food_state:
        eat_snake(&sn, mv, fod);
        *st = is_free_state;
        break;
    case is_snake_state:
        exit(0);
        break;
    default:
        break;
    }
}