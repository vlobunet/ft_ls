#include "ft_ls.h"

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

void	print_lnk(t_list *lst)
{
	int		n;

	n = 3 - ft_strlen(ft_itoa(lst->st_nlink));
	while (n-- > 0)
		ft_putchar(' ');
	ft_putnbr((*lst).st_nlink);
	ft_putstr(" ");
}

void print_uid(t_list *lst)
{
	if (getpwuid((*lst).st_uid))
		ft_putstr((getpwuid((*lst).st_uid))->pw_name);
	else
		ft_putstr(ft_itoa((*lst).st_uid));
}

void print_gid(t_list *lst)
{
	int n;

	if (getgrgid((*lst).st_gid))
	{
		n = 6 - ft_strlen((getgrgid((*lst).st_gid))->gr_name);
		while (n-- > 0)
			ft_putchar(' ');
		ft_putstr((getgrgid((*lst).st_gid))->gr_name);
	}
	else
	{
		n = 6 - ft_strlen(ft_itoa((*lst).st_gid));
		while (n-- > 0)
			ft_putchar(' ');
		ft_putstr(ft_itoa((*lst).st_gid));
	}
}

void print_size(t_list *lst)
{
	int n;
	int x;
	n = 0;
	x = (*lst).st_size;
	while (x / 10 > 0)
	{
		x = x / 10;
		n++;
	}
	n = 5 - n + 1;
	while (n-- > 0)
		ft_putchar(' ');
	ft_putnbr((*lst).st_size);
}
