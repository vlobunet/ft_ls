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

// int ft_ch_dr (const char *dir_name)
// {
// 	DIR *d;

// 	d = opendir(dir_name);
// 	if (!d)
// 		return (0);
// 	else
// 		return (1);
// }
// void	lst_print(t_list **lst)
// {
// 	printf(" %s", (*lst)->content);
// }

void    ft_lstadd_s(t_list **cur, char *new_lst)
{
	int num;

	if (!*cur || (!(*cur)->next))
		return ;
	while (strcmp((*cur)->content, (*cur)->next->content) < 0)
		*cur = (*cur)->next;
	if (strcmp(new_lst, (*cur)->next->content) < 0)
		return ;
	num = (*cur)->num;
	*cur = (*cur)->next;
	while (strcmp(new_lst, (*cur)->content) > 0 && num != (*cur)->num)
		*cur = (*cur)->next;
	if (strcmp(new_lst, (*cur)->content) < 0)
		*cur = (*cur)->prev;
}

int		ft_ch_sumb(char *str, char s)
{
	while (*str)
		if (s == *str++)
			return (1);
	return (0);
}

void	ft_get_pr(t_param *lst_pr, char *param)
{
	int		i;

	i = 1;
	while (param[i])
	{
		if (ft_ch_sumb("1lRafgrtu", param[i]))
		{
			param[i] == 'l' ? lst_pr->l = 1 : 0;
			param[i] == 'R' ? lst_pr->R = 1 : 0;
			param[i] == 'a' ? lst_pr->a = 1 : 0;
			param[i] == 'r' ? lst_pr->r = 1 : 0;
			param[i] == 't' ? lst_pr->t = 1 : 0;
			param[i] == 'u' ? lst_pr->u = 1 : 0;
			param[i] == 'f' ? lst_pr->f = 1 : 0;
			param[i] == 'g' ? lst_pr->g = 1 : 0;
			i++;
		}
		else printf("ERROR_PARAM\n");
	}
}

void	ft_parsing(int argc, char **argv, t_list **lst_dr, t_param *lst_pr)
{
	int	i = 0;

	argv++;
	while (i < (argc - 1) && (*argv)[0] == '-' && (*argv)[1])
	{
		ft_get_pr(lst_pr, *argv++);
		i++;
	}
	while (i < argc - 1)
	{
		ft_lstadd_s(lst_dr, *argv);
		ft_lstadd(lst_dr, ft_lstnew(i++, *argv++));
	}
}



int main(int argc, char **argv)
{

	t_list	*lst_dr;
	t_param lst_pr;

	lst_pr = (t_param){0, 0, 0, 0, 0, 0, 0, 0};
	lst_dr = NULL;

	if (argc == 1)
		ft_ls(".");
	else
	{
		ft_parsing(argc, argv, &lst_dr, &lst_pr);
		if (lst_dr == NULL)
			printf("no dr\n");
		lst_pr.l == 1 ? printf("lst_pr.l == 1\n") : 0;
		lst_pr.R == 1 ? printf("lst_pr.R == 1\n") : 0;
		lst_pr.a == 1 ? printf("lst_pr.a == 1\n") : 0;
		lst_pr.r == 1 ? printf("lst_pr.r == 1\n") : 0;
		lst_pr.t == 1 ? printf("lst_pr.t == 1\n") : 0;
		lst_pr.u == 1 ? printf("lst_pr.u == 1\n") : 0;
		lst_pr.f == 1 ? printf("lst_pr.f == 1\n") : 0;
		lst_pr.g == 1 ? printf("lst_pr.g == 1\n") : 0;
	}
	return 0;
}
		// argv++;
		// while (i < argc && (*argv)[0] == '-' && (*argv)[1] != '\0')
		// 	ft_lstadd(&lst_param, ft_lstnew(i++, *argv++));
		// while (i < argc)
		// {
		// 	if (!ft_ch_dr(*argv))
		// 	{
		// 		ft_lstadd_s(&lst_error, *argv);
		// 		ft_lstadd(&lst_error, ft_lstnew(i++, *argv++));
		// 	}
		// 	else
		// 	{
		// 		ft_lstadd_s(&lst_dr, *argv);
		// 		ft_lstadd(&lst_dr, ft_lstnew(i++, *argv++));
		// 	}
		// }