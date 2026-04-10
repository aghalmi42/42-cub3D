
NAME = cub3D

BONUS = cub3D_bonus

SRCS =	srcs/main.c \
		srcs/parsing/parsing_map.c \
		srcs/parsing/parsing_map_utils.c \
		srcs/parsing/parsing_map_utils_2.c \
		srcs/parsing/parsing_map_utils_3.c \
		srcs/parsing/parsing_map_utils_4.c \
		srcs/parsing/parsing_map_utils_5.c \
		srcs/parsing/valid_map.c \
		srcs/parsing/valid_track_utils.c \
		srcs/parsing/valid_track.c \
		srcs/parsing/free_all.c \
		srcs/parsing/check.c \
		srcs/parsing/check_2.c \
		srcs/parsing/parsing_door.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		srcs/exec/hooks.c \
		srcs/exec/init.c \
		srcs/exec/move_player.c \
		srcs/exec/update_move_camera.c \
		srcs/exec/display_shape.c \
		srcs/exec/raycasting.c \
		srcs/exec/minimap.c \
		srcs/exec/2D_to_3D.c \
		srcs/exec/display_line.c \
		srcs/exec/display_line_set.c \
		srcs/exec/display_ray.c \
		srcs/exec/init_textures.c \
		srcs/exec/loop_update_ray.c \
		srcs/exec/update_game.c
		

SRCS_BONUS =	srcs_bonus/main_bonus.c \
				srcs_bonus/parsing/parsing_map_bonus.c \
				srcs_bonus/parsing/parsing_map_utils_bonus.c \
				srcs_bonus/parsing/parsing_map_utils_2_bonus.c \
				srcs_bonus/parsing/parsing_map_utils_3_bonus.c \
				srcs_bonus/parsing/parsing_map_utils_4_bonus.c \
				srcs_bonus/parsing/parsing_map_utils_5_bonus.c \
				srcs_bonus/parsing/valid_map_bonus.c \
				srcs_bonus/parsing/valid_track_utils_bonus.c \
				srcs_bonus/parsing/valid_track_bonus.c \
				srcs_bonus/parsing/free_all_bonus.c \
				srcs_bonus/parsing/check_bonus.c \
				srcs_bonus/parsing/check_2_bonus.c \
				srcs_bonus/parsing/parsing_door_bonus.c \
				srcs_bonus/exec/hooks_bonus.c \
				srcs_bonus/exec/init_bonus.c \
				srcs_bonus/exec/init_textures_bonus.c \
				srcs_bonus/exec/move_player_bonus.c \
				srcs_bonus/exec/update_move_camera_bonus.c \
				srcs_bonus/exec/update_game_bonus.c \
				srcs_bonus/exec/display_shape_bonus.c \
				srcs_bonus/exec/display_line_bonus.c \
				srcs_bonus/exec/display_line_set_bonus.c \
				srcs_bonus/exec/display_ray_bonus.c \
				srcs_bonus/exec/raycasting_bonus.c \
				srcs_bonus/exec/loop_update_ray_bonus.c \
				srcs_bonus/exec/minimap_bonus.c \
				srcs_bonus/exec/2D_to_3D_bonus.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \
				srcs_bonus/exec/init_doors_bonus.c

OBJDIR    = objs
OBJS        = $(SRCS:%.c=$(OBJDIR)/%.o)

OBJDIR_BONUS    = objs_bonus
OBJS_BONUS        = $(SRCS_BONUS:%.c=$(OBJDIR_BONUS)/%.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -g3
INCLUDES = -Iincludes -Ilibft -I./minilibx
INCLUDE_BONUS = -Iincludes_bonus -Ilibft -I./minilibx
LIBS	= -Llibft -lft -lm  -L./minilibx -lmlx -lXext -lX11 -lm

MLX_DIR = minilibx
MLX_LIB = $(MLX_DIR)/libmlx.a

LIBFT_DIR = ./libft
LIBFT	= $(LIBFT_DIR)/libft.a

RED		= \033[0;91m
GREEN	= \033[0;92m
BLUE	= \033[0;94m
RESET	= \033[0;39m

HEADER = includes/cub3D.h
HEADER_BONUS = includes_bonus/cub3D_bonus.h \
				includes_bonus/parsing_bonus.h \
				includes_bonus/exec_bonus.h \
				includes_bonus/struct_bonus.h

all: $(NAME)

bonus: $(BONUS)
$(LIBFT):
	@echo "$(BLUE)Compiling libft...$(RESET)"
	@make -C $(LIBFT_DIR) > /dev/null 2>&1  
	@echo "$(GREEN)libft compiled!$(RESET)"

$(MLX_LIB):
	@echo "$(BLUE)Compiling MiniLibX...$(RESET)"
	@make -C $(MLX_DIR) > /dev/null 2>&1
	@echo "$(GREEN)MiniLibX ready!$(RESET)"

$(NAME): $(MLX_LIB) $(LIBFT) $(OBJS) 
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(FLAGS) $(OBJS) \
		-L$(LIBFT_DIR) -lft \
		-L$(MLX_DIR) -lmlx -lXext -lX11 -lm \
		-o $(NAME)
	@echo "$(GREEN)$(NAME) created successfully!$(RESET)"

$(BONUS): $(MLX_LIB) $(LIBFT) $(OBJS_BONUS) 
	@echo "$(BLUE)Linking $(NAME)...$(RESET)"
	@$(CC) $(FLAGS) $(OBJS_BONUS) \
		-L$(LIBFT_DIR) -lft \
		-L$(MLX_DIR) -lmlx -lXext -lX11 -lm \
		-o $(BONUS)
	@echo "$(GREEN)$(BONUS) created successfully!$(RESET)"

$(OBJDIR_BONUS)/%.o: %.c $(HEADER_BONUS)
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o: %.c $(HEADER)
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
clean:
	@echo "$(RED)Cleaning...$(RESET)"
	@rm -rf $(OBJDIR) $(OBJDIR_BONUS)
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@make -C $(MLX_DIR) clean > /dev/null 2>&1


fclean: clean
	@echo "$(RED)Full clean...$(RESET)"
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean > /dev/null 2>&1

re: fclean all

.PHONY: all clean fclean re