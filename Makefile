NAME = learn_mlx

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

libmlx:
	@if [ ! -d $(LIBMLX) ]; then \
		git clone --branch v2.4.1 --depth 1 https://github.com/codam-coding-college/MLX42.git; \
		cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4; \
	else \
		echo "MLX42 already cloned, skipping clone and compile"; \
	fi

LIBS = -Llibft -lft $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

DIR_INCLUDE = include
INCLUDE = -I $(DIR_LIBFT) -I $(DIR_INCLUDE) -I $(LIBMLX)/include
SRCDIR = src
OBJDIR = src/obj
SRCS = learn_mlx.c \
	error.c \
	input.c \


OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJDIR)/, $(OBJS))

RM = rm -f

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS) $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(LIBFT):
	@$(MAKE) -C $(DIR_LIBFT)

clean:
	$(RM) $(OBJS)
	@$(MAKE) -C $(DIR_LIBFT) clean

fclean: clean
	$(RM) -r $(OBJDIR)
	$(RM) $(NAME)
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

.PHONY: all clean fclean re libmlx release debug