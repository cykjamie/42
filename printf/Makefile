# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chapark <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/11 20:45:36 by chapark           #+#    #+#              #
#    Updated: 2019/05/06 00:02:36 by chapark          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c fmt.c put_cs.c put_num.c put_ouxp.c width.c flag.c special_case.c ft_lltoa.c convert_f.c convert_numx.c precision.c

OBJ = ft_printf.o fmt.o put_cs.o put_num.o put_ouxp.o width.o flag.o special_case.o ft_lltoa.o convert_f.o convert_numx.o precision.o



$(NAME): $(SRC)
	gcc -g -Wall -Werror -Wextra -c -I libft $(SRC)
	make -C libft
	mv libft/libft.a $(NAME)
	ar rc $(NAME) $(OBJ) 
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C libft
 
fclean:	clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean \
	all

test: all
	gcc -g -fsanitize=address test.c libftprintf.a -I . -I libft
	./a.out

fasttest: re
	@clear
	@echo "testing"
	@sed "s/printf(/ft_printf(/g" tester.c > ft_tester.c
	@gcc -o printf -Wno-format $(NAME) -I . tester.c
	@gcc -o ft_printf $(NAME) -I . ft_tester.c
	@./ft_printf > ft_printf.out
	@./printf > printf.out
	@diff --text ft_printf.out printf.out
	@clear
	@echo "################"
	@echo "## GOOD STUFF ##"
	@echo "################"
