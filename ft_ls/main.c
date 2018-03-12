#include "ft_ls.h"

// void	display_file(t_opt arg, t_elem *files, int fileordir)
// {
// 	t_elem	*cur;

// 	cur = files;
// 	(arg.l == 1 || arg.g == 1) ? \
// 			ls_long(arg, cur, fileordir) : ls_simple(arg, cur);
// 	arg.upper_r == 1 ? recursion(arg, cur) : NULL;
// }

t_list	*ft_lstnew_el(int num, char *str, t_param p)
{
	t_list *lst;
	struct stat		fstat;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->num = num;
	lst->content = ft_strdup(str);
	lst->st_mode = fstat.st_mode;
	lst->st_nlink = fstat.st_nlink;
	lst->st_uid = fstat.st_uid;
	lst->st_gid = fstat.st_gid;
	lst->st_size = fstat.st_size;
	lst->st_blocks = fstat.st_blocks;
	lst->date = (p.u == 1 ? fstat.st_atime : fstat.st_mtime);
	lst->st_rdev = fstat.st_rdev;
	lst->prev = NULL;
	lst->next = NULL;
	return (lst);
}

void	ft_error_name(char *name, char *error, int ex)
{
	ft_putstr(name);
	perror(error);
	ex ? exit(EXIT_FAILURE) : 0;
}
void s1 (char *content, t_list **file, t_list **dir, int i, t_param lst_pr)
{
	DIR		*d;

	if ((d = opendir(content)) == NULL && errno != ENOTDIR)
		ft_error_name("ft_ls: ", content, 0);
	else if ((d = opendir(content)) == NULL && errno == ENOTDIR)
	{
		ft_lstadd_s(file, content);
    	ft_lstadd(file, ft_lstnew_el(i++, content, lst_pr));
	}
	else if ((d = opendir(content)) != NULL)
	{
		ft_lstadd_s(dir, content);
    	ft_lstadd(dir, ft_lstnew_el(i++, content, lst_pr));
		closedir(d);
	}
}

void	core(t_param lst_pr, t_list *lst_dr, int multidir)
{
	t_list	*lst_file;
	t_list	*lst_dir;
	int num; 
	int i = 0;

	lst_file = NULL;
	lst_dir = NULL;
	lst_pr.R = 0;
	multidir = 0;
	num = lst_dr->prev->num;
	while (num != lst_dr->num)
	{
		s1(lst_dr->content, &lst_file, &lst_dir, i++, lst_pr);
		lst_dr = lst_dr->next;
	}
	s1(lst_dr->content, &lst_file, &lst_dir, i++, lst_pr);
	lst_file ? printf("lst_file\n") : 0;
	lst_file && lst_dir ? ft_putchar('\n') : 0;
	lst_dir ? printf("lst_dir\n") : 0;
	// lst_file ? do_ls_file(lst_pr, lst_file) : NULL;
	// lst_file && lst_dir ? ft_putchar('\n') : NULL;
	// lst_dir ? do_ls_dir(lst_pr, lst_dir, multidir) : NULL;
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
	!lst_dr ? ft_lstadd(&lst_dr, ft_lstnew_el(1, ".", lst_pr)) : 0;
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