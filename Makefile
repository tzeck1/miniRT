# EXECUTABLE
NAME = ./miniRT

# FLAGS
CC = gcc
CFLAGS = -Wall -Wextra -g #-Werror

# COLORS
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

# PATHS
SRC_PATH = ./src/
PARS_PATH = ./src/parser/
VEC_PATH = ./src/vector/
OBJ_PATH = ./obj/
MLX_PATH = ./MLX42/
GLFW_PATH = ~/.brew/opt/glfw/lib/

# SOURCES
SRC =	$(SRC_PATH)main.c\
		$(PARS_PATH)init_objects.c	$(PARS_PATH)utils.c \
		$(PARS_PATH)init_amb_l.c	$(PARS_PATH)init_cam.c	$(PARS_PATH)init_dir_l.c \
		$(PARS_PATH)cylinder_list.c\
		$(VEC_PATH)vector.c\
		$(SRC_PATH)debug.c

# OBJECTS
OBJ = $(patsubst $(SRC_PATH)%.c, $(OBJ_PATH)%.o, $(SRC))

# RULES
all: $(NAME)
	@echo $(B)"                                                           "$(X)
	@echo $(B)"           ,--.          ,--. ,------.  ,--------.         "$(X)
	@echo $(B)",--,--,--. \`--' ,--,--,  \`--' |  .--. ' '--.  .--'       "$(X)
	@echo $(B)"|        | ,--. |      \ ,--. |  '--'.'    |  |            "$(X)
	@echo $(B)"|  |  |  | |  | |  ||  | |  | |  |\  \     |  |            "$(X)
	@echo $(B)"\`--\`--\`--' \`--' \`--''--' \`--' \`--' '--'    \`--'    "$(X)
	@printf "\n\n"

$(OBJ_PATH)%.o :$(SRC_PATH)%.c
	@echo $(Y)Compiling [$@]...$(X)
	@mkdir -p $(dir $@)
	@printf $(UP)$(CUT)
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo $(G)Finished [$@]$(X)
	@printf $(UP)$(CUT)

$(NAME): $(OBJ)
	@make -C MLX42
	@make -C libft
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_PATH)libmlx42.a -lglfw -L $(GLFW_PATH) libft/libft.a -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

clean:
	@make clean -C MLX42
	@make clean -C libft
	@if [ -d "$(OBJ_PATH)" ]; then \
			rm -f -r $(OBJ_PATH); \
			echo $(R)Cleaning" "[$(OBJ) $(OBJ_PATH)]$(X); else \
			echo "No objects to remove."; \
	fi;

fclean: clean
	@make fclean -C MLX42
	@make fclean -C libft
	@if [ -f "$(NAME)" ]; then \
			rm -f $(NAME); \
			echo $(R)Cleaning" "[$(NAME)]$(X);else \
			echo "No executable to remove."; \
	fi;

re: fclean all

.PHONY: all, clean, fclean, re
