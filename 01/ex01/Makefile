# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daviles- <daviles-@student.madrid42.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/05 14:55:03 by daviles-          #+#    #+#              #
#    Updated: 2024/11/05 14:55:07 by daviles-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = zombies

##########################   COMPILING SETTINGS   #########################

CC = c++
CFLAGS = -Werror -Wextra -Wall #-fsanitize=address -g3
CPPFLAGS = -std=c++98 
RM = rm -f

###########################    FILES   ####################################

SRCS =	Zombie.cpp zombieHorde.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)	
DEPS = $(SRCS:.cpp=.d)


#########################  COLORS & EXTRAS  #################################
RED = \033[0;31m
RED_N = \033[1;31m
GREEN = \033[0;32m
GREEN_N = \033[1;32m
YELLOW = \033[0;33m
YELLOW_N = \033[1;33m
BLUE = \033[0;34m
BLUE_N = \033[1;34m
PURPLE = \033[0;35m
PURPLE_N = \033[1;35m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NOCOLOR = \033[0m

# Emojis
SUCCESS_EMOJI=✨
CLEAN_EMOJI=🧹
RECYCLE_EMOJI=♻️
WARNING_EMOJI=⚠️
ERROR_EMOJI=❌
COOL_EMOJI=😎
CAT_EMOJI=😸


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Successful compilation! $(NOCOLOR)"
	@echo "$(YELLOW)──▄────▄▄▄▄▄▄▄────▄───"
	@echo "─▀▀▄─▄█████████▄─▄▀▀──"
	@echo "─────██─▀███▀─██──────"
	@echo "───▄─▀████▀████▀─▄────"
	@echo "─▀█────██▀█▀██────█▀──$(NOCOLOR)"

%.o: %.cpp
	@echo "$(BLUE)Compiling files...$(NOCOLOR)"
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

-include $(DEPS)

clean:
	@echo "$(CLEAN_EMOJI)$(RED_N)Cleaning files... $(NOCOLOR)$(SUCCESS_EMOJI)"
	@$(RM) $(OBJS) $(DEPS)

fclean:	clean
	@echo "$(CLEAN_EMOJI)$(RED)Removing executable... $(NOCOLOR)$(CAT_EMOJI)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re


#Silent prints:  > /dev/null
	


