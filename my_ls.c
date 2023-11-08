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

int print_files_aux(DIR *fd, struct dirent *my_dir,
    struct flags_list *flags, char *file_path)
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

int print_files(char *file_path, struct flags_list *flags)
{
    DIR *fd;
    struct dirent *my_dir;

    fd = opendir(file_path);
    if (fd == NULL) {
        write(2, "File not found", 14);
        return 84;
    }
    my_dir = readdir(fd);
    print_files_aux(fd, my_dir, flags, file_path);
    closedir(fd);
    return 0;
}

int main(int ac, char **av)
{
    struct flags_list flags;
    int error = error_handling(ac, av);

    initialize_struct(&flags);
    get_flags(&flags, ac, av);
    if (flags.d == 1)
        flag_d(ac, av);
    if (error == 84)
        return 84;
    if (get_nb_file_path(ac, av) == 0)
        print_files(".", &flags);
    if (get_nb_file_path(ac, av) == 1)
        print_files(av[get_ind_file_path(1, ac, av)], &flags);
    if (get_nb_file_path(ac, av) > 1)
        print_multiple_files(ac, av, &flags);
    if (error == 84)
        return 84;
    return 0;
}
