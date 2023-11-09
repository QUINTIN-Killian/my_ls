/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** r flag functions.
** flag_r
*/

#include "include/my.h"
#include "include/my_ls.h"

int get_nb_under_dir(struct flags_list *flags, int ind,
    int *nb_under_dir_not_hidden)
{
    DIR *fd;
    struct dirent *my_dir;
    int nb_under_dir = 0;

    fd = opendir(flags->dir_name[ind]);
    my_dir = readdir(fd);
    while (my_dir != NULL) {
        if (my_dir->d_name[0] != '.')
            *nb_under_dir_not_hidden = *nb_under_dir_not_hidden + 1;
        nb_under_dir++;
        my_dir = readdir(fd);
    }
    closedir(fd);
    return nb_under_dir;
}

static void print_spaces(struct flags_list *flags, int nb_under_dir,
    int nb_under_dir_not_hidden)
{
    if (nb_under_dir > 1 && flags->a == 1)
        my_putstr("  ");
    if (nb_under_dir > 1 && flags->a == 0 &&
    nb_under_dir_not_hidden > 0)
        my_putstr("  ");
}

int print_rev_files(struct flags_list *flags)
{
    for (int i = flags->file_name_ind - 1; i >= 0; i--) {
        my_putstr(flags->file_name[i]);
        if (i > 0)
            my_putstr("  ");
    }
    if (flags->dir_name_ind > 0 && flags->file_name_ind > 0)
        my_putstr("\n\n");
}

void print_under_dir(struct flags_list *flags, int ind)
{
    DIR *fd;
    struct dirent *my_dir;
    int nb_under_dir;
    int nb_under_dir_not_hidden = 0;

    nb_under_dir = get_nb_under_dir(flags, ind, &nb_under_dir_not_hidden);
    while (nb_under_dir > 0) {
        fd = opendir(flags->dir_name[ind]);
        for (int i = 0; i < nb_under_dir; i++)
            my_dir = readdir(fd);
        if (my_dir->d_name[0] == '.' && flags->a == 0) {
            nb_under_dir--;
            continue;
        }
        my_putstr(my_dir->d_name);
        nb_under_dir_not_hidden--;
        print_spaces(flags, nb_under_dir, nb_under_dir_not_hidden);
        closedir(fd);
        nb_under_dir--;
    }
}

int print_rev_dir(struct flags_list *flags)
{
    for (int i = flags->dir_name_ind - 1; i >= 0; i--) {
        if (flags->dir_name_ind + flags->file_name_ind > 1) {
            my_putstr(flags->dir_name[i]);
            my_putstr(":\n");
        }
        print_under_dir(flags, i);
        if (flags->dir_name_ind > 1 &&
        i > 0)
            my_putstr("\n\n");
    }
}

int flag_r(struct flags_list *flags)
{
    print_rev_files(flags);
    print_rev_dir(flags);
}
