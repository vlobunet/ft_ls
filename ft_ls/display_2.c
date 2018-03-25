#include "ft_ls.h"

void	print_date(time_t date)
{
	char	*str1;
	time_t	t;

	t = time(0);
	str1 = ctime(&date);
	if ((t - 15778463) > date || t < date)
		str1 = ft_strjoin(ft_strjoin(ft_strsub(str1, 4, 6), "  "), ft_strsub(str1, 20, 4));
	else
		str1 = ft_strsub(str1, 4, 12);
	str1[12] = '\0';
	ft_putchar(' ');
	ft_putstr(str1);
	ft_putchar(' ');
	free(str1);
}

void	print_error_el(t_lst *lst_err, t_param pr)
{
	DIR		*d;
	int num;
	pr.G == 1 ? ft_putstr(C_ERROR) : 0;
	if (lst_err->next)
	{
		while (ft_strcmp(lst_err->content, lst_err->next->content) < 0)
			lst_err =lst_err->next;
		lst_err =lst_err->next;
		num = lst_err->prev->num;
		while (num != lst_err->num)
		{
			if ((d = opendir(lst_err->content)) == NULL && errno != ENOTDIR)
				ft_error_name("ft_ls: ", lst_err->content, 0);
			lst_err =lst_err->next;
		}
	}
	if ((d = opendir(lst_err->content)) == NULL && errno != ENOTDIR)
				ft_error_name("ft_ls: ", lst_err->content, 0);
	ft_putstr(C_RESET);
	ft_lstdel_el(&lst_err);
}

void	ft_error_name(char *name, char *error, int ex)
{
	ft_putstr(name);
	perror(error);
	ex ? exit(EXIT_FAILURE) : 0;
}