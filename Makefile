NAME	= cub3d

SRCSDIR	= src/
OBJSDIR = obj/


SRCS = main.c check_map.c ft_utils.c error.c init.c parser.c print.c free.c map_error.c map_error_utils.c set_direction.c parser_utils.c load_textur.c rendering_engine.c drawing.c key_hook.c move_player.c


OBJS	= $(addprefix $(OBJSDIR), $(SRCS:.c=.o))

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
MLXFRAGS = -lX11 -lXext -lm

LIBFTDIR	= libft/
LIBFTNAME	= libft.a
MLXDIR		= minilibx/
MLXNAME		= libmlx.a

all:$(NAME)

$(NAME):$(OBJS)
	$(MAKE) -C $(LIBFTDIR)
	$(MAKE) -C $(MLXDIR)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) -L$(LIBFTDIR) -lft -L$(MLXDIR) -lmlx $(MLXFRAGS)

$(OBJSDIR)%.o:$(SRCSDIR)%.c
	@mkdir -p $(OBJSDIR)
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

$(MLXDIR)$(MLXNAME):
	$(MAKE) -C $(MLXDIR)

$(LIBFTDIR)$(LIBFTNAME):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) $(OBJS)
	rm -rf $(OBJSDIR)
	$(MAKE) -C $(LIBFTDIR) clean
	$(MAKE) -C $(MLXDIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean
	$(MAKE) -C $(MLXDIR) fclean

re: fclean all
