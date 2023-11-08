/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Prints multiple files
** print_multiple_files
*/

#include "include/my.h"
#include "include/my_ls.h"

int print_multiple_files(int ac, char **av, struct flags_list *flags)
{
    int nb_file_path = get_nb_file_path(ac, av);
    struct stat lst;

    for (int i = 1; i < ac; i++)
        if (!is_flag(av[i]) && lstat(av[i], &lst) != 0)
            nb_file_path--;
    for (int i = 1; i < ac; i++) {
        if (!is_flag(av[i]) && nb_file_path > 0 && lstat(av[i], &lst) == 0) {
            nb_file_path--;
            my_putstr(av[i]);
            my_putstr(":\n");
            print_files(av[i], flags);
        }
        if (!is_flag(av[i]) && nb_file_path > 0 && lstat(av[i], &lst) == 0)
            my_putstr("\n\n");
    }
    return 1;
}
