# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samin <samin@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/07 14:39:41 by hayelee           #+#    #+#              #
#    Updated: 2021/06/23 13:52:08 by samin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	pipex

SRCS =  ./src/main.c\
		./src/util.c\
        ./src/util2.c\
	
OBJS			= $(SRCS:.c=.o)
CC				= gcc
RM				= rm -f
CFLAGS			= -O3 -Wall -Wextra -Werror -I.
LIBFT			= libft/libft.a
MK				= make

all:		$(NAME)

${LIBFT}:	
			$(MAKE) -C libft 

$(NAME):	${LIBFT}
			$(CC) ${CFLAGS} -o ${NAME} ${SRCS} ${LIBFT}
clean:
			$(MAKE) -C ./libft clean
			$(RM) $(OBJS)
			
fclean:		clean
				$(RM) $(NAME) $(LIBFT)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
