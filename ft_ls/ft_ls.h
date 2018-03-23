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

# define MAJOR(x)((int32_t)(((u_int32_t)(x) >> 24) & 0xff))
# define MINOR(x)((int32_t)((x) & 0xffffff))

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
void	ft_lstadd_s(t_list **cur, char *new_lst);
void	ft_parsing(int argc, char **argv, t_list **lst_dr, t_param *lst_pr);
t_list	*ft_lstnew_el(int num, char *str, t_param p, char *path);
t_size	get_size(t_param arg, t_list *files);
void	ft_access(t_list *lst);
void	print_lnk(t_list *lst, int x);
void	print_uid(t_list *lst);
void	print_gid(t_list *lst);
void	print_size(t_list *lst);
void	print_date(time_t date);
void	print_error_el(t_list *lst_err);
void	ft_error_name(char *name, char *error, int ex);
void ls_long_file (t_list *lst, t_param p, t_size size);
void go_to_start(t_list **lst);
void	print_ls_lg(t_list *file, t_param lst_pr, int m);
void	print_ls_lgr(t_list *file, t_param lst_pr, int m);
void	print_fie(t_list *file, t_param lst_pr, int i);
void ft_lstdel_el(t_list **lst);
#endif
