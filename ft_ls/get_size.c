#include "ft_ls.h"

void	get_size_errorhandling(t_size *size, t_list *cur)
{
	if (getpwuid(cur->st_uid))
		size->userspace = (int)ft_strlen(getpwuid(cur->st_uid)->pw_name) \
			> size->userspace ? (int)ft_strlen(getpwuid(cur->st_uid)->pw_name) \
			: size->userspace;
	else
		size->userspace = (int)ft_strlen(ft_itoa(cur->st_uid)) \
			> size->userspace ? (int)ft_strlen(ft_itoa(cur->st_uid)) \
			: size->userspace;
	if (getgrgid(cur->st_gid))
		size->groupspace = (int)ft_strlen(getgrgid(cur->st_gid)->gr_name) \
			> size->groupspace ? \
			(int)ft_strlen(getgrgid(cur->st_gid)->gr_name) : size->groupspace;
	else
		size->groupspace = (int)ft_strlen(ft_itoa(cur->st_gid)) \
			> size->groupspace ? (int)ft_strlen(ft_itoa(cur->st_gid)) \
			: size->groupspace;
}

void	get_size_quick(t_size *size, t_list *lst)
{
	size->linkspace = (int)ft_strlen(ft_itoa(lst->st_nlink)) > \
		size->linkspace ? (int)ft_strlen(ft_itoa(lst->st_nlink)) \
		: size->linkspace;
	size->maj = (int)ft_strlen(ft_itoa(major(lst->st_rdev))) > size->maj \
		? (int)ft_strlen(ft_itoa(major(lst->st_rdev))) : size->maj;
	size->min = (int)ft_strlen(ft_itoa(minor(lst->st_rdev))) > size->min ? \
		(int)ft_strlen(ft_itoa(minor(lst->st_rdev))) : size->min;
	size->size = (int)ft_strlen(ft_itoa(lst->st_size)) > size->size ? \
		(int)ft_strlen(ft_itoa(lst->st_size)) : size->size;
	size->total += lst->st_blocks;
}

t_size	get_size(t_param arg, t_list *lst)
{
	t_size	size;
	int num;

	size = (t_size){0, 0, 0, 0, 0, 0, 0};
	if (lst->prev)
	{
		num = lst->prev->num;
		while (num != lst->num)
		{
			if (!(arg.a == 0 && lst->content[0] == '.'))
			{
				get_size_quick(&size, lst);
				get_size_errorhandling(&size, lst);
			}
			lst = lst->next;
		}
	}
	if (!(arg.a == 0 && lst->content[0] == '.'))
	{
		get_size_quick(&size, lst);
		get_size_errorhandling(&size, lst);
	}
	return (size);
}
