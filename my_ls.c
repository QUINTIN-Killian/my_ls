/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Works the same as ls.
** my_ls
*/

#include "include/my.h"
#include "include/my_ls.h"

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
    while (my_dir != NULL) {
        my_putstr(my_dir->d_name);
        my_putchar(' ');
        my_dir = readdir(fd);
    }
    closedir(fd);
    return 0;
}

int main(int ac, char **av)
{
    if (ac < 1 || ac > 3)
        return 84;
    if (ac == 1)
        return print_files(".");
    if (ac == 2)
        return print_files(av[1]);
    return 84;
}
