/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Get files name.
** get_files
*/

#include "include/my.h"
#include "include/my_ls.h"

static int get_nb_files(int ac, char **av)
{
    struct stat lst;
    DIR *fd;
    int ans = 0;

    for (int i = 1; i < ac; i++) {
        fd = opendir(av[i]);
        if (fd == NULL && lstat(av[i], &lst) == 0)
            ans++;
        closedir(fd);
    }
    return ans;
}

static int get_nb_dir(int ac, char **av)
{
    struct stat lst;
    DIR *fd;
    int ans = 0;

    for (int i = 1; i < ac; i++) {
        fd = opendir(av[i]);
        if (fd != NULL)
            ans++;
        closedir(fd);
    }
    return ans;
}

static void set_struct(struct flags_list *flags)
{
    flags->total = flags->total + flags->file_name_ind + flags->dir_name_ind;
    if (flags->total == 0) {
        flags->dir_name[flags->dir_name_ind] = my_strdup(".");
        flags->dir_name_ind = flags->dir_name_ind + 1;
    }
}

int get_files_aux(struct flags_list *flags, int i, int ac, char **av)
{
    struct stat lst;
    DIR *fd;

    fd = opendir(av[i]);
    if (fd == NULL && lstat(av[i], &lst) == 0) {
        flags->file_name[flags->file_name_ind] = my_strdup(av[i]);
        flags->file_name_ind = flags->file_name_ind + 1;
    }
    if (fd != NULL) {
        flags->dir_name[flags->dir_name_ind] = my_strdup(av[i]);
        flags->dir_name_ind = flags->dir_name_ind + 1;
    }
    closedir(fd);
}

void get_files(struct flags_list *flags, int ac, char **av)
{
    struct stat lst;
    int nb_other = get_nb_other(ac, av);
    DIR *fd;

    flags->file_name = malloc(sizeof(char *) * (get_nb_files(ac, av) + 1));
    flags->dir_name = malloc(sizeof(char *) * (get_nb_dir(ac, av) + 1));
    flags->file_name[get_nb_files(ac, av)] = NULL;
    flags->dir_name[get_nb_dir(ac, av)] = NULL;
    for (int i = 1; i < ac; i++) {
        fd = opendir(av[i]);
        if (fd == NULL &&
        lstat(av[i], &lst) != 0 && av[i][0] != '-') {
            error_opening(av[i], &nb_other);
            flags->total++;
            flags->error = 84;
        }
        closedir(fd);
        get_files_aux(flags, i, ac, av);
    }
    set_struct(flags);
}
