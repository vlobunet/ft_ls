#include "ft_ls.h"

void	ft_print_recurs2(t_param lst_pr, char *path)
{
	DIR		*dir;
	t_list	*files;

	char *a;

	ft_putchar('\n');
	ft_putstr(path);
	ft_putstr(":\n");
	if ((dir = opendir(path)) != NULL)
	{
		a = ft_strjoin(path, "/");
		while (1)
			if (!(get_elem(&files, readdir(dir), a, lst_pr)))
				break ;
		closedir(dir);
		free(a);
		if (files)
			print_fie(files, lst_pr, 1);
		files = NULL;
	}
	else
		ft_error_name("ft_ls: ", path, 0);
}

int ft_cheack(char *content, char *path, t_param lst_pr)
{
	if (content && path && \
			ft_strcmp(".", content) && \
			ft_strcmp("..", content) && \
			!(lst_pr.a == 0 && content[0] == '.'))
		return (1);
	return (0);
}

void ft_print_recurs1(t_list *file, t_param lst_pr)
{
	int num;

	if (file->prev)
	{
		go_to_start(&file);
		num = file->prev->num;
		while (num != file->num)
		{
			ft_cheack(file->content, file->path, lst_pr) ? ft_print_recurs2(lst_pr, file->path) : 0;
			file = file->next;
		}
	}
	ft_cheack(file->content, file->path, lst_pr) ? ft_print_recurs2(lst_pr, file->path) : 0;
}