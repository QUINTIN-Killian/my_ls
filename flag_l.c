/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** l flag functions.
** flag_l
*/

#include "include/my.h"
#include "include/my_ls.h"

void call_flag_l(char *file_path)
{
    struct stat lst;

    lstat(file_path, &lst);
    print_permissions(&lst);
    print_file_name(file_path);
}

void print_break(struct dirent *my_dir)
{
    if (my_dir != NULL)
        my_putchar('\n');
}

void flag_l_aux(DIR *fd, struct dirent *my_dir,
    struct flags_list *flags, int i)
{
    while (my_dir != NULL) {
        if (my_dir->d_name[0] == '.' && flags->a == 0) {
            my_dir = readdir(fd);
            continue;
        }
        call_flag_l(concat_str(3, flags->dir_name[i], "/", my_dir->d_name));
        my_dir = readdir(fd);
        print_break(my_dir);
    }
}

void flag_l_print_files(struct flags_list *flags)
{
    for (int i = 0; i < flags->file_name_ind; i++) {
        call_flag_l(flags->file_name[i]);
        if (i < flags->file_name_ind - 1)
            my_putchar('\n');
    }
}

int flag_l(struct flags_list *flags)
{
    DIR *fd;
    struct dirent *my_dir;

    flag_l_print_files(flags);
    if (flags->file_name_ind > 0 && flags->dir_name_ind > 0)
        my_putstr("\n\n");
    for (int i = 0; i < flags->dir_name_ind; i++) {
        if (flags->dir_name_ind > 0 && flags->total > 1) {
            my_putstr(flags->dir_name[i]);
            my_putstr(":\n");
        }
        print_total_flag_l(flags->dir_name[i]);
        fd = opendir(flags->dir_name[i]);
        my_dir = readdir(fd);
        flag_l_aux(fd, my_dir, flags, i);
        if (i < flags->dir_name_ind - 1)
            my_putstr("\n\n");
    }
    return flags->error;
}
