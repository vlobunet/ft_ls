#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <dirent.h>

typedef struct		s_param
{
	int				l;
	int				R; // upper_r
	int				a;
	int				r;
	int				t;
	int				u;
	int				f;
	int				g;
}					t_param;

void	lst_print(t_list **lst);
#endif
