#ifndef SNAKE_H_SENTRY
#define SNAKE_H_SENTRY

struct snake
{
    int pos_x;
    int pos_y;
    struct snake *next;
};

struct move_vector
{
    int x;
    int y;
};

void init_snake(struct snake *sn);
void move_snake(struct sname *sn, struct move_vector *mv, struct field *fld);

#endif