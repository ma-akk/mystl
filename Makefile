SRCS		= main_it_test.cpp

OBJS		= ${SRCS:.cpp=.o}

HEADER		= rb_tree.hpp

CC			= c++

NAME		= ft_containers

#add flags -Wall -Wextra -Werror
FLAGS		= -std=c++98 -g

.cpp.o:
		${CC} ${FLAGS} -c $< -o ${<:.cpp=.o}

all:	${NAME}

$(NAME):	${OBJS} ${HEADER}
			${CC} ${FLAGS} ${OBJS} -o ${NAME}

clean:
		rm -rf ${OBJS}

fclean:	clean
		rm -rf ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
