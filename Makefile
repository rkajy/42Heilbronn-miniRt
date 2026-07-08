# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: radandri <radandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/24 18:44:11 by asando            #+#    #+#              #
#    Updated: 2026/07/08 03:28:45 by radandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := miniRT
CC ?= cc
DEBUG ?= 0
BONUS ?= 0

LIB_DIR := ./lib
LIBFT_DIR := $(LIB_DIR)/libft
LIBFT_NAME := $(LIBFT_DIR)/libft.a
LIBFT_PRINTF_NAME := $(LIBFT_DIR)/libftprintf.a
MLX42_DIR := $(LIB_DIR)/MLX42

CPPFLAGS := -Iinclude -I$(LIBFT_DIR)/includes -I$(MLX42_DIR)/include
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Ofast $(CPPFLAGS)

C_SRC := \
	src/main.c \
	src/math/math_first.c \
	src/parsing/parse_ambient.c \
	src/parsing/parse_color.c \
	src/parsing/parse_double.c \
	src/parsing/parse_light.c \
	src/parsing/parse_plane.c \
	src/parsing/parse_vec3.c \
    src/parsing/parse_camera.c \
    src/parsing/parse_cylinder.c \
    src/parsing/parse_file.c \
    src/parsing/parse_line.c \
    src/parsing/parse_sphere.c \
	src/parsing/error.c \
	src/parsing/error_message.c \
	src/utils/ft_atof.c \
	src/utils/clean_line.c \
	src/utils/ft_isspace.c \
	src/utils/is_comment_or_empty.c \
	src/utils/ft_free_split.c \
	src/utils/is_file_extension_valid.c \
	src/utils/is_input_valid.c \
	src/utils/destroy_scene.c \
	src/parsing/validate_scene.c \
	src/parsing/validate_tokens.c \
	src/parsing/validate_values.c \
	
OBJ_DIR := build/obj

SRC_OBJ := $(C_SRC:src/%.c=$(OBJ_DIR)/%.o)

# COLOR AND SYMBOL

GREEN := \033[1;32m
RED := \033[1;31m
BLUE := \033[1;34m
RESET := \033[0m

OK := ✔
FAIL := ✖
ARROW := ➜

# RULES

all: submodules $(NAME) $(LIBFT_NAME) $(LIBFT_PRINTF_NAME)
	@echo "$(GREEN)$(OK) $(NAME) built successfully!$(RESET)"

$(NAME): $(OBJ_DIR) $(SRC_OBJ) $(LIBFT_NAME) $(LIBFT_PRINTF_NAME)
	@$(CC) $(CFLAGS) $(SRC_OBJ) $(LIBFT_NAME) $(LIBFT_PRINTF_NAME) -o $(NAME)
	@echo "$(GREEN)$(OK) executable created!$(RESET)"

submodules:
	@if [ ! -f "$(LIBFT_DIR)/Makefile" ] || \
		[ ! -f "$(MLX42_DIR)/CMakeLists.txt" ]; then \
		printf "$(ARROW) initializing submodules...\n"; \
		printf "$(ARROW) cloning...\n"; \
		git submodule update --init --recursive > /dev/null 2>&1; \
		printf "$(GREEN)$(OK) libft and MLX42 are ready\n$(RESET)"; \
	fi

$(LIBFT_NAME):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "$(GREEN)$(OK) libft built successfully!$(RESET)"

$(LIBFT_PRINTF_NAME):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "$(GREEN)$(OK) libft printf built successfully!$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)$(OK) Object directory created!$(RESET)"

$(OBJ_DIR)/%.o: src/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)$(OK) object files removed!$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1
	@$(MAKE) -f .github/Makefile.tests clean
	@printf "$(ARROW)  libft cleaned\n"

	
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null 2>&1

re: fclean all

test:
	make -f .github/Makefile.tests test

test-cmake:
	make -f .github/Makefile.tests test-cmake
	
.PHONY: all submodules clean fclean re