#include "ft_ls.h"

void	error_arg(char arg)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(arg);
	ft_putstr("\nusage: ft_ls [-Rafglrtu1] [file ...]\n");
	exit(EXIT_FAILURE);
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
			lst_pr->l = (param[i] == 'l' ? 1 : lst_pr->l);
			lst_pr->R = (param[i] == 'R' ? 1 : lst_pr->R);
			lst_pr->a = (param[i] == 'a' ? 1 : lst_pr->a);
			lst_pr->r = (param[i] == 'r' ? 1 : lst_pr->r);
			lst_pr->t = (param[i] == 't' ? 1 : lst_pr->t);
			lst_pr->u = (param[i] == 'u' ? 1 : lst_pr->u);
			lst_pr->f = (param[i] == 'f' ? 1 : lst_pr->f);
			lst_pr->l = (param[i] == 'f' ? 0 : lst_pr->l);
			lst_pr->a = (param[i] == 'f' ? 1 : lst_pr->a);
			lst_pr->g = (param[i] == 'g' ? 1 : lst_pr->g);
			lst_pr->l = (param[i] == '1' ? 0 : lst_pr->l);
		}
		else error_arg(param[i]);
		i++;
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
	while (i < (argc - 1))
	{
		ft_lstadd_s(lst_dr, *argv);
		ft_lstadd(lst_dr, ft_lstnew_el(i++, *argv++, *lst_pr));
	}
}
