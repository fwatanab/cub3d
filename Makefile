NAME	= cub3d

SRCSDIR	= src/

SRCS = main.c check_map.c ft_utils.c error.c init.c parser.c print.c free.c parser_utils.c key_hook.c

OBJS	= $(addprefix $(SRCSDIR), $(SRCS:.c=.o))

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
MLXFRAGS = -lX11 -lXext -lm
INC		= -I inc/ -I $(LIBFTDIR)
LIBFTDIR	= libft/
LIBFTNAME	= libft.a
MLXDIR		= minilibx/
MLXNAME		= libmlx.a

all:$(NAME)

$(NAME):$(OBJS)
	$(MAKE) -C $(LIBFTDIR)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFTDIR) -lft $(LFLAGS) -o $@
#	$(MAKE) -C $(MLXDIR)
#	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft -L$(MLXDIR) -lmlx $(MLXFRAGS)

.c.o:
#	 $(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
	$(CC) $(CFLAGS) $(INC) -I /usr/X11/include -I mlx -c $< -o $(<:.c=.o)
#	$(CC) $(CFLAGS) -Imlx -c $< -o $(<:.c=.o)

$(MLXDIR)$(MLXNAME):
	$(MAKE) -C $(MLXDIR)

$(LIBFTDIR)$(LIBFTNAME):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) $(OBJS)
	$(MAKE) -C $(LIBFTDIR) clean
#	$(MAKE) -C $(MLXDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
#	$(MAKE) -C $(MLXDIR) fclean

re: fclean all
