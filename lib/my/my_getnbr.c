/*
** EPITECH PROJECT, 2018
** getnbr
** File description:
** it is a getnbr
*/

#include "../../include/my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int negga = 0;
    int result = 0;

    while (str[i] < '0' || str[i] > '9') {
        if (str[i] == '\0')
            return (0);
        i++;
    }
    for (int sperm = 1; str[i - sperm] == '+' || str[i - sperm] == '-'; sperm++) {
        if (str[i - sperm] == '-' && negga != 0)
            negga = 0;
        else if (str[i - sperm] == '-' && negga == 0)
            negga = 1;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10;
        result = result + str[i] - '0';
        i++;
    }
    if (negga)
        result = result * -1;
    return (result);
}
