# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By:  rboia-pe@student.42porto.com  <rboia-p    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 02:02:06 by jhogonca          #+#    #+#              #
#    Updated: 2023/03/29 10:39:33 by  rboia-pe@s      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq

SRCS = ${wildcard *.c}
OBJS = ${SRCS:.c=.o}

#CFLAGS = -Wall -Wextra -Werror -I.
CFLAGS = -I.

CC = gcc

PERL = perl map_gen.pl

RM = rm -f

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

perl:
	perl *.pl 50 10 > map_50.txt

.PHONY: all clean fclean re norm