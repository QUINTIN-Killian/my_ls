/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Works the same as ls.
** my_ls
*/
/*
NOTES ET OBJECTIFS :
    - recréer affichage de plusieurs dir
    - demander Loïc son printing en couleur
    - error handling si le file name ou dir name n'existe pas
*/

#include "include/my.h"
#include "include/my_ls.h"

int print_files(struct flags_list *flags)
{
    for (int i = 0; i < flags->file_name_ind; i++) {
        my_putstr(flags->file_name[i]);
        if (i < flags->file_name_ind - 1)
            my_putstr("  ");
        if (i == flags->file_name_ind - 1 && flags->dir_name_ind > 0)
            my_putstr("\n\n");
    }
    return 0;
}

int print_dir_aux(struct flags_list *flags, DIR *fd,
    struct dirent *my_dir)
{
    while (my_dir != NULL) {
        if (my_dir->d_name[0] == '.' && flags->a == 0) {
            my_dir = readdir(fd);
            continue;
        }
        my_putstr(my_dir->d_name);
        my_dir = readdir(fd);
        if (my_dir != NULL)
            my_putstr("  ");
    }
    return 0;
}

int print_dir(struct flags_list *flags, DIR *fd,
    struct dirent *my_dir, int i)
{
    fd = opendir(flags->dir_name[i]);
    if (flags->total > 1) {
        my_putstr(flags->dir_name[i]);
        my_putstr(":\n");
    }
    my_dir = readdir(fd);
    print_dir_aux(flags, fd, my_dir);
    if (flags->dir_name_ind + flags->file_name_ind > 1 &&
    i < flags->dir_name_ind - 1)
        my_putstr("\n\n");
    closedir(fd);
    return 0;
}

int classic_ls(struct flags_list *flags)
{
    DIR *fd;
    struct dirent *my_dir;

    print_files(flags);
    for (int i = 0; i < flags->dir_name_ind; i++)
        print_dir(flags, fd, my_dir, i);
    return 0;
}
