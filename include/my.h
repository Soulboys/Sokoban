/*
** EPITECH PROJECT, 2018
** include
** File description:
** create an include
*/

#ifndef MY_H_
#define MY_H_

void my_putchar(char c);
int my_putstr (char const *str);
char *my_revstr (char *str);
char *my_strcpy(char const *src);
int my_strlen(char const *str);
int my_strlen2(char const *str, int i);
int my_strcmp(char const *s1, char const *s2);
int my_getnbr(char const *str);
char *my_strdup(char const *src);
char *openfile(char *filepath);
int game(char **map, char **reset, int f, int *pos_of_o);
char **keypress(char **map, int ch, char **reset, int f, int *pos_of_o);
int main(int argc, char **argv);
char **moveleft(char **map, int *pos_player,int f, int *pos_of_o);
char **moveright(char **map, int *pos_player, int f, int *pos_of_o);
char **moveup(char **map, int *pos_player, int f, int *pos_of_o);
char **movedown(char **map, int *pos_player, int f, int *pos_of_o);
char **if_xright(char **map, int *pos_player, int f, int *pos_of_o);
char **if_xleft(char **map, int *pos_player, int f, int *pos_of_o);
char **if_xup(char **map, int *pos_player, int f, int *pos_of_o);
char **if_xdown(char **map, int *pos_player, int f, int *pos_of_o);
char **wino(char **map, int *pos_player, int f, int *pos_of_o);
void ifloose(char **map, int *pos_of_o, int f);
char **strtotab(char *str, int *f);
int my_strlen3(char *str);
int my_strlentab(char **tab, int j);
int my_tablen_line(char **tab);
int *pos_o(char **map, int f);
char **the_o(char **map, int *pos_of_o);
int *getInt(char **map, int f);
void help(void);

#endif
