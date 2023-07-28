# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastida <abastida@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 12:09:49 by abastida          #+#    #+#              #
#    Updated: 2023/07/26 20:27:48 by abastida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo_bonus
SRC := philo_bonus.c check_error_bonus.c giving_data_bonus.c utils_bonus.c \
	create_bonus.c print_bonus.c routine_bonus.c
OBJ := $(SRC:.c=.o)
DEP := $(SRC:.c=.d)
CC := gcc
CFLAGS := -Wall -Werror -Wextra -g -MMD -pthread
RM := rm -rf
LIBS := -lpthread 
HEADER := inc_bonus/
INCLUDE := -I $(HEADER)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(OBJ)
	$(MAKE) $(NAME)

-include $(DEP)
$(NAME): $(OBJ) Makefile 
	$(CC) $(CFLAGS) $(LIBS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(DEP)

fclean:
	$(MAKE) clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus
