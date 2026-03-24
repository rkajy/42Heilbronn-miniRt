# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asando <asando@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/24 18:44:11 by asando            #+#    #+#              #
#    Updated: 2026/03/24 19:16:48 by asando           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC ?= cc
DEBUG ?= 0
BONUS ?= 0
CFLAGS := -Wall -Wextra -Werror -Wunreachable-code -0fast

LIB_DIR := ./lib
LIBFT_DIR := $(LIB_DIR)/libft
MLX42_DIR := $(LIB_DIR)/MLX42

HEADER := include
HEADER_LIBFT := $(LIBFT_DIR)/includes
HEADER_MLX42 := $(MLX42_DIR)/include
HEADER_ALL := -I$(HEADER) -I$(HEADER_LIBFT) -I$(HEADER_MLX42)
# COLOR AND SYMBOL

GREEN := \033[1;32m
RED := \033[1;31m
BLUE := \033[1;34m
RESET := \033[0m

OK := ✔
FAIL := ✖
ARROW := ➜

# RULES

all: submodules

submodules:
	@if [ ! -f "$(LIBFT_DIR)/Makefile" ] || \
		[ ! -f "$(MLX42_DIR)/CMakeLists.txt" ]; then \
		printf "$(ARROW) initializing submodules...\n"; \
		printf "$(ARROW) cloning...\n"; \
		git submodules update --init --recursive > /dev/null 2>&1; \
		printf "$(GREEN)$(OK) libft and MLX42 are ready\n$(RESET)"; \
	fi
