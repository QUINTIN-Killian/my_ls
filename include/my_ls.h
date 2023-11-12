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
#include <pwd.h>
#include <time.h>
#include <errno.h>

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
    int error;
};

//my_ls.c :
int classic_ls(struct flags_list *flags);
int print_files(struct flags_list *flags);
int print_dir(struct flags_list *flags, DIR *fd,
    struct dirent *my_dir, int i);

//error_handling.c :
int error_opening(char *file_path, int *nb_other);

//aux.c :
int get_nb_other(int ac, char **av);
int is_flag(char *str);

//get_flags.c :
void get_flags(struct flags_list *flags, int ac, char **av);

//get_files.c :
void get_files(struct flags_list *flags, int ac, char **av);

//flag_d.c :
int flag_d(struct flags_list *flags);

//flag_r.c :
int flag_r(struct flags_list *flags);

//flag_l.c :
int flag_l(struct flags_list *flags);

//print_total_flag_l.c :
int print_total_flag_l(char *file_path);

//printing_flag_l.c :
void print_permissions(struct stat *lst);
void print_file_name(char *str);

//printing.c :
void printing(struct dirent *my_dir, char *file_path);

#endif
