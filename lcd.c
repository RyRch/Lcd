#include <string.h>
#include <stdio.h>

typedef struct
{
    char digits[3][30];
    char list[];
} format_t;

static void
fill_struct(format_t *lcd, char *av)
{
    strcpy(lcd->digits[0], " _     _  _     _  _ _   _  _ ");
    strcpy(lcd->digits[1], "| | |  _| _||_||_ |_  | |_||_|");
    strcpy(lcd->digits[2], "|_| | |_  _|  | _||_| | |_| _|");
    lcd->list[strlen(av)];
    strcpy(lcd->list, av);
}

static void
lcd_format(format_t *lcd)
{
    int nb_list;

    for (int i = 0; lcd->list[i] != '\0'; i++) {
        nb_list = lcd->list[i] - '0';
        for (int y = 0; y < 3; y++) {
            for (int x = 0; x < 3; x++)
                printf("%c", lcd->digits[y][(nb_list * 3) + x]);
        printf("\n");
        }
    }
}

int 
main(int ac, char **av)
{
    format_t lcd;

    fill_struct(&lcd, av[1]);
    if (av[1] == NULL
            || av[1][0] < '1' && av[1][0] > '9')
        return 84;
    lcd_format(&lcd);
    return 0;
}
