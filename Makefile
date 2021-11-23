# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhaefeli <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/18 16:28:28 by vhaefeli          #+#    #+#              #
#    Updated: 2021/11/22 15:10:15 by vhaefeli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

NAME 		= libftprintf.a

CFLAGS 		= -Wall -Wextra -Werror #-g -fsanitize=address

LIBFT_DIR	= ./libft

INCLUDES_DIRS	= ./includes $(LIBFT_DIR)

INCLUDES		= $(addprefix -I,$(INCLUDES_DIRS))

SRCS =	ft_printf.c\
		ft_hextoa.c\
		ft_checktype.c\
		ft_itoua.c\
		ft_uitoa.c\
		ft_flstring.c\
		ft_argprint.c\
		ft_argtype.c\
		ft_flafter.c\
		ft_flbefore.c\
		ft_nbpoint.c


OBJS = $(SRCS:.c=.o)

.PHONY: all clean fclean re bonus

all: $(NAME)

%.o: %.c
	$(CC) -o $@ -c $^ $(CFLAGS) $(INCLUDES)

bonus: $(NAME)
 
$(NAME): $(LIBFT_DIR)/libft.a $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/libft.a $(NAME)
	ar -rcs $(NAME) $(OBJS)

$(LIBFT_DIR)/libft.a:
	$(MAKE) -C $(LIBFT_DIR)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

