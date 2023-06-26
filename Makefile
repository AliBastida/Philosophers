# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abastida <abastida@student.42barcelona.co  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/23 17:42:30 by abastida          #+#    #+#              #
#    Updated: 2023/06/23 17:47:56 by abastida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := philo
SRC := philo.c prueba.c
OBJ := $(SRC:.c=.o)
DEP := $(SRC:.c=.d)
CC := gcc
CFLAGS := -Wall -Werror -Wextra -g -MMD  -pthread
RM := rm -rf
LIBS := -lpthread 
HEADER := inc/
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

