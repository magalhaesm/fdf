NAME		= fdf
INCLUDES	= fdf.h keycode.h
SOURCES		= main.c load_data.c scene.c draw_line.c draw_utils.c events.c \
						data_convert.c scene_utils.c rotation.c rotation_utils.c \
						translation.c controls.c

LIBFT		= ./libft/libft.a

SRCS_PATH	= src
OBJS_PATH	= obj
SRCS		= $(addprefix $(SRCS_PATH)/, $(SOURCES))
OBJS		= $(addprefix $(OBJS_PATH)/, $(SOURCES:.c=.o))

CFLAGS		= -Wall -Wextra -Werror -O3
RM			= rm -f

CYAN		= \033[1;36m
RESET		= \033[0m

MAPS = 10-2 10-70 20-60 42 42mod 50-4 100-6 basictest elem-col \
			 elem-fract elem elem2 error fdf invalid julia mars \
			 pentenegpos plat pnp_flat pylone-mod pylone pyra pyramide t1 t2

LOG			= printf "$(CYAN)info:$(RESET) %s\n"

all:		$(NAME)

bonus: all

norma:
	@norminette $(SRCS_PATH) include

$(NAME):	$(OBJS_PATH) $(LIBFT) $(OBJS) $(addprefix include/, $(INCLUDES))
	@$(LOG) "Compiling $(NAME)"
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lmlx -lXext -lX11 -lm -o $(NAME)

$(OBJS_PATH):
	@mkdir -p $(OBJS_PATH)

$(OBJS_PATH)/%.o:	$(SRCS_PATH)/%.c
	@$(LOG) "Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

%:
	@./$(NAME) maps/$@.fdf &

$(LIBFT):
	@$(LOG) "Compiling libft..."
	git submodule init
	git submodule update
	@make -C ./libft --no-print-directory

clean:
	@$(RM) -r $(OBJS_PATH)

fclean:	clean
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re bonus
