NAME = so_long
BONUS = so_long_bonus

# compiler settings
CC = cc
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -Ofast

# LIBFT settings
DIR_LIBFT = libft
LIBFT = $(DIR_LIBFT)/libft.a

# mlx settings
LIBMLX	:= ./MLX42

all: libmlx
	@$(MAKE) $(NAME)
	@$(MAKE) $(BONUS)

bonus: libmlx
	@$(MAKE) $(BONUS)

libmlx:
	@if [ ! -d $(LIBMLX) ]; then \
		git clone --branch v2.4.1 --depth 1 https://github.com/codam-coding-college/MLX42.git; \
		cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4; \
	else \
		echo "MLX42 already cloned, skipping clone and compile"; \
	fi

LIBS = -Llibft -lft $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

DIR_INCLUDE = include
INCLUDE = -I $(DIR_LIBFT) -I $(DIR_LIBFT)/include -I $(DIR_INCLUDE) -I $(LIBMLX)/include
SRCDIR = src
OBJDIR = src/obj
COMMON_SRCS = so_long.c \
	coordinates.c \
	error.c \
	exit.c \
	free_everything.c \
	game_loop.c \
	input.c \
	moves.c \
	moves_helper.c \
	my_mlx_cleanup.c \
	print_stuff.c \
	process_position.c \
	tile_image_change.c \
	tile_images_add.c \
	tile_images_load.c \
	validate_map.c \
	validate_map_file.c \
	validate_map_items.c \
	utils/free_utils.c \
	utils/str_utils.c

SRCS = main.c \
	mock_bonus/mock_bonus.c
SRCS += $(COMMON_SRCS)

BONUS_SRCS = bonus/main_bonus.c \
	bonus/free_everything_bonus.c \
	bonus/game_loop_bonus.c \
	bonus/init_bonus.c
BONUS_SRCS += $(COMMON_SRCS)

OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJDIR)/, $(OBJS))

BONUS_OBJS = $(BONUS_SRCS:.c=.o)
BONUS_OBJS := $(addprefix $(OBJDIR)/, $(BONUS_OBJS))

RM = rm -f

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS) $(LIBS)

$(BONUS): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS_BONUS) $(INCLUDE) -o $(BONUS) $(BONUS_OBJS) $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(LIBFT):
	@$(MAKE) -C $(DIR_LIBFT)

clean:
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)
	@$(MAKE) -C $(DIR_LIBFT) clean

fclean: clean
	$(RM) -r $(OBJDIR)
	$(RM) $(NAME)
	$(RM) $(BONUS)
	@$(MAKE) -C $(DIR_LIBFT) fclean

re: fclean all

release: CFLAGS += -O3
release:
	@$(MAKE) -C $(DIR_LIBFT) CFLAGS="-Wall -Werror -Wextra -O3"
	@$(MAKE) all

debug: CFLAGS += -g3 -DDEBUG
debug:
	@$(MAKE) -C $(DIR_LIBFT) CFLAGS="-Wall -Werror -Wextra -g3 -DDEBUG"
	@$(MAKE) all

debug_sanitize: CFLAGS += -g3 -DDEBUG -fsanitize=address
debug_sanitize:
	@$(MAKE) -C $(DIR_LIBFT) clean
	@$(MAKE) -C $(DIR_LIBFT) CFLAGS="-Wall -Werror -Wextra -g3 -DDEBUG -fsanitize=address"
	$(MAKE) clean
	$(MAKE) LIBS="-Llibft -lft $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm -fsanitize=address"

.PHONY: all clean fclean re libmlx bonus release debug
