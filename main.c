#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "field.h"
#include "snake.h"
#include "draw_game.h"

static struct field fld;
static struct food fod;

int main()
{
    struct snake *sn;
    enum state st = is_none_state;
    srand(time(NULL));
    init_field(&fld);
    init_snake(&sn);
    init_food(&fod);
    struct move_vector mv = {0, 0};
    fd_set rds;

    char buf;

    for (;;)
    {
        draw_field(&fld, sn, &fod);
        FD_ZERO(&rds);
        FD_SET(0, &rds);
        struct timeval t;
        t.tv_sec = 1;
        int stat = select(2, &rds, NULL, NULL, &t);

        if (stat > 0)
        {
            stat = read(0, &buf, sizeof(buf));
            switch (buf)
            {
            case 'w':
                mv.x = 0;
                mv.y = -1;
                break;
            case 's':
                mv.x = 0;
                mv.y = 1;
                break;
            case 'a':
                mv.x = -1;
                mv.y = 0;
                break;
            case 'd':
                mv.x = 1;
                mv.y = 0;
                break;
            default:
                break;
            }
        }

        handle_snake(sn, &fod, &st, &mv);
        move_snake(&sn, &mv, &fld);
        is_food(sn, &fod, &st);
        is_snake(sn, &st);
    }

    return 0;
}