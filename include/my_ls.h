/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** my_ls's header.
** my_ls
*/

#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <sys/stat.h>

#ifndef MY_LS_H_
    #define MY_LS_H_

struct flags_list {
    int a;
    int l;
    int r_maj;
    int d;
    int r;
    int t;
};

//my_ls.c :
int print_files(char *file_path, struct flags_list *flags);

//error_handling.c :
int error_handling(int ac, char **av);

//aux.c :
int is_flag(char *str);
int get_nb_flags(int ac, char **av);
int get_ind_file_path(int ind, int ac, char **av);
int get_nb_file_path(int ac, char **av);
int no_file_path(int ac, char **av);

//flags.c :
int get_flags(struct flags_list *flags, int ac, char **av);

//print_multiple_files.c :
int print_multiple_files(int ac, char **av, struct flags_list *flags);

//flag_d.c :
int flag_d(int ac, char **av);

//printing.c :
void printing(struct dirent *my_dir, char *file_path);

#endif
