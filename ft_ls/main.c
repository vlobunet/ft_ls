#include "ft_ls.h"

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

int s1(char *content, t_list **file, t_list **dir, int i, t_param lst_pr)
{
	DIR		*d;

	if ((d = opendir(content)) == NULL && errno != ENOTDIR)
		return (0);
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
	return (1);
}

void add_elem(char *content, t_list **lst, int i, t_param lst_pr)
{
	ft_lstadd_s(lst, content);
	ft_lstadd(lst, ft_lstnew_el(i++, content, lst_pr));
}

void	core(t_param lst_pr, t_list *lst_dr, int multidir)
{
	t_list	*lst_file;
	t_list	*lst_dir;
	t_list	*lst_err;
	int num; 
	int i;

	i = 0;
	lst_file = NULL;
	lst_dir = NULL;
	lst_err = NULL;
	multidir = 0; // убрать
	(lst_dr->prev) ? (num = lst_dr->prev->num) : (num = lst_dr->num);
	while (num != lst_dr->num)
	{
		!s1(lst_dr->content, &lst_file, &lst_dir, i++, lst_pr) ? \
			add_elem(lst_dr->content, &lst_err, i, lst_pr) : 0;
		lst_dr = lst_dr->next;
	}
	!s1(lst_dr->content, &lst_file, &lst_dir, i++, lst_pr) ? \
		add_elem(lst_dr->content, &lst_err, i, lst_pr) : 0;
	lst_err ? print_error_el(&lst_err): 0;
	lst_file ? print_fie(lst_file, lst_pr) : 0;
	lst_file && lst_dir ? ft_putchar('\n') : 0;
	// lst_dir ? print_dir(lst_dir, lst_pr) : 0;
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