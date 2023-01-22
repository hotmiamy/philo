# C Compiler
CC		:=	clang
# Compiler flags
CFLAGS	:=	-Wall -Wextra -Werror -pthread -g 
# Removal tool
RM		:=	rm -rf


# PROGRAM
# Program name
NAME		:= philo

# Header that includes all headers
H_MASTER	:=	philo.h
# Headers
HEADER_DIR	:=	inc
HEADER		:=	philo.h
H_INCLUDE	:=	$(addprefix -I, $(HEADER_DIR))

# Source
SRC_DIR		:=	src src/utils
SRC			:=	main.c init.c free_exit.c phi_routine.c vigilant.c actions.c
SRC			+=	ft_atoi.c phi_lst_add.c time.c print_action.c ft_isdigit.c check.c

# Object
OBJ_DIR		:=	obj
OBJ			:=	$(SRC:%.c=$(OBJ_DIR)/%.o)

# Precompiled header
C_HEADER	:=	$(H_MASTER:%.h=$(OBJ_DIR)/%.h.gch)
C_INCLUDE	:=	$(addprefix -include-pch , $(C_HEADER))

# Inclusions:
INCLUDE		:=	$(C_INCLUDE) $(H_INCLUDE) $(LIBFT_H_INC)

# vpath
vpath	%.h		$(HEADER_DIR)
vpath	%.c		$(SRC_DIR)

# -----------------------RULES------------------------------------------------ #
.PHONY: all vg norm clean fclean re

# Creates NAME
all: $(NAME)

# Compiles OBJ and LIBFT into the program NAME
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(INCLUDE)

# Compiles SRC into OBJ
$(OBJ): $(OBJ_DIR)/%.o: %.c $(C_HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(INCLUDE)

# Header precompiling
$(C_HEADER): $(OBJ_DIR)/%.h.gch: %.h $(HEADER) | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -o $@ $< $(H_INCLUDE)

# Directory making
$(OBJ_DIR):
	@mkdir -p $@

# Run program using valgrind
vg:
	valgrind --tool=helgrind --log-file=log_vg  ./$(NAME) 2 300 100 100 2

# Norm: checks code for norm errors
norm:
	@norminette | grep "Error" | cat

# Clean: removes objects' directory
clean:
	@$(RM) $(OBJ_DIR) $(C_HEADER_DIR)

# Full clean: removes objects' directory and generated libs/programs
fclean: clean
	$(RM) $(NAME)

# Remake: full cleans and runs 'all' rule
re: fclean all