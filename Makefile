# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alexfuen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/12 19:12:09 by alexfuen          #+#    #+#              #
#    Updated: 2026/01/12 19:12:11 by alexfuen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = $(addprefix $(SRC_DIR)/,  close_program.c\
				create_map.c\
				display.c\
				ft_split.c\
			 	gnl.c\
			 	img_initialize.c\
			 	initialize.c\
			 	initialize_map.c\
			 	main.c main_utils.c\
			 	parser.c\
			 	parser_utils.c\
			 	player_move.c\
			 	player_move_bis.c\
			 	put_image.c\
			 	utils.c)

SRC_BONUS = $(addprefix $(SRC_BONUS_DIR)/, display_bonus.c\
					   display_bis_bonus.c\
					   ft_split_bonus.c\
					   mob_spawn_bonus.c\
					   core_bonus.c\
					   close_program_bonus.c\
					   main_utils_bonus.c\
					   gnl_bonus.c\
					   img_initialize_bonus.c\
					   create_map_bonus.c\
					   initialize_bonus.c\
					   initialize_map_bonus.c\
					   main_bonus.c\
					   parser_bonus.c\
					   parser_utils_bonus.c\
					   player_move_bonus.c\
					   player_move_bis_bonus.c\
					   mob_position_update_bonus.c\
					   put_image_bonus.c\
					   utils_bonus.c\
					   display_moves_count_bonus.c)
				 
CC = cc
NAME = so_long
BONUS = so_long_bonus
M_DIR = minilibx-linux
SRC_DIR = mandatory
OBJS = $(SRC:.c=.o)
SRC_BONUS_DIR = bonus
OBJS_BONUS = $(SRC_BONUS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
MLBX = $(M_DIR)/libmlx.a -lXext -lX11
RM = rm

all: $(NAME)

bonus : $(BONUS)

$(NAME) : $(M_DIR) $(OBJS)
	make -C $(M_DIR)
	$(CC) $(OBJS) -o $(NAME) $(MLBX)

$(BONUS) : $(M_DIR) $(OBJS_BONUS)
	make -C $(M_DIR)
	$(CC) $(OBJS_BONUS) -o $(NAME) $(MLBX)

$(M_DIR) : 
	git clone https://github.com/42paris/minilibx-linux.git $(M_DIR)

clean:
	$(RM) -f $(OBJS)
	$(RM) -f $(OBJS_BONUS)
	make clean -C $(M_DIR)

fclean : clean
	$(RM) -f $(NAME)
	$(RM) -f $(BONUS)

re : fclean all

.PHONY: all clean fclean re bonus
