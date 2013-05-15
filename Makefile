##
## Makefile for domusic in /home/brunie_j/local/my/domusic
##
## Made by Brunier Jean
## Login   <brunie_j@epitech.net>
##
## Started on  Wed Feb 13 15:57:38 2013 Brunier Jean
## Last update Wed May 15 09:40:00 2013 Brunier Jean
##

CXX	= clang++

NAME	= a.out

DOBJ	= obj
DSRC	= src
DINC	= .

SRCS	= Sound.cpp		\
	  Input.cpp		\
	  Key.cpp		\
	  Piano.cpp		\
	  Controler.cpp		\
	  main.cpp

INCLUDE = $(addprefix -I $(DSRC)/, $(DINC))

OBJS	= $(addprefix $(DOBJ)/, $(SRCS:.cpp=.o))

CXXFLAGS= $(INCLUDE) -Wall -Wextra -Werror -g -Ifmod/inc

LDXFLAGS= `sdl-config --cflags --libs` fmod/lib/libfmodex64.so -lm



all: $(NAME)

$(NAME):  $(OBJS)
	$(CXX) $^ -o $@ $(LDXFLAGS)

$(DOBJ)/%.o: $(DSRC)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $^ -c -o $@ $(CXXFLAGS)

clean:
	rm -Rf $(DOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
