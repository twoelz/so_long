# static library name
NAME = libft.a
# compiler for c sources
CC = cc
# compiler for static library
LIBC = ar rcs
# list sources. wildcards are not allowed
SRCS = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \

# fd_stdout
SRCS += stdout_fd/ft_putchar.c \
		stdout_fd/ft_putendl.c \
		stdout_fd/ft_putnbr.c \
		stdout_fd/ft_putstr.c \

# get next line sources
SRCS += get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \

# ft_printf sources
SRCS += ft_printf/data_generic.c \
		ft_printf/ft_printf.c \
		ft_printf/print_buf.c \
		ft_printf/data_int.c \
		ft_printf/data_str.c \
		ft_printf/data_uint.c \
		ft_printf/parse_flags.c \
		ft_printf/parse_generic.c \
		ft_printf/print_arg_types.c \
		ft_printf/print_buf_number.c \
		ft_printf/print_generic.c \
		ft_printf/util_data.c \
		ft_printf/util_number.c \

# compiler flags
CFLAGS = -Wall -Wextra -Werror
# remove files without asking
RM = rm -f
# .o files same name as .c, but in obj folder
DIR_INCLUDE = include
INCLUDE = -I $(DIR_INCLUDE)
SRCDIR = src
OBJDIR = src/obj
OBJS = $(SRCS:.c=.o)
OBJS := $(addprefix $(OBJDIR)/, $(OBJS))

# .c to .o compilation
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} ${INCLUDE} -c -o $@ $<

# create static library, if the objects are newer than library
$(NAME): $(OBJS)
	if [ ! -f $(NAME) ] || [ $(OBJS) -nt $(NAME) ]; then \
		${LIBC} ${NAME} ${OBJS}; \
	fi

# default (first) rule
all: ${NAME}

# cleans just the .o files
clean:
	${RM} ${MY_OBJECTS}

# cleans .o + the static lib created before
fclean: clean
	${RM} ${NAME} libft.so
	${RM} -r ${OBJDIR}

# rebuild everything
re: fclean all

so: CFLAGS += -fPIC
so: $(MY_OBJECTS)
	$(CC) -shared -o libft.so $(MY_OBJECTS)

.PHONY: all clean fclean re so