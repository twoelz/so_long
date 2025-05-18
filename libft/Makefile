# static library name
NAME = libft.a
# compiler for c sources
CC = cc
# compiler for static library
LIBC = ar rcs
# list sources. wildcards are not allowed
MY_SOURCES = ft_atoi.c \
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
		get_next_line.c \
		get_next_line_utils.c \
# compiler flags
CFLAGS = -Wall -Wextra -Werror
# remove files without asking
RM = rm -f
# .o files same name as .c, but in obj folder
OBJDIR = obj
MY_OBJECTS = $(MY_SOURCES:.c=.o)
MY_OBJECTS := $(addprefix $(OBJDIR)/, $(MY_OBJECTS))

# .c to .o compilation
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c -o $@ $< -I .

# create static library, if the objects are newer than library
$(NAME): $(MY_OBJECTS)
	if [ ! -f $(NAME) ] || [ $(MY_OBJECTS) -nt $(NAME) ]; then \
		${LIBC} ${NAME} ${MY_OBJECTS}; \
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