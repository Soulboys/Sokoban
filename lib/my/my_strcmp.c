/*
** EPITECH PROJECT, 2018
** cmp
** File description:
** cmp
*/

#include "../../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int	i = 0;
    if (my_strlen(s1) > my_strlen(s2)) {
        return (1);
    } else if (my_strlen(s1) == my_strlen(s2)) {
        while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
            i = i + 1;
        return (s1[i] - s2[i]);
    } else {
        return (-1);
    }
}
