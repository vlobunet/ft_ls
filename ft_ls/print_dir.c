#include "ft_ls.h"

void	print_dir(t_list *lst_dir, t_param lst_pr)
{
	DIR		*dir;
	int num;
	struct  dirent *file;

	num = (lst_dir->prev ? lst_dir->prev->num : lst_dir->num);
	while (num != lst_dir->num)
	{
		dir = opendir(lst_dir->content);
		file = readdir(dir);
		lst_dir = lst_dir->next;
	}
}
