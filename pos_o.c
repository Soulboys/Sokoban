/*
** EPITECH PROJECT, 2018
** PSU_my_sokoban_2018
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include "include/my.h"

int *pos_o(char **map, int f)
{
    int nbO = 0;
    int *pos_of_o;
    int i = 0;

    for (int g = 0; g != f; g++)
        for (int s = 0; s != my_strlentab(map, g); s++)
            if (map[g][s] == 'O') {
                nbO = nbO + 1;
            }
    pos_of_o = malloc(sizeof(int) * nbO * 2);
    for (int d = 0; d != f; d++) {
        for (int q = 0; q != my_strlentab(map, d); q++) {
            if (map[d][q] == 'O') {
                pos_of_o[i] = d;
                pos_of_o[i + 1] = q;
                i = i + 2;
            }
        }
    }
    return(pos_of_o);
}

char **the_o(char **map, int *pos_of_o)
{
    int i = 0;

    for (; pos_of_o[i]; i = i + 2 ) {
        if (map[pos_of_o[i]][pos_of_o[i + 1]] == ' ')
            map[pos_of_o[i]][pos_of_o[i + 1]] = 'O';
    }
    return (map);
}

void help(void)
{
    char str[] = "USAGE\n";
    char str1[] = "    ./my_sokoban map\n";
    char str2[] = "DESCRIPTION\n";
    char str3[] = "    map file representing the warehouse map,";
    char str4[] = "containing ‘#’ for walls,\n";
    char str5[] = "    ‘P’ for the player, ‘X’ ";
    char str6[] = "for boxes and ‘O’ for storage locations.\n";

    my_putstr(str);
    my_putstr(str1);
    my_putstr(str2);
    my_putstr(str3);
    my_putstr(str4);
    my_putstr(str5);
    my_putstr(str6);
}
