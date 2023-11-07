/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Prints multiple files
** print_multiple_files
*/

#include "include/my.h"
#include "include/my_ls.h"

int print_multiple_files(int ac, char **av)
{
    int nb_file_path = get_nb_file_path(ac, av);

    for (int i = 1; i < ac; i++) {
        if (!is_flag(av[i]) && nb_file_path == 1) {
            my_putstr(av[i]);
            my_putstr(":\n");
            print_files(av[i]);
            return 0;
        }
        if (!is_flag(av[i]) && nb_file_path > 1) {
            my_putstr(av[i]);
            my_putstr(":\n");
            print_files(av[i]);
            my_putstr("\n\n");
            nb_file_path--;
        }
    }
    return 1;
}
