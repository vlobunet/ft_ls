#include "ft_ls.h"

void ls_long_file (t_lst *lst, t_param p, t_size size)
{
	ft_access(lst);
	print_lnk(lst, size.linkspace);
	if (p.g == 0)
		print_uid(lst);
	print_gid(lst);
	print_size(lst, size.size);
	print_date((*lst).date);
	(p.G == 1 && (S_ISFIFO(lst->st_mode))) ? ft_putstr(C_GREEN) : 0;
	(p.G == 1 && (S_ISCHR(lst->st_mode))) ? ft_putstr(C_SINIY) : 0;
	(p.G == 1 && (S_ISDIR(lst->st_mode))) ? ft_putstr(C_FIOLE) : 0;
	(p.G == 1 && (S_ISBLK(lst->st_mode))) ? ft_putstr(C_SINIY) : 0;
	(p.G == 1 && (S_ISREG(lst->st_mode))) ? ft_putstr(C_YELLO) : 0;
	(p.G == 1 && (S_ISLNK(lst->st_mode))) ? ft_putstr(C_GOLYB) : 0;
	(p.G == 1 && (S_ISFIFO(lst->st_mode))) ? ft_putstr(C_SINIY) : 0;
	ft_putendl((*lst).content);
	ft_putstr(C_RESET);
}

void go_to_start(t_lst **lst)
{
	while (strcmp((*lst)->content, (*lst)->next->content) < 0)
		*lst = (*lst)->next;
	*lst = (*lst)->next;
}

void	print_ls_lg(t_lst *file, t_param lst_pr, int m)
{
	t_size	size;
	int num;

	size = get_size(lst_pr, file);
	if (m)
	{
		ft_putstr("total ");
		ft_putnbr(size.total);
		ft_putchar('\n');
	}
	if (file->prev)
	{
		go_to_start(&file);
		num = file->prev->num;
		while (num != file->num)
		{
			if (!(lst_pr.a == 0 && file->content[0] == '.'))
				ls_long_file(file, lst_pr, size);
			file = file->next;
		}
	}
	if (!(lst_pr.a == 0 && file->content[0] == '.'))
	ls_long_file(file, lst_pr, size);
}

void	print_ls_lgr(t_lst *file, t_param lst_pr, int m)
{
	t_size	size;
	int num;

	size = get_size(lst_pr, file);
	if (m)
	{
		ft_putstr("total ");
		ft_putnbr(size.total);
		ft_putchar('\n');
	}
	if (file->prev)
	{
		go_to_start(&file);
		file = file->prev;
		num = file->next->num;
		while (num != file->num)
		{
			if (!(lst_pr.a == 0 && file->content[0] == '.'))
				ls_long_file(file, lst_pr, size);
			file = file->prev;
		}
	}
	if (!(lst_pr.a == 0 && file->content[0] == '.'))
	ls_long_file(file, lst_pr, size);
}

void print_cut (t_lst *file, t_param lst_pr)
{
	int num;

	if (file->prev)
	{
		go_to_start(&file);
		num = file->prev->num;
		while (num != file->num)
		{
			if (!(lst_pr.a == 0 && file->content[0] == '.'))
			ft_putendl(file->content);
			file = file->next;
		}
	}
	if (!(lst_pr.a == 0 && file->content[0] == '.'))
	ft_putendl(file->content);
}

void print_cutr(t_lst *file, t_param lst_pr)
{
	int num;

	if (file->prev)
	{
		go_to_start(&file);
		file = file->prev;
		num = file->next->num;
		while (num != file->num)
		{
			if (!(lst_pr.a == 0 && file->content[0] == '.'))
			ft_putendl(file->content);
			file = file->prev;
		}
	}
	if (!(lst_pr.a == 0 && file->content[0] == '.'))
	ft_putendl(file->content);
}

void	print_fie(t_lst *file, t_param lst_pr, int i)
{
	if (lst_pr.l || lst_pr.g)
		(!lst_pr.r) ?  print_ls_lg(file, lst_pr, i) : print_ls_lgr(file, lst_pr, i);
	else
		(!lst_pr.r) ? print_cut(file, lst_pr) : print_cutr(file, lst_pr);
	(lst_pr.R == 1 && !lst_pr.r) ? ft_print_recurs1(file, lst_pr) : NULL;
	(lst_pr.R == 1 && lst_pr.r) ? ft_print_recurs1r(file, lst_pr) : NULL;
	ft_lstdel_el(&file);
}