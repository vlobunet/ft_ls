clear
printf "                              \e[93mmake fclean && make \e[92m\n"
echo -n "         "       
make fclean && make 
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
./ft_ls -lR test test1 test2
printf "\e[97m  ================================ ls ===============================\e[39m  \n"
ls -lR test test1 test2