/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** d flag functions.
** flag_d
*/

#include "include/my.h"
#include "include/my_ls.h"

int my_print(char *str, int nb_file_path)
{
    my_putstr(str);
    if (nb_file_path > 0)
        my_putstr("  ");
}

int flag_d(int ac, char **av)
{
    int nb_file_path = get_nb_file_path(ac, av);
    struct stat lst;

    if (nb_file_path == 0) {
        my_putstr(".");
        return 0;
    }
    for (int i = 1; i < ac; i++)
        if (!is_flag(av[i]) && lstat(av[i], &lst) != 0)
            nb_file_path--;
    for (int i = 1; i < ac; i++) {
        if (!is_flag(av[i]) && lstat(av[i], &lst) == 0) {
            nb_file_path--;
            my_print(av[i], nb_file_path);
        }
    }
    return 0;
}
