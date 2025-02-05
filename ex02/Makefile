SRCS	=	main.cpp\
			PmergeMe.cpp\

OBJS	=	$(SRCS:.cpp=.o)

CXX		= c++

CXXFLAGS	= -std=c++98
CXXFLAGS 	+= -Wall -Wextra -Werror

NAME	= PmergeMe

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re:		fclean all

.PHONY:all clean fclean re