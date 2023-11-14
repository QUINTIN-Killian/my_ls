/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Get under dir.
** get_under_dir
*/

#include "include/my.h"
#include "include/my_ls.h"

int get_nb_elt(struct flags_list *flags, int ind)
{
    DIR *fd;
    struct dirent *my_dir;
    int nb_elt = 0;

    fd = opendir(flags->dir_name[ind]);
    my_dir = readdir(fd);
    while (my_dir != NULL) {
        if (my_dir->d_name[0] == '.' && flags->a == 0) {
            my_dir = readdir(fd);
            continue;
        }
        nb_elt++;
        my_dir = readdir(fd);
    }
    closedir(fd);
    return nb_elt;
}

void alloc_under_dir(struct flags_list *flags, int ind)
{
    int nb_elt = get_nb_elt(flags, ind);

    flags->under_dir_name = malloc(sizeof(char *) * (nb_elt + 1));
    flags->under_dir_name[nb_elt] = NULL;
    flags->under_dir_name_ind = 0;
}

void get_under_dir(struct flags_list *flags, int ind)
{
    DIR *fd;
    struct dirent *my_dir;

    free_under_dir(flags);
    alloc_under_dir(flags, ind);
    fd = opendir(flags->dir_name[ind]);
    my_dir = readdir(fd);
    while (my_dir != NULL) {
        if (my_dir->d_name[0] == '.' && flags->a == 0) {
            my_dir = readdir(fd);
            continue;
        }
        flags->under_dir_name[flags->under_dir_name_ind] =
        my_strdup(my_dir->d_name);
        flags->under_dir_name_ind++;
        my_dir = readdir(fd);
    }
    closedir(fd);
}
