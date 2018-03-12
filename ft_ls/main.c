#include "ft_ls.h"

// void	display_file(t_param param, t_list *files, int fileordir)
// {
// 	if ((param.l == 1 || param.g == 1))
// 			ls_long(param, files, fileordir);
// 	else
// 			ls_simple(param, files);
// 	param.upper_r == 1 ? recursion(param, files) : NULL;
// }

void	ft_access(t_list *lst)
{
	ft_putchar((S_ISFIFO(lst->st_mode)) ? 'p' : 0);
	ft_putchar((S_ISCHR(lst->st_mode)) ? 'c' : 0);
	ft_putchar((S_ISDIR(lst->st_mode)) ? 'd' : 0);
	ft_putchar((S_ISBLK(lst->st_mode)) ? 'b' : 0);
	ft_putchar((S_ISREG(lst->st_mode)) ? '-' : 0);
	ft_putchar((S_ISLNK(lst->st_mode)) ? 'l' : 0);
	ft_putchar((S_ISSOCK(lst->st_mode)) ? 's' : 0);
	ft_putchar((lst->st_mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((lst->st_mode & S_IWUSR) ? 'w' : '-');
	ft_putchar((lst->st_mode & S_IXUSR) ? 'x' : '-');
	ft_putchar((lst->st_mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((lst->st_mode & S_IWGRP) ? 'w' : '-');
	ft_putchar((lst->st_mode & S_IXGRP) ? 'x' : '-');
	ft_putchar((lst->st_mode & S_IROTH) ? 'r' : '-');
	ft_putchar((lst->st_mode & S_IWOTH) ? 'w' : '-');
	ft_putchar((lst->st_mode & S_IXOTH) ? 'x' : '-');
	ft_putstr("  ");
}

void	print_int(t_list *lst)
{
	int		n;

	n = ft_strlen(ft_itoa(lst->st_nlink));
	while (n-- > 0)
		ft_putchar(' ');
	ft_putnbr((*lst).st_nlink);
	ft_putstr(" ");
}

t_list	*ft_lstnew_el(int num, char *str, t_param p)
{
	t_list *lst;
	struct stat		st;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->num = num;
	lst->content = ft_strdup(str);
	lstat(lst->content, &st);
	lst->st_mode = st.st_mode;
	lst->st_nlink = st.st_nlink;
	lst->st_uid = st.st_uid;
	lst->st_gid = st.st_gid;
	lst->st_size = st.st_size;
	lst->st_blocks = st.st_blocks;
	lst->date = (p.u == 1 ? st.st_atime : st.st_mtime);
	lst->st_rdev = st.st_rdev;
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
    	ft_access(*file);
    	print_int(*file);
    	printf("%s\n", (*file)->content);
	}
	else if ((d = opendir(content)) != NULL)
	{
		ft_lstadd_s(dir, content);
    	ft_lstadd(dir, ft_lstnew_el(i++, content, lst_pr));
    	ft_access(*dir);
    	print_int(*dir);
    	printf("%s\n", (*dir)->content);
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
	multidir = 0;
	(lst_dr->prev) ? (num = lst_dr->prev->num) : (num = lst_dr->num);
	while (num != lst_dr->num)
	{
		s1(lst_dr->content, &lst_file, &lst_dir, i++, lst_pr);
		lst_dr = lst_dr->next;
	}
	s1(lst_dr->content, &lst_file, &lst_dir, i++, lst_pr);
	lst_file ? printf("lst_file\n") : 0;
	lst_file && lst_dir ? ft_putchar('\n') : 0;
	lst_dir ? printf("lst_dir\n") : 0;
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
