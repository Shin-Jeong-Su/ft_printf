NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = crus
RM = rm -f

SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)
SUB_LIB_DIR = ./libft
SUB_LIB = libft.a

all : $(NAME)

$(NAME) : $(OBJS) $(SUB_LIB_DIR)/$(SUB_LIB)
	cp $(SUB_LIB_DIR)/$(SUB_LIB) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(SUB_LIB_DIR)/$(SUB_LIB) :
	$(MAKE) -C $(SUB_LIB_DIR)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean : 
	$(RM) $(OBJS)
	$(MAKE) -C $(SUB_LIB_DIR) clean
fclean : clean
	$(RM) $(NAME)
	$(MAKE) -C $(SUB_LIB_DIR) fclean
re : fclean all