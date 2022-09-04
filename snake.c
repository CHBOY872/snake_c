#include <stdlib.h>
#include "field.h"
#include "snake.h"

void init_snake(struct snake *sn)
{
    sn->pos_x = SIZE / 2;
    sn->pos_y = SIZE / 2;
    sn->next = NULL;
}