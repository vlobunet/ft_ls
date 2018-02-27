#include "ft_ls.h"

void ft_ls (const char *dir_name)
{
	DIR *d;
	struct dirent *entry;
	const char *d_name;

	(dir_name == NULL) ? (dir_name = ".") : 0;
	d = opendir(dir_name);
	if (!d)
		printf("ft_ls: %s: No such file or directory\n", dir_name);
	else
	{
		printf("%s:\n", dir_name);
		while (1)
		{
			entry = readdir(d);
			if (!entry)
				break ;
			d_name = entry->d_name;
			(d_name[0] != '.') ? (printf("%s\n", d_name)) : 0;
			// printf("%s\n", d_name);
		}
		printf("\n");
		if (closedir (d))
			printf("Could not close '%s'\n", dir_name);
	}
}

int ft_ch_dr (const char *dir_name)
{
	DIR *d;

	d = opendir(dir_name);
	if (!d)
		return (0);
	else
		return (1);
}

void    ft_lstadd_s(t_list **cur, char *new_lst)
{
    int num;

	if (!*cur)
		return ;
	if ((strcmp((*cur)->content, (*cur)->next->content) == 0) 
		&& ((*cur)->num == (*cur)->next->num))
			return ;
	// printf("%s ", (*cur)->content);
	while (strcmp((*cur)->content, (*cur)->next->content) > 0)
	{
		*cur = (*cur)->next;
		// printf(">>>> %s", (*cur)->content);
	}	
	num = (*cur)->prev->num;
	while ((*cur)->num != num 
		&& strcmp((*cur)->content, new_lst) < 0 
		&& strcmp((*cur)->content, (*cur)->next->content) < 0)
	{
		*cur = (*cur)->next;
		// printf(">> %s", (*cur)->content);
	}
	if (strcmp((*cur)->content, new_lst) > 0)
	{
		*cur = (*cur)->prev;
		// printf(" << %s", (*cur)->content); 
	}
}


void	lst_print(t_list **lst)
{
	printf(" %s", (*lst)->content);
}

int main(int argc, char **argv)
{
	int	i;

	t_list	*lst_param;
	// t_list	*lst_dr;
	// t_list	*lst_error;
	i = 1;

	if (argc == 1)
		ft_ls(".");
	else
	{
		argv++;
		while (i < argc && (*argv)[0] == '-' && (*argv)[1] != '\0')
		{
			// printf(" -> %s\n", *argv);
			ft_lstadd_s(&lst_param, *argv);
			// printf("\n*\n");
			ft_lstadd(&lst_param, ft_lstnew(i++, *argv++));
		}
		lst_print(&lst_param);
		lst_param = lst_param->next;
		lst_print(&lst_param);
		lst_param = lst_param->next;
		lst_print(&lst_param);
		lst_param = lst_param->next;
		lst_print(&lst_param);
		lst_param = lst_param->next;
		lst_print(&lst_param);
		lst_param = lst_param->next;
		lst_print(&lst_param);
		lst_param = lst_param->next;
		lst_print(&lst_param);
		lst_param = lst_param->next;
		lst_print(&lst_param);
		lst_param = lst_param->next;
		lst_print(&lst_param);
		lst_param = lst_param->next;
		lst_print(&lst_param);
		lst_param = lst_param->next;
		lst_print(&lst_param);
		lst_param = lst_param->next;
		lst_print(&lst_param);
		lst_param = lst_param->next;
		// printf("\n%d\n", strcmp("t4", "t5"));

		
		// while (i < argc)
		// {
		// 	if (!ft_ch_dr(*argv))
		// 		ft_lstadd(&lst_error, ft_lstnew(i++, *argv++));
		// 	else
		// 		ft_lstadd(&lst_dr, ft_lstnew(i++, *argv++));
		// }
	}
	return 0;
}