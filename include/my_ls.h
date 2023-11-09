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
    char *file_name[4000];
    int file_name_ind;
    char *dir_name[4000];
    int dir_name_ind;
    int total;
};

//my_ls.c :
int classic_ls(struct flags_list *flags);
int print_files(struct flags_list *flags);
int print_dir(struct flags_list *flags, DIR *fd,
    struct dirent *my_dir, int i);

//error_handling.c :
int error_opening(char *file_path, struct flags_list *flags, int i);

//aux.c :
int is_flag(char *str);
//int get_nb_flags(int ac, char **av);
//int get_ind_file_path(int ind, int ac, char **av);
//int get_nb_file_path(int ac, char **av);
//int no_file_path(int ac, char **av);

//get_flags.c :
int get_flags(struct flags_list *flags, int ac, char **av);

//get_files.c :
int get_files(struct flags_list *flags, int ac, char **av);

//flag_d.c :
int flag_d(struct flags_list *flags);

//printing.c :
void printing(struct dirent *my_dir, char *file_path);

#endif
