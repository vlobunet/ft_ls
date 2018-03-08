#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/includes/libft.h"
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>

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

void	ft_ls(const char *dir_name);
void	ft_get_pr(t_param *lst_pr, char *param);
void	ft_lstadd_s(t_list **cur, char *new_lst);
void	ft_parsing(int argc, char **argv, t_list **lst_dr, t_param *lst_pr);
#endif
