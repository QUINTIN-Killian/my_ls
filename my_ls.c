/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Works the same as ls.
** my_ls
*/

#include "include/my.h"
#include "include/my_ls.h"

int initialize_struct(struct flags_list *flags)
{
    flags->a = 0;
    flags->l = 0;
    flags->r_maj = 0;
    flags->d = 0;
    flags->r = 0;
    flags->t = 0;
    return 0;
}

int print_files_aux(DIR *fd, struct dirent *my_dir)
{
    while (my_dir != NULL) {
        if (my_dir->d_name[0] == '.' ||
        my_dir->d_name[my_strlen(my_dir->d_name) - 1] == '~') {
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

int print_files(char *file_path)
{
    DIR *fd;
    struct dirent *my_dir;

    fd = opendir(file_path);
    if (fd == NULL) {
        write(2, "File not found", 14);
        return 84;
    }
    my_dir = readdir(fd);
    print_files_aux(fd, my_dir);
    closedir(fd);
    return 0;
}

int main(int ac, char **av)
{
    struct flags_list flags;

    initialize_struct(&flags);
    get_flags(&flags, ac, av);
    if (ac < 1)
        return 84;
    if (get_nb_flags(ac, av) == 0) {
        if (no_file_path(ac, av))
            return print_files(".");
        if (get_nb_file_path(ac, av) == 1)
            print_files(av[get_ind_file_path(1, ac, av)]);
        if (get_nb_file_path(ac, av) > 1)
            print_multiple_files(ac, av);
    }
    return 0;
}
