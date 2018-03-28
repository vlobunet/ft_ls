# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/24 23:40:50 by vlobunet          #+#    #+#              #
#    Updated: 2018/02/10 12:13:06 by vlobunet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls
SRCS	=	main.c ft_parsing.c \
			get_size.c display_1.c \
			display_2.c display_3.c \
			display_4.c print_recurs.c \
			print_dir.c time.c lst_func.c
OBJS	= $(SRCS:.c=.o)
FLAGS	= -Wall -Wextra -Werror

all: $(NAME)
	@echo  ""

$(NAME): $(OBJS)
	@make -C libft/
	@gcc $(OBJS) -o $(NAME) -L libft/ -lft

%.o: %.c
	@cc -c $< -o $@ $(FLAGS)
	@echo  "▒\c)"

clean:
	@make -C libft/ clean
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME) $(OBJS)

re: fclean $(NAME)
