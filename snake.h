#ifndef SNAKE_H_SENTRY
#define SNAKE_H_SENTRY

#include "field.h"
#include "position_move.h"

enum state
{
    is_none,
    is_snake,
    is_eat,
    is_free
};

struct snake
{
    struct position pos;
    struct snake *next;
};

struct food
{
    struct position pos;
};

void init_snake(struct snake **sn);
void delete_snake(struct snake **sn);
void move_snake(struct snake **sn, struct move_vector *mv, struct field *fld);
void eat_snake(struct snake **sn, struct move_vector *mv, struct food *fod);

void init_food(struct food *fod);

void handle_snake();

#endif