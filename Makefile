NAME		=	cub3D

LIBFT		=	libft.a

LIBFT_DIR	=	libft

MLX_DIR = minilibx-linux

BONUS_DIR	=	src_bonus

BONUS_SRCS	=	$(BONUS_DIR)/parsing/cardinal_directions.c \
				$(BONUS_DIR)/parsing/exit.c \
				$(BONUS_DIR)/parsing/floor_ceiling.c \
				$(BONUS_DIR)/main.c \
				$(BONUS_DIR)/parsing/instructions_parsing.c \
				$(BONUS_DIR)/parsing/map_parsing.c \
				$(BONUS_DIR)/parsing/stack.c \
				$(BONUS_DIR)/parsing/check_line.c \
				$(BONUS_DIR)/parsing/map.c \
				$(BONUS_DIR)/parsing/parsing_utils.c \
				$(BONUS_DIR)/parsing/color_parsing.c \
				$(BONUS_DIR)/horizontal_distance.c \
				$(BONUS_DIR)/vertical_distance.c \
				$(BONUS_DIR)/textures.c \
				$(BONUS_DIR)/pixel_array.c \
				$(BONUS_DIR)/clean.c \
				$(BONUS_DIR)/keys.c \
				$(BONUS_DIR)/minimap.c \
				$(BONUS_DIR)/anim.c \
				$(BONUS_DIR)/door_textures.c \
				$(BONUS_DIR)/doors.c \
				$(BONUS_DIR)/parsing/doors_check.c \
				$(BONUS_DIR)/game_init.c \
				$(BONUS_DIR)/free_images.c \
				$(BONUS_DIR)/handle_input.c \
				$(BONUS_DIR)/draw_rays.c \
				$(BONUS_DIR)/draw_doors.c \
				$(BONUS_DIR)/utils.c

BONUS_OBJS	=	$(BONUS_SRCS:.c=.o)

SRC_DIR		=	src

SRCS		=	$(SRC_DIR)/parsing/cardinal_directions.c \
				$(SRC_DIR)/parsing/exit.c \
				$(SRC_DIR)/parsing/floor_ceiling.c \
				$(SRC_DIR)/main.c \
				$(SRC_DIR)/parsing/instructions_parsing.c \
				$(SRC_DIR)/parsing/map_parsing.c \
				$(SRC_DIR)/parsing/stack.c \
				$(SRC_DIR)/parsing/check_line.c \
				$(SRC_DIR)/parsing/map.c \
				$(SRC_DIR)/parsing/parsing_utils.c \
				$(SRC_DIR)/parsing/color_parsing.c \
				$(SRC_DIR)/horizontal_distance.c \
				$(SRC_DIR)/vertical_distance.c \
				$(SRC_DIR)/textures.c \
				$(SRC_DIR)/pixel_array.c \
				$(SRC_DIR)/clean.c \
				$(SRC_DIR)/keys.c \
				$(SRC_DIR)/minimap.c \
				$(SRC_DIR)/doors.c \
				$(SRC_DIR)/game_init.c \
				$(SRC_DIR)/free_images.c \
				$(SRC_DIR)/handle_input.c \
				$(SRC_DIR)/draw_rays.c \
				$(SRC_DIR)/utils.c

OBJS		=	$(SRCS:.c=.o)

DEPS		=	header

CFLAGS		+=	-Wall \
				-Werror \
				-Wextra \
				-I$(DEPS)

MLX_FLAGS	=	-Lminilibx-linux \
				-lmlx_Linux \
				-lX11 \
				-lXext

all: $(NAME)

$(NAME): $(OBJS)
		@make -C $(LIBFT_DIR)
		@make -C $(MLX_DIR)
		@make bonus -C $(LIBFT_DIR)
		@cc $(CFLAGS) $(OBJS) $(LIBFT_DIR)/$(LIBFT) -o $(NAME) $(MLX_FLAGS) -lm

clean:
		@make clean -C $(LIBFT_DIR)
		@#make clean -C $(MLX_DIR)
		@rm -f $(OBJS)
		@rm -f $(BONUS_OBJS)

fclean: clean
		@make fclean -C $(LIBFT_DIR)
		@rm -f $(NAME)

re: fclean
		@make all

bonus: $(BONUS_OBJS)
		@make -C $(LIBFT_DIR)
		@make -C $(MLX_DIR)
		@make bonus -C $(LIBFT_DIR)
		@cc $(CFLAGS) $(BONUS_OBJS) $(LIBFT_DIR)/$(LIBFT) -o $(NAME) $(MLX_FLAGS) -lm

.PHONY: re fclean clean all bonus