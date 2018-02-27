clear
printf "\e[8;50;80;t"
printf "                    \e[93m-C libft/ fclean && make -C libft/\e[92m\n"
echo -n "         "       
make -C libft/ fclean && make -C libft/
printf "       \e[93m-Wall -Wextra -Werror -I libft/includes -o main.o -c main.c\e[92m\n"
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
printf "           \e[93m-o ft_ls main.o -I libft/includes -L libft/ -lft\e[92m\n"
clang -o ft_ls main.o -I libft/includes -L libft/ -lft
printf "\n"
printf "\e[93m/* ************************************************************************** */\e[0m\n"
printf "\e[93m/*                                                                            */\e[0m\n"
printf "\e[93m/*\e[0m                                                        \e[97m:::      ::::::::\e[0m\e[25m   \e[93m*/\e[0m\n"
printf "\e[93m/*\e[0m   \e[34mft_ls.c        \e[39m                                     \e[97m:+:      :+:    :+:\e[92m\e[25m  \e[93m*/\e[0m\n"
printf "\e[93m/*\e[0m                                                    \e[97m+:+ +:+         +:+\e[92m\e[25m     \e[93m*/\e[0m\n"
printf "\e[93m/*\e[0m   \e[97mBy: vlobunet <marvin@42.fr>\e[39m                     \e[97m+#+  +:+       +#+\e[92m\e[25m       \e[93m*/\e[0m\n"
printf "\e[93m/*\e[0m                                                \e[97m+#+#+#+#+#+    +#+\e[92m\e[25m          \e[93m*/\e[0m\n"
printf "\e[93m/*\e[0m   \e[97mCreated: 2018/01/30 12:57:46 by \e[34mvlobunet\e[39m          \e[97m#+#    #+#\e[92m\e[25m             \e[93m*/\e[0m\n"
printf "\e[93m/*\e[0m   \e[97mUpdated: 2018/01/30 12:57:47 by \e[34mvlobunet\e[39m         \e[97m###   ########.fr\e[92m\e[25m       \e[93m*/\e[0m\n"
printf "\e[93m/*                                                                            */\e[0m\n"
printf "\e[93m/* ************************************************************************** */\e[0m\n"
printf "\n"
printf "\e[97m  ================================ ./ft_ls ===============================\e[39m  \n"
./ft_ls -t4 -t6 -t2 -t1 -t5 -t0