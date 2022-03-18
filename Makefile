SRCS		= main.cpp Vector.cpp

OBJS		= ${SRCS:.cpp=.o}

HEADER		= Vector.hpp 

CC			= c++

NAME		= ft_containers

FLAGS		= -Wall -Wextra -Werror -std=c++98

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
