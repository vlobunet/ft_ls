#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/includes/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <time.h>
# include <stdio.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
#include <sys/xattr.h>


#define C_RESET		"\033[0m"
#define C_ERROR		"\033[0;31m"
#define C_GREEN		"\033[0;32m"
#define C_YELLO		"\033[0;33m"
#define C_SINIY		"\033[0;34m"
#define C_FIOLE		"\033[0;35m"
#define C_GOLYB		"\033[0;36m"
#define C_ROZOV		"\033[0;37m"


typedef struct		s_lst
{
	char			*content;
	char			*path;
	int				num;
	time_t			date;
	mode_t			st_mode;
	nlink_t			st_nlink;
	uid_t			st_uid;
	gid_t			st_gid;
	off_t			st_size;
	quad_t			st_blocks;
	dev_t			st_rdev;
	struct s_lst	*prev;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_param
{
	int				l;
	int				R;
	int				a;
	int				r;
	int				t;
	int				u;
	int				f;
	int				g;
	int				G;
}					t_param;

typedef struct		s_size
{
	int				total;
	int				size;
	int				groupspace;
	int				userspace;
	int				linkspace;
	int				min;
	int				maj;
}					t_size;


void	ft_ls(const char *dir_name);
void	ft_get_pr(t_param *lst_pr, char *param);
void	ft_lstadd_s(t_lst **cur, char *new_lst);
void	ft_parsing(int argc, char **argv, t_lst **lst_dr, t_param *lst_pr);
t_lst	*ft_lstnew_el(int num, char *str, t_param p, char *path);
t_size	get_size(t_param arg, t_lst *files);
void	ft_access(t_lst *lst);
void	print_lnk(t_lst *lst, int x);
void	print_uid(t_lst *lst);
void	print_gid(t_lst *lst);
void print_size(t_lst *lst, int x);
void	print_date(time_t date);
void	print_error_el(t_lst *lst_err, t_param pr);
void	ft_error_name(char *name, char *error, int ex);
void ls_long_file (t_lst *lst, t_param p, t_size size);
void go_to_start(t_lst **lst);
void	print_ls_lg(t_lst *file, t_param lst_pr, int m);
void	print_ls_lgr(t_lst *file, t_param lst_pr, int m);
void	print_fie(t_lst *file, t_param lst_pr, int i);
void ft_lstdel_el(t_lst **lst);
int ft_numlen(int num);
void ft_print_recurs1(t_lst *file, t_param lst_pr);
int get_elem(t_lst **lst, struct dirent *file, char *path, t_param param);
void    ft_lstad(t_lst **alst, t_lst *new_lst);
void ft_print_recurs1r(t_lst *file, t_param lst_pr);
#endif
