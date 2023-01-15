NAME		= bureaucrat

CC		= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98

RM		= rm
RMFLAGS		= -f

INCLUDE		= ./Bureaucrat.hpp ./AFrom.hpp ./ShrubberyCreationForm.hpp ./RobotomyRequestForm.hpp ./PresidentialPardonForm.hpp ./Intern.hpp

SRCS 		= main.cpp	\
			  Bureaucrat.cpp	\
			  AForm.cpp	\
			  ShrubberyCreationForm.cpp	\
			  RobotomyRequestForm.cpp	\
			  PresidentialPardonForm.cpp	\
			  Intern.cpp

OBJS		= $(SRCS:%.cpp=%.o)

all		: $(NAME)

$(NAME)		: $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
		$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

clean		:
		$(RM) $(RMFLAGS) $(OBJS)

fclean		: clean
		$(RM) $(RMFLAGS) $(NAME)

re		: fclean all

.PHONY		: all clean fclean re
