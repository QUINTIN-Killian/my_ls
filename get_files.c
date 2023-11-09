/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Get files name.
** get_files
*/

#include "include/my.h"
#include "include/my_ls.h"

int get_files_aux(struct flags_list *flags, int i, int ac, char **av)
{
    struct stat lst;

    if (opendir(av[i]) == NULL && lstat(av[i], &lst) == 0) {
        flags->file_name[flags->file_name_ind] = av[i];
        flags->file_name_ind = flags->file_name_ind + 1;
    }
    if (opendir(av[i]) != NULL) {
        flags->dir_name[flags->dir_name_ind] = av[i];
        flags->dir_name_ind = flags->dir_name_ind + 1;
    }
}

int get_files(struct flags_list *flags, int ac, char **av)
{
    struct stat lst;
    int error = 0;

    for (int i = 1; i < ac; i++) {
        if (opendir(av[i]) == NULL &&
        lstat(av[i], &lst) != 0 && av[i][0] != '-')
            error = error_opening(av[i], flags, i);
        get_files_aux(flags, i, ac, av);
    }
    flags->total = flags->file_name_ind + flags->dir_name_ind;
    if (flags->total == 0) {
        flags->dir_name[flags->dir_name_ind] = ".";
        flags->dir_name_ind = flags->dir_name_ind + 1;
    }
    return error;
}
