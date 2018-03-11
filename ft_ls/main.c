#include "ft_ls.h"
void	basicerror(char *name, char *error, int ex)
{
	ft_putstr_fd(name, 2);
	perror(error);
	if (ex)
		exit(EXIT_FAILURE);
}

void	core(t_param lst_pr, t_list *lst_dr, int multidir)
{
	DIR		*dir;
	t_list	*lst_file;
	t_list	*lst_dir;
	int num;

	lst_file = NULL;
	lst_dir = NULL;
	lst_pr.R = 0;
	multidir = 0;
	num = lst_dr->prev->num;
	while (num != lst_dr->num)
	{
		printf("---> : %s\n", lst_dr->content);
		if ((dir = opendir(lst_dr->content)) == NULL && errno != ENOTDIR)
			basicerror("ft_ls: ", lst_dr->content, 0);
		else if ((dir = opendir(lst_dr->content)) == NULL && errno == ENOTDIR)
			printf("f : %s\n", lst_dr->content);// если аргумент не открывается но есть файлом добавить его в список файлов lst_file
		else if ((dir = opendir(lst_dr->content)) != NULL)
		{
			printf("dr : %s\n", lst_dr->content);// если аргумент открывается добавить его в список папок lst_dir
			closedir(dir);
		}
		lst_dr = lst_dr->next;
	}
	// lst_file ? do_ls_file(arg, lst_file) : NULL;
	// lst_file && lst_dir ? ft_putchar('\n') : NULL;
	// lst_dir ? do_ls_dir(arg, lst_dir, multidir) : NULL;
}

int		main(int argc, char **argv)
{

	t_list	*lst_dr;
	t_param lst_pr;
	int		x;

	x = 0;
	lst_pr = (t_param){0, 0, 0, 0, 0, 0, 0, 0};
	lst_dr = NULL;

	if (argc > 1)
		ft_parsing(argc, argv, &lst_dr, &lst_pr);
	!lst_dr ? ft_lstadd(&lst_dr, ft_lstnew(1, ".")) : 0;
	lst_dr->next != NULL ? x = 1 : 0;
	core(lst_pr, lst_dr, x);
	return 0;
}

// void	error_arg(char arg)
// {
// 	ft_putstr_fd("ft_ls: illegal option -- ", 2);
// 	ft_putchar_fd(arg, 2);
// 	ft_putstr_fd("\nusage: ft_ls [-Rafglrtu1] [file ...]\n", 2);
// 	exit(EXIT_FAILURE);
// }
