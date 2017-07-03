# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbodak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/19 15:46:49 by mbodak            #+#    #+#              #
#    Updated: 2017/04/29 14:14:12 by mbodak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= lem-in

GCC		= gcc

FLAG	= -Wall -Wextra -Werror

SRC		= validation.c parse_rooms.c parse_links.c build_matrix.c	\
		  breadth_first_search.c find_parallel_ways.c count_steps.c \
		  get_best_ways.c create_ants_struct.c push_ants.c          \
		  free_memory.c free_memory_2.c main.c

OBJ		= $(SRC:.c=.o)

LIB     = libft/

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	$(CC) $(CFLAGS) $(SRC) $(LIB)libft.a -o $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -c $<  -o $@

clean:
	make -C $(LIB) clean
	$(RM) $(OBJ)

fclean : clean
		make fclean -C libft/
		rm -rf $(NAME)

re : 	fclean all
