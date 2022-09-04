#ifndef SNAKE_H_SENTRY
#define SNAKE_H_SENTRY

#include "field.h"
#include "position_move.h"

enum state
{
    is_none_state,
    is_snake_state,
    is_food_state,
    is_free_state
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

void is_snake(struct snake *sn, enum state *st);
void is_food(struct snake *sn, struct food *fod, enum state *st);

void handle_snake(struct snake *sn, struct food *fod, enum state *st,
                  struct move_vector *mv);

#endif