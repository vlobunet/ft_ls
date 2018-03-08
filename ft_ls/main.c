#include "ft_ls.h"

// void	ft_print_error(char *str, char *content, char *arg, int md, int f)
// {
// 	if (!f)
// 	{
// 		ft_putstr("ft_ls: illegal option -- ");
// 		ft_putchar(arg);
// 		ft_putstr("\nusage: ft_ls [-Rafglrtu1] [file ...]\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	else
// 	{
// 		ft_putstr(str);
// 		perror(error);
// 		md ? exit(EXIT_FAILURE) : 0;
// 	}
// }

int		main(int argc, char **argv)
{

	t_list	*lst_dr;
	t_param lst_pr;
	int		x;

	x = 0;
	lst_pr = (t_param){0, 0, 0, 0, 0, 0, 0, 0};
	lst_dr = NULL;

	if (argc == 1)
		ft_ls(".");
	else
		ft_parsing(argc, argv, &lst_dr, &lst_pr);
	!lst_dr ? ft_lstadd(&lst_dr, ft_lstnew(1, ".")) : 0;
	lst_dr->next != NULL ? x = 1 : 0;

	printf("%d\n", x);
	return 0;
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