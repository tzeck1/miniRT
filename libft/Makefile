# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzeck <@student.42heilbronn.de>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/02 11:55:38 by rsiebert          #+#    #+#              #
#    Updated: 2022/06/27 18:08:33 by tzeck            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
SRC		=	ft_atoi.c		ft_isalnum.c	ft_isprint.c	ft_memcmp.c\
			ft_bzero.c		ft_calloc.c		ft_isalpha.c	ft_isascii.c\
			ft_isdigit.c	ft_itoa.c		ft_memchr.c		ft_striteri.c\
			ft_memcpy.c		ft_memmove.c	ft_memset.c		ft_putchar_fd.c\
			ft_putendl_fd.c	ft_putnbr_fd.c	ft_putstr_fd.c	ft_split.c\
			ft_strchr.c		ft_strdup.c		ft_strjoin.c	ft_strlcat.c\
			ft_strlcpy.c	ft_strlen.c		ft_strmapi.c	ft_strncmp.c\
			ft_strnstr.c	ft_strrchr.c	ft_strtrim.c	ft_substr.c\
			ft_tolower.c	ft_toupper.c	ft_atof.c		ft_free_split.c\
			ft_isfloat.c
GNLSRC	=	get_next_line/get_next_line.c\
			get_next_line/get_next_line_utils.c
OBJ		=	$(SRC:.c=.o)
GNLOBJ	=	$(GNLSRC:.c=.o)
CC		=	@gcc -Wall -Wextra -Werror

all		:	$(NAME)

$(NAME)	:	message $(OBJ) $(GNLOBJ)
	@ar rs $(NAME) $(GNLOBJ) $(OBJ)
	@echo "\033[92mDone!\033[0m"

message	:
	@echo "creating $(NAME)..."

clean	:
	@rm -f *.o
	@rm -f get_next_line/*.o
	@echo "Object files be gone!"

fclean	:	clean
	@rm -f $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
