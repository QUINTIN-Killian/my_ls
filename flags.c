/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Flags recognition functions.
** flags
*/

#include "include/my.h"
#include "include/my_ls.h"

int is_correct_flag(char flag)
{
    if (flag == 'a' || flag == 'l' || flag == 'R' ||
    flag == 'd' || flag == 'r' || flag == 't')
        return 1;
    return 0;
}

int add_flag_in_struct(struct flags_list *flags, char flag)
{
    if (flag == 'a')
            flags->a = 1;
    if (flag == 'l')
            flags->l = 1;
    if (flag == 'R')
            flags->r_maj = 1;
    if (flag == 'd')
            flags->d = 1;
    if (flag == 'r')
            flags->r = 1;
    if (flag == 't')
            flags->t = 1;
    return 0;
}

int cpy_flags(struct flags_list *flags, char *str)
{
    for (int i = 0; i < my_strlen(str); i++) {
        add_flag_in_struct(flags, str[i]);
    }
    return 0;
}

int get_flags(struct flags_list *flags, int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (is_flag(av[i]))
            cpy_flags(flags, av[i]);
    }
}
