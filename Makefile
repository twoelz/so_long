NAME = learn_mlx

# compiler settings
CC = cc
CFLAGS = -Wall -Werror -Wextra

# library (libft) settings
DIR_LIBFT = libft
LIBFT = $(DIR_LIBFT)/libft.a
LIBS = -Llibft -lft

# push swap settings
DIR_INCLUDE = include
INCLUDE = -I $(DIR_LIBFT) -I $(DIR_INCLUDE)
SRCDIR = src
OBJDIR = src/obj
SRCS = main.c \

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

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@make -C $(DIR_LIBFT) clean

fclean: clean
	$(RM) -r $(OBJDIR)
	$(RM) $(NAME)
	$(RM) $(BONUS)
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

.PHONY: all clean fclean re release debug