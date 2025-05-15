NAME = learn_mlx

# compiler settings
CC = cc
CFLAGS = -Wall -Werror -Wextra -Wunreachable-code -Ofast

# LIBFT settings
DIR_LIBFT = libft
LIBFT = $(DIR_LIBFT)/libft.a

# mlx settings
LIBMLX	:= ./lib/MLX42

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

LIBS = -Llibft -lft (LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

DIR_INCLUDE = include
INCLUDE = -I $(DIR_LIBFT) -I $(DIR_INCLUDE) -I $(LIBMLX)/include
SRCDIR = src
OBJDIR = src/obj
SRCS = learn_mlx.c \

OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJDIR)/, $(OBJS))

RM = rm -f

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) -o $(NAME) $(OBJS) $(LIBS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

$(LIBFT):
	@make -C $(DIR_LIBFT)

all: libmlx $(NAME)

clean:
	$(RM) $(OBJS)
	@make -C $(DIR_LIBFT) clean
	@rm -rf $(LIBMLX)/build

fclean: clean
	$(RM) -r $(OBJDIR)
	$(RM) $(NAME)
	@make -C $(DIR_LIBFT) fclean

re: fclean all

release: CFLAGS += -O3
release:
	@make -C $(DIR_LIBFT) CFLAGS="-Wall -Werror -Wextra -O3"
	@make all

debug: CFLAGS += -g3 -DDEBUG
debug:
	@make -C $(DIR_LIBFT) CFLAGS="-Wall -Werror -Wextra -g3 -DDEBUG"
	@make all

.PHONY: all clean fclean re libmlx release debug