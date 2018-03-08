#include "ft_ls.h"

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
