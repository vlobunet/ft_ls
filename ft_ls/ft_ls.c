#include "ft_ls.h"

void ft_ls (const char *dir_name)
{
	DIR *d;
	struct dirent *entry;
	const char *d_name;

	(dir_name == NULL) ? (dir_name = ".") : 0;
	d = opendir(dir_name);
	if (!d)
		printf("ft_ls: %s: No such file or directory\n", dir_name);
	else
	{
		printf("%s:\n", dir_name);
		while (1)
		{
			entry = readdir(d);
			if (!entry)
				break ;
			d_name = entry->d_name;
			(d_name[0] != '.') ? (printf("%s\n", d_name)) : 0;
			// printf("%s\n", d_name);
		}
		printf("\n");
		if (closedir (d))
			printf("Could not close '%s'\n", dir_name);
	}
}