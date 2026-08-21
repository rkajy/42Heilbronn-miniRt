# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: radandri <radandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/24 18:44:11 by asando            #+#    #+#              #
#    Updated: 2026/07/12 20:18:06 by radandri         ###   ########.fr        #
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
MLX42_LIB := $(MLX42_DIR)/build/libmlx42.a
MLX42_LIBS := -ldl -lglfw -pthread -lm

CPPFLAGS := -Iinclude -I$(LIBFT_DIR)/includes -I$(MLX42_DIR)/include
ifeq ($(DEBUG),1)
CPPFLAGS += -DDEBUG=1
else
CPPFLAGS += -DDEBUG=0
endif
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -Ofast $(CPPFLAGS)

C_SRC := \
	src/main.c \
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
	src/parsing/parse_transform.c \
	src/parsing/error.c \
	src/parsing/error_message.c \
	src/parsing/scene_rt_factory.c \
	src/parsing/parsing-utils/ft_atof.c \
	src/parsing/parsing-utils/clean_line.c \
	src/parsing/parsing-utils/ft_isspace.c \
	src/parsing/parsing-utils/is_comment_or_empty.c \
	src/parsing/parsing-utils/ft_free_split.c \
	src/parsing/parsing-utils/is_file_extension_valid.c \
	src/parsing/parsing-utils/is_input_valid.c \
	src/parsing/parsing-utils/destroy_scene.c \
	src/parsing/parsing-utils/debug_dump_scene.c \
	src/parsing/parsing-utils/debug_dump_shapes.c \
	src/parsing/parsing-utils/normalize_vector.c \
        src/math/math_ray.c \
        src/math/math_vec3_adv_ops.c \
        src/math/math_vec3_init.c \
        src/math/math_vec3_ops.c \
        src/math/math_vec3_utils.c \
        src/objects/objects_cylinder.c \
        src/objects/objects_cylinder_caps.c \
        src/objects/objects_plane.c \
        src/objects/objects_sphere.c \
        src/render/render.c \
        src/render/render_mlx.c \
        src/render/render_shade.c \
        src/render/render_shadow.c \
        src/render/render_trace.c \
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

all: submodules $(NAME) $(LIBFT_NAME) $(LIBFT_PRINTF_NAME) $(MLX42_LIB)
	@echo "$(GREEN)$(OK) $(NAME) built successfully!$(RESET)"

$(NAME): $(OBJ_DIR) $(SRC_OBJ) $(LIBFT_NAME) $(LIBFT_PRINTF_NAME) $(MLX42_LIB)
	@$(CC) $(CFLAGS) $(SRC_OBJ) $(LIBFT_NAME) $(LIBFT_PRINTF_NAME) \
		$(MLX42_LIB) $(MLX42_LIBS) -o $(NAME)
	@echo "$(GREEN)$(OK) executable created!$(RESET)"

$(MLX42_LIB):
	@cmake $(MLX42_DIR) -B $(MLX42_DIR)/build
	@cmake --build $(MLX42_DIR)/build -j4
	@echo "$(GREEN)$(OK) MLX42 built successfully!$(RESET)"

submodules:
	@if [ ! -f "$(LIBFT_DIR)/Makefile" ] || \
		[ ! -f "$(MLX42_DIR)/CMakeLists.txt" ]; then \
		printf "$(ARROW) initializing submodules...\n"; \
		printf "$(ARROW) cloning...\n"; \
		git submodule update --init --recursive > /dev/null 2>&1; \
		printf "$(GREEN)$(OK) libft and MLX42 are ready\n$(RESET)"; \
	fi

$(LIBFT_NAME):
	@$(MAKE) -C $(LIBFT_DIR) bonus > /dev/null 2>&1
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
