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

char **moveright(char **map, int *pos_player, int f, int *pos_of_o)
{
    if (map[pos_player[0]][pos_player[1] + 1] == 'X') {
        map = if_xright(map, pos_player, f, pos_of_o);
        return (map);
    }
    if (map[pos_player[0]][pos_player[1]] == 'P' &&
        map[pos_player[0]][pos_player[1] + 1] != '#') {
        map[pos_player[0]][pos_player[1] + 1] = 'P';
        map[pos_player[0]][pos_player[1]] = ' ';
    }
    map = the_o(map, pos_of_o);
    return (map);
}

char **moveleft(char **map, int *pos_player, int f, int *pos_of_o)
{
    if (map[pos_player[0]][pos_player[1] - 1] == 'X') {
        map = if_xleft(map, pos_player, f, pos_of_o);
        return (map);
    }
    if (map[pos_player[0]][pos_player[1]] == 'P' &&
        map[pos_player[0]][pos_player[1] - 1] != '#') {
        map[pos_player[0]][pos_player[1] - 1] = 'P';
        map[pos_player[0]][pos_player[1]] = ' ';
    }
    map = the_o(map, pos_of_o);
    return (map);
}

char **moveup(char **map, int *pos_player, int f, int *pos_of_o)
{
    if (map[pos_player[0] - 1][pos_player[1]] == 'X') {
        map = if_xup(map, pos_player, f, pos_of_o);
        return (map);
    }
    if (map[pos_player[0]][pos_player[1]] == 'P' &&
        map[pos_player[0] - 1][pos_player[1]] != '#') {
        map[pos_player[0] - 1][pos_player[1]] = 'P';
        map[pos_player[0]][pos_player[1]] = ' ';
    }
    map = the_o(map, pos_of_o);
    return (map);
}

char **movedown(char **map, int *pos_player, int f, int *pos_of_o)
{
    if (map[pos_player[0] + 1][pos_player[1]] == 'X') {
        map = if_xdown(map, pos_player, f, pos_of_o);
        return (map);
    }
    if (map[pos_player[0]][pos_player[1]] == 'P' &&
        map[pos_player[0] + 1][pos_player[1]] != '#') {
        map[pos_player[0] + 1][pos_player[1]] = 'P';
        map[pos_player[0]][pos_player[1]] = ' ';
    }
    map = the_o(map, pos_of_o);
    return (map);
}

void ifloose(char **map, int *pos_of_O, int f)
{
    int g = 0;
    int s = 0;

    for (; g != f; g++) {
        for (; s != my_strlentab(map, g); s++) {
            if (map[g][s] == 'X') {
                if (map[g + 1][s] == '#' && map[g][s + 1] == '#')
                    exit(1);
                else if (map[g][s + 1] == '#' && map[g - 1][s] == '#')
                    exit(1);
                if (map[g][s - 1] == '#' && map[g + 1][s] == '#')
                    exit(1);
                else if (map[g][s - 1] == '#' && map[g - 1][s] == '#')
                    exit(1);
            }
        }
    }
}
