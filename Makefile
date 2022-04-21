# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pamartin <pamartin@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/05 12:31:38 by pamartin          #+#    #+#              #
#    Updated: 2022/04/05 12:31:40 by pamartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				=		fdf
NAME_B				=		fdf_bonus

### DIRECTORY
HEADER				= 		./include/
GNL					=		./gnl/
SOURCE_C			= 		./src_common/
SOURCE_M			=		./src_manda/
SOURCE_B			= 		./src_bonus/
OBJ_TMP				=		./obj/

### FILES
SRC_GNL				=		get_next_line.c  get_next_line_utils.c 
OBJ_GNL				= 		$(addprefix $(OBJ_TMP), $(SRC_GNL:%.c=%.o))
$(OBJ_TMP)%.o		:		$(GNL)%.c
								$(CC) $(FLAGS) -c $< -o $@ $(INCLUDE)

SRC_COMMON			= 		parsing.c  draw.c  utils.c	exit.c  init.c
OBJ_COMMON			= 		$(addprefix $(OBJ_TMP), $(SRC_COMMON:%.c=%.o))							
$(OBJ_TMP)%.o		:		$(SOURCE_C)%.c
								$(CC) $(FLAGS) -c $< -o $@ $(INCLUDE)


SRC_MANDA			= 		fdf.c animation.c 
OBJ_MANDA			= 		$(addprefix $(OBJ_TMP),  $(SRC_MANDA:%.c=%.o))
$(OBJ_TMP)%.o		:		$(SOURCE_M)%.c 
								$(CC) $(FLAGS) -c $< -o $@ $(INCLUDE)

SRC_BONUS			=		fdf_bonus.c draw_bonus.c z_bonus.c animation_bonus.c get_key_bonus.c get_mouse_bonus.c hook_bonus.c need_menus_bonus.c
OBJ_BONUS			=		$(addprefix $(OBJ_TMP),  $(SRC_BONUS:%.c=%.o))
$(OBJ_TMP)%.o		:		$(SOURCE_B)%.c 
								$(CC) $(FLAGS) -c $< -o $@ $(INCLUDE)

MANDA_TOT_OBJ		=		$(OBJ_COMMON) $(OBJ_GNL) $(OBJ_MANDA) 
BONUS_TOT_OBJ		=		$(OBJ_COMMON) $(OBJ_GNL) $(OBJ_BONUS) 

### COMMANDS
CC					= 		gcc
FLAGS				=		-Wall -Wextra -Werror
UTILS				=		-l mlx -framework OpenGL -framework AppKit
#UTILS 				=		-I /usr/X11/include -g -L /usr/X11/lib -l mlx -framework OpenGL -framework AppKit
LIB 				= 		./libft/libft.a
FSANITIZE 			=		-fsanitize=address
INCLUDE				= 		-I $(HEADER)
RM					=		rm -rf
MAKE 				= 		make

### GET OBJECTS ON TMP DIRECTORY
$(NAME)				:		$(OBJ_TMP) $(MANDA_TOT_OBJ)
							$(MAKE) -C Libft
							$(CC) $(FLAGS) $(UTILS) $(INCLUDE) $(LIB) -o $(NAME) $(MANDA_TOT_OBJ)

$(NAME_B)			:		$(OBJ_TMP) $(BONUS_TOT_OBJ)
							$(MAKE) -C Libft
							$(CC) $(FLAGS) $(UTILS) $(INCLUDE) $(LIB) -o $(NAME_B) $(BONUS_TOT_OBJ)

$(OBJ_TMP)			:	
								mkdir -p $(OBJ_TMP)		

### RULES
all					:		$(NAME)

bonus 				:		$(NAME_B)

clean				:
			$(RM) $(OBJ_TMP)
			$(MAKE) clean -C libft

fclean				:		clean
			$(RM) $(NAME) $(NAME_B)
			$(MAKE) fclean -C libft

push				:		fclean
			git add *
			git commit -m "Fdf"
			git push

re 					:		fclean 	all