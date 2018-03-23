#include "ft_ls.h"

int g_count = 1;

void ft_lstdel_el(t_list **lst)
{
	int num;
	t_list *p;

	num = ((*lst)->prev ? (*lst)->prev->num : (*lst)->num);
	while (num != (*lst)->num)
	{
		p = *lst;
		(*lst)->prev->next = (*lst)->next;
		(*lst)->next->prev = (*lst)->prev;
		*lst = (*lst)->next;
		ft_strdel(&p->content);
		ft_strdel(&p->path);
		free(p);
	}
	(*lst)->prev = NULL;
	(*lst)->next = NULL;
	ft_strdel(&(*lst)->content);
	ft_strdel(&(*lst)->path);
	free(*lst);
}

t_list	*ft_lstnew_el(int num, char *str, t_param p, char *path)
{
	t_list		*lst;
	struct stat	st;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->num = num;
	lst->content = ft_strdup(str);
	lst->path = ft_strjoin(path, str);
	lstat(lst->path, &st);
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

int		s1(char *content, t_list **file, t_list **dir, t_param lst_pr)
{
	DIR			*d;

	if ((d = opendir(content)) == NULL && errno != ENOTDIR)
		return (0);
	else if ((d = opendir(content)) == NULL && errno == ENOTDIR)
	{
		ft_lstadd_s(file, content);
		ft_lstadd(file, ft_lstnew_el(g_count++, content, lst_pr, ""));
	}
	else if ((d = opendir(content)) != NULL)
	{
		ft_lstadd_s(dir, content);
		ft_lstadd(dir, ft_lstnew_el(g_count++, content, lst_pr, ""));
		closedir(d);
	}
	printf("%s\n", content);
	// ft_strdel(&content);
	return (1);
}

void	add_elem(char *content, t_list **lst, int i, t_param lst_pr)
{
	ft_lstadd_s(lst, content);
	ft_lstadd(lst, ft_lstnew_el(i++, content, lst_pr, ""));
}

int get_elem(t_list **lst, struct dirent *file, char *path, t_param param)
{
	if (!file)
		return (0);
	if (lst)
	{
		ft_lstadd_s(lst, file->d_name);
		ft_lstadd(lst, ft_lstnew_el(g_count++, file->d_name, param, path));
	}
	else
		ft_lstadd(lst, ft_lstnew_el(g_count++, file->d_name, param, path));
	free(path);
	return (1);
}

void print_dir_2(t_list *lst_dir, t_list **file, t_param param, int m)
{
	DIR		*dir;

	char *s;

	dir = opendir(lst_dir->content);
	while ((get_elem(file, readdir(dir), ft_strjoin(lst_dir->path, "/"), param)))
		;
	closedir(dir);
	if (file)
	{
		s = ft_strjoin(lst_dir->content, ":");
		m ? ft_putendl(s) : NULL;
		free(s);
		print_fie(*file, param, 1);
	}
}

void	print_dir(t_list *lst_dir, t_param param, int m)
{
	t_list	*file;
	int num;

	file = NULL;
	if (lst_dir->next)
	{
		go_to_start(&lst_dir);
		num = (lst_dir->prev ? lst_dir->prev->num : lst_dir->num);
		while (num != lst_dir->num)
		{
			print_dir_2(lst_dir, &file, param, m);
			ft_putchar('\n');
			file = NULL;
			lst_dir = lst_dir->next;
		}
	}
	print_dir_2(lst_dir, &file, param, m);
	ft_lstdel_el(&lst_dir);
	file = NULL;
}




void	core(t_param lst_pr, t_list *lst_dr, int m)
{
	t_list	*lst_file;
	t_list	*lst_dir;
	t_list	*lst_err;
	int		num;

	lst_file = NULL;
	lst_dir = NULL;
	lst_err = NULL;
	num = (lst_dr->prev ? lst_dr->prev->num : lst_dr->num);
	while (num != lst_dr->num)
	{
		!s1(lst_dr->content, &lst_file, &lst_dir, lst_pr) ? \
			add_elem(lst_dr->content, &lst_err, g_count++, lst_pr) : 0;
		lst_dr = lst_dr->next;
	}
	!s1(lst_dr->content, &lst_file, &lst_dir, lst_pr) ? \
		add_elem(lst_dr->content, &lst_err, g_count++, lst_pr) : 0;
	lst_err ? print_error_el(lst_err) : 0;
	lst_file ? print_fie(lst_file, lst_pr, 0) : 0;
	lst_file && lst_dir ? ft_putchar('\n') : 0;
	lst_dir ? print_dir(lst_dir, lst_pr, m) : 0;
}

int		main(int argc, char **argv)
{

	t_list	*lst_dr;
	t_param lst_pr;

	lst_pr = (t_param){0, 0, 0, 0, 0, 0, 0, 0};
	lst_dr = NULL;
	if (argc > 1)
		ft_parsing(argc, argv, &lst_dr, &lst_pr);
	!lst_dr ? ft_lstadd(&lst_dr, ft_lstnew_el(1, ".", lst_pr, "")) : 0;
	core(lst_pr, lst_dr, lst_dr->next ? 1 : 0);
	system("leaks ft_ls ");
	return (0);
}
