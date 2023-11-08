/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Error handling.
** error_handling
*/

#include "include/my.h"
#include "include/my_ls.h"

int error_printing(char *str, int nb_file_path)
{
    write(2, "ls: impossible d'accéder à '", 30);
    write(2, str, my_strlen(str));
    write(2, "' : Aucun fichier ou dossier de ce type", 39);
    if (nb_file_path != 0)
        my_putchar('\n');
    return 0;
}

int error_handling(int ac, char **av)
{
    int nb_file_path = get_nb_file_path(ac, av);
    struct stat lst;
    int a = 0;

    for (int i = 1; i < ac; i++) {
        if (!is_flag(av[i]) && lstat(av[i], &lst) != 0) {
            nb_file_path--;
            error_printing(av[i], nb_file_path);
            a = 84;
        }
    }
    return a;
}
