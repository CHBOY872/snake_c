#include <stdio.h>
#include <stdlib.h>

#include "field.h"
#include "snake.h"

static int field[SIZE][SIZE];
static struct snake sn;

int main()
{
    init_field(field);
    init_snake(&sn);
    int x, y;
    for (y = 0; y < SIZE; y++)
    {
        for (x = 0; x < SIZE; x++)
        {
            if (x == sn.pos_x && y == sn.pos_y)
                printf("* ");
            else
                printf("0 ", field[y][x]);
        }
        printf("\n");
    }
    return 0;
}