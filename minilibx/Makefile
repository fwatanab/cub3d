NAME	= libmlx.a

SRCS	= mlx_init.c mlx_new_window.c mlx_pixel_put.c mlx_loop.c \
mlx_mouse_hook.c mlx_key_hook.c mlx_expose_hook.c mlx_loop_hook.c \
mlx_int_anti_resize_win.c mlx_int_do_nothing.c \
mlx_int_wait_first_expose.c mlx_int_get_visual.c \
mlx_flush_event.c mlx_string_put.c mlx_set_font.c \
mlx_new_image.c mlx_get_data_addr.c \
mlx_put_image_to_window.c mlx_get_color_value.c mlx_clear_window.c \
mlx_xpm.c mlx_int_str_to_wordtab.c mlx_destroy_window.c \
mlx_int_param_event.c mlx_int_set_win_event_mask.c mlx_hook.c \
mlx_rgb.c mlx_destroy_image.c mlx_mouse.c mlx_screen_size.c \
mlx_destroy_display.c

OBJS	= $(SRCS:.c=.o)

CC		= cc
RM		= rm -f

$(NAME):$(OBJS)
		ar crs $(NAME) $(OBJS)

all:$(NAME)

.c.o:
	$(CC) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re
