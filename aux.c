/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Contains auxiliar functions.
** aux
*/

#include "include/my.h"
#include "include/my_ls.h"

int is_flag(char *str)
{
    return str[0] == '-';
}

int get_nb_flags(int ac, char **av)
{
    int ans = 0;

    for (int i = 1; i < ac; i++) {
        if (is_flag(av[i]))
            ans++;
    }
    return ans;
}

int get_ind_file_path(int ind, int ac, char **av)
{
    for (int i = ind; i < ac; i++) {
        if (!is_flag(av[i]))
            return i;
    }
    return 0;
}

int get_nb_file_path(int ac, char **av)
{
    int ans = 0;

    for (int i = 1; i < ac; i++) {
        if (!is_flag(av[i]))
            ans++;
    }
    return ans;
}

int no_file_path(int ac, char **av)
{
    for (int i = 1; i < ac; i++) {
        if (!is_flag(av[i]))
            return 0;
    }
    return 1;
}
