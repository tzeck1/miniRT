# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzeck <@student.42heilbronn.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 11:55:38 by rsiebert          #+#    #+#              #
#    Updated: 2022/06/11 21:01:55 by tzeck            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		=	ft_atoi.c		ft_isalnum.c	ft_isprint.c	ft_memcmp.c\
			ft_bzero.c		ft_calloc.c		ft_isalpha.c	ft_isascii.c\
			ft_isdigit.c	ft_itoa.c		ft_memchr.c		ft_striteri.c\
			ft_memcpy.c		ft_memmove.c	ft_memset.c		ft_putchar_fd.c\
			ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr_fd.c	ft_split.c\
			ft_strchr.c		ft_strdup.c		ft_strjoin.c	ft_strlcat.c\
			ft_strlcpy.c	ft_strlen.c		ft_strmapi.c	ft_strncmp.c\
			ft_strnstr.c	ft_strrchr.c	ft_strtrim.c	ft_substr.c\
			ft_tolower.c	ft_toupper.c	ft_atof.c
NAME	=	libft.a
OBJ		=	$(SRC:.c=.o)
CC		=	@gcc -Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	message $(OBJ)
	@ar rs $(NAME) $(OBJ)
	@echo "\033[92mDone!\033[0m"

message	:
	@echo "creating $(NAME)..."

clean	:
	@rm -f *.o
	@echo "Object files be gone!"

fclean	:	clean
	@rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
