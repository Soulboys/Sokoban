/*
** EPITECH PROJECT, 2018
** Delivery
** File description:
** __DESCRIPTION__
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ncurses.h>
#include "include/my.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char **keypress(char **map, int ch, char **reset, int f, int *pos_of_o)
{
    int *pos_player = getInt(map, f);

    if (ch == KEY_LEFT)
        map = moveleft(map, pos_player, f, pos_of_o);
    if (ch == KEY_RIGHT)
        map = moveright(map, pos_player, f, pos_of_o);
    if (ch == KEY_UP)
        map = moveup(map, pos_player, f, pos_of_o);
    if (ch == KEY_DOWN)
        map = movedown(map, pos_player, f, pos_of_o);
    if (ch == 32)
        for (int i = 0; i != f; i++)
            for (int j = 0; j != my_strlentab(map, i); j++)
                map[i][j] = reset[i][j];
    if (ch == 27)
        exit(0);
    return (map);
}

int *getInt(char **map, int f)
{
    int *pos_player = malloc(sizeof(int) * 2);

    for (int g = 0; g != f; g++) {
        for (int s = 0; s != my_strlentab(map, g); s++) {
            if (map[g][s] == 'P') {
                pos_player[0] = g;
                pos_player[1] = s;
            }
        }
    }
    return (pos_player);
}

int game(char **map, char **reset, int f, int *pos_of_o)
{
    int ch;

    initscr();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    noecho();
    for (int i = 0; i != f; i++) {
        printw(map[i]);
    }
    while (1) {
        ifloose(map, pos_of_o, f);
        ch = getch();
        map = keypress(map, ch, reset, f, pos_of_o);
        clear();
        for (int m = 0; m != f; m++)
            printw(map[m]);
        refresh();
    }
    endwin();
}

char *openfile(char *filepath)
{
    char *str;
    int thecat;
    struct stat filest;

    stat(filepath, &filest);
    str = malloc(sizeof(char) * filest.st_size + 1);
    thecat = open(filepath, O_RDONLY);
    if (thecat == -1) {
        write(2, "FAILURE\n", 8);
        exit(84);
    } else {
        read(thecat, str, filest.st_size);
    }
    str[filest.st_size] = '\0';
    close(thecat);
    return (str);
}

int main(int argc, char **argv)
{
    int f = 0;

    if (argc == 1) {
        write(1, "No such File\n", 14);
        return (84);
    }
    if (argv[1][0] == '-') {
        if (argv[1][1] == 'h') {
            help();
            return (1);
        }
    }
    char *m = openfile(argv[1]);
    char **tkt = strtotab(my_strdup(m), &f);
    char **reset = strtotab(my_strdup(m), &f);
    int *pos_of_o = pos_o(tkt, f);
    game(tkt, reset, f, pos_of_o);
}
