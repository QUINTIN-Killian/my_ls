/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Contains auxiliar functions.
** aux
*/

#include "include/my.h"
#include "include/my_ls.h"

int get_nb_other(int ac, char **av)
{
    struct stat lst;
    int ans = 0;

    for (int i = 1; i < ac; i++)
        if (opendir(av[i]) == NULL &&
        lstat(av[i], &lst) != 0 && av[i][0] != '-')
            ans++;
    return ans;
}

int is_flag(char *str)
{
    return str[0] == '-';
}
