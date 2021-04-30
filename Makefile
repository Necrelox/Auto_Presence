##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## make
##

############### Compiler ##################
CC = @g++ -std=c++17
###########################################

###############  Default  #################
NAME 	= presence
SRC		= 	$(wildcard src/*.cpp) 				\
			$(wildcard src/error/*.cpp) 		\
			$(wildcard src/filehandle/*.cpp)

OBJ		=	$(SRC:.cpp=.o)
INCPATH = 	-I./include -I./include/class
CFLAGS	= -Wall -Wextra -Werror -g3 -O3
LIB 	=
###########################################


################# Rules ###################

.cpp.o:
	@echo "\e[1;91m[\e[1;92mOK\e[1;91m]\e[0m" "\e[1;91m Compile\e[1;93m" $< "\e[1;91mto\e[1;92m" $@ "\e[0m"
	$(CC) $(CFLAGS) $(INCPATH) -c $< -o $@

all: $(OBJ)
	@echo "\e[1;91m[\e[1;92mOK\e[1;91m]\e[0m" "\e[1;91m LINK\e[1;93m" $< "\e[1;91mto\e[1;92m" $(NAME) "\e[0m"
	$(CC) $(OBJ) -o $(NAME) $(LIB)

	@echo "\e[1;92m Compile $(NAME), Finish ! \e[0m"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

###########################################
