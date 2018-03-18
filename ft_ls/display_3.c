#include "ft_ls.h"

void ls_long_file (t_list *lst, t_param p)
{
	ft_access(lst);
	print_lnk(lst);
	if (p.g == 0)
		print_uid(lst);
	print_gid(lst);
	print_size(lst);
	print_date((*lst).date);
	ft_putendl((*lst).content);
}

void go_to_start(t_list **lst)
{
	while (strcmp((*lst)->content, (*lst)->next->content) < 0)
		*lst = (*lst)->next;
	*lst = (*lst)->next;
}

void	print_ls_lg(t_list *file, t_param lst_pr, int m)
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
				ls_long_file(file, lst_pr);
			file = file->next;
		}
	}
	ls_long_file(file, lst_pr);
}

void	print_ls_lgr(t_list *file, t_param lst_pr, int m)
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
				ls_long_file(file, lst_pr);
			file = file->prev;
		}
	}
	ls_long_file(file, lst_pr);
}

void	print_fie(t_list *file, t_param lst_pr)
{
	// lst_pr.a = 1;
	if ((lst_pr.l || lst_pr.g) && !lst_pr.r) 
		print_ls_lg(file, lst_pr, 0);
	else if ((lst_pr.l || lst_pr.g) && lst_pr.r) 
		print_ls_lgr(file, lst_pr, 0);
	//ОЧИСТИТЬ СПИСОК!!!!!
}