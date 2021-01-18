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

char **if_xright(char **map, int *pos_player, int f, int *pos_of_o)
{
    if (map[pos_player[0]][pos_player[1] + 2] == 'O') {
        map[pos_player[0]][pos_player[1] + 2] = 'X';
        map[pos_player[0]][pos_player[1] + 1] = 'P';
        map[pos_player[0]][pos_player[1]] = ' ';
        wino(map, pos_player, f, pos_of_o);
        return (map);
    }
    if (map[pos_player[0]][pos_player[1] + 2] != '#' &&
    map[pos_player[0]][pos_player[1] + 2] != 'X') {
        map[pos_player[0]][pos_player[1] + 2] = 'X';
        map[pos_player[0]][pos_player[1] + 1] = 'P';
        map[pos_player[0]][pos_player[1]] = ' ';
    }
    map = the_o(map, pos_of_o);
    return (map);
}

char **if_xleft(char **map, int *pos_player, int f, int *pos_of_o)
{
    if (map[pos_player[0]][pos_player[1] - 2] == 'O') {
        map[pos_player[0]][pos_player[1] - 2] = 'X';
        map[pos_player[0]][pos_player[1] - 1] = 'P';
        map[pos_player[0]][pos_player[1]] = ' ';
        wino(map, pos_player, f, pos_of_o);
        return (map);
    }
    if (map[pos_player[0]][pos_player[1] - 2] != '#' &&
    map[pos_player[0]][pos_player[1] - 2] != 'X') {
        map[pos_player[0]][pos_player[1] - 2] = 'X';
        map[pos_player[0]][pos_player[1] - 1] = 'P';
        map[pos_player[0]][pos_player[1]] = ' ';
    }
    map = the_o(map, pos_of_o);
    return (map);
}

char **if_xup(char **map, int *pos_player, int f, int *pos_of_o)
{
    if (map[pos_player[0] - 2][pos_player[1]] == 'O') {
        map[pos_player[0] - 2][pos_player[1]] = 'X';
        map[pos_player[0] - 1][pos_player[1]] = 'P';
        map[pos_player[0]][pos_player[1]] = ' ';
        wino(map, pos_player, f, pos_of_o);
        return (map);
    }
    if (map[pos_player[0] - 2][pos_player[1]] != '#' &&
    map[pos_player[0] - 2][pos_player[1]] != 'X') {
        map[pos_player[0] - 2][pos_player[1]] = 'X';
        map[pos_player[0] - 1][pos_player[1]] = 'P';
        map[pos_player[0]][pos_player[1]] = ' ';
    }
    map = the_o(map, pos_of_o);
    return (map);
}

char **if_xdown(char **map, int *pos_player, int f, int *pos_of_o)
{
    if (map[pos_player[0] + 2][pos_player[1]] == 'O') {
        map[pos_player[0] + 2][pos_player[1]] = 'X';
        map[pos_player[0] + 1][pos_player[1]] = 'P';
        map[pos_player[0]][pos_player[1]] = ' ';
        wino(map, pos_player, f, pos_of_o);
        return (map);
    }
    if (map[pos_player[0] + 2][pos_player[1]] != '#' &&
    map[pos_player[0] + 2][pos_player[1]] != 'X') {
        map[pos_player[0] + 2][pos_player[1]] = 'X';
        map[pos_player[0] + 1][pos_player[1]] = 'P';
        map[pos_player[0]][pos_player[1]] = ' ';
    }
    map = the_o(map, pos_of_o);
    return (map);
}

char **wino(char **map, int *pos_player, int f, int *pos_of_o)
{
    int nbX = 0;

    for (int g = 0; g != f; g++)
        for (int s = 0; s != my_strlentab(map, g); s++)
            if (map[g][s] == 'O')
                nbX = nbX + 1;
    if (nbX == 0) {
        clear();
        for (int i = 0; i != f; i++) {
            printw(map[i]);
        }
        printw("YOU WIN");
        refresh();
        exit(0);
    }
    return (map);
}
