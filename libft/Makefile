# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaejkim <jaejkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/14 10:01:34 by jaejkim           #+#    #+#              #
#    Updated: 2022/11/27 05:50:18 by jaejkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libft.a

CC		= 	cc
CFLAGS	= 	-Wall -Wextra -Werror

AR		= 	ar
ARFLAGS	= 	-crus

INC		= 	libft.h
SRCS	= 	ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_tolower.c\
			ft_toupper.c
B_SRCS	= 	ft_lstadd_back_bonus.c\
			ft_lstadd_front_bonus.c\
			ft_lstclear_bonus.c\
			ft_lstdelone_bonus.c\
			ft_lstiter_bonus.c\
			ft_lstlast_bonus.c\
			ft_lstmap_bonus.c\
			ft_lstnew_bonus.c\
			ft_lstsize_bonus.c

M_OBJS	=	$(SRCS:.c=.o)
B_OBJS	=	$(B_SRCS:.c=.o)

%.o		:	%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

.PHONY	:	all
all		:	$(NAME)

$(NAME)	:	$(M_OBJS)													
			$(AR) $(ARFLAGS) $@ $?

.PHONY	:	bonus
B_DUM	=	.bonus_dummy
bonus 	:	$(B_DUM)
$(B_DUM):	$(B_OBJS)
			$(AR) $(ARFLAGS) $(NAME) $(B_OBJS)
			@touch $(B_DUM)

.PHONY	:	clean
clean	:
			rm -f $(M_OBJS) 
			rm -f $(B_OBJS)
			@rm -f $(B_DUM)

.PHONY	:	fclean
fclean	:	clean
			rm -f $(NAME)

.PHONY	:	re
re		:
			make fclean
			make all
