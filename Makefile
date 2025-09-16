NAME := fractol

# ----- Diretórios -----
LIBFT_DIR   := libft
PRINTF_DIR  := printf
MLX_DIR     := minilibx-linux
INCLUDE_DIR       := include
SRC_MANDATORY_DIR := src/mandatory
SRC_BONUS_DIR     := src/bonus
OBJ_MANDATORY_DIR := obj/mandatory
OBJ_BONUS_DIR     := obj/bonus

SRCS_MANDATORY_NAMES := main.c ft_free.c ft_utils_eventos.c ft_draw.c ft_mandel.c \
                        ft_julia.c ft_zoom.c ft_inits.c ft_parse.c ft_calculate_iters.c \
						ft_color_smooth.c
SRCS_BONUS_NAMES     := main_bonus.c ft_free_bonus.c ft_utils_eventos_bonus.c ft_draw_bonus.c ft_mandel_bonus.c \
                        ft_julia_bonus.c ft_zoom_bonus.c ft_inits_bonus.c ft_parse_bonus.c ft_calculate_iters_bonus.c \
						ft_color_smooth_bonus.c ft_burning_ship_bonus.c ft_move_bonus.c

SRCS_MANDATORY := $(addprefix $(SRC_MANDATORY_DIR)/,$(SRCS_MANDATORY_NAMES))
SRCS_BONUS     := $(addprefix $(SRC_BONUS_DIR)/,$(SRCS_BONUS_NAMES))

OBJS_MANDATORY := $(addprefix $(OBJ_MANDATORY_DIR)/,$(SRCS_MANDATORY_NAMES:.c=.o))
OBJS_BONUS     := $(addprefix $(OBJ_BONUS_DIR)/,$(SRCS_BONUS_NAMES:.c=.o))
# ----- Compilação & Linkagem -----

# Variável para determinar quais arquivos .o serão linkados
OBJS := $(addprefix $(OBJ_MANDATORY_DIR)/,$(SRCS_MANDATORY_NAMES:.c=.o))

CC      := cc
CFLAGS  := -Wall -Wextra -Werror \
           -I$(INCLUDE_DIR) \
           -I$(LIBFT_DIR)/include \
           -I$(PRINTF_DIR)/include \
           -I$(MLX_DIR) 
		   

# Ordem importa: objetos primeiro, depois libs.
LDFLAGS := \
  -L$(PRINTF_DIR) -lftprintf \
  -L$(LIBFT_DIR)  -lft \
  -L$(MLX_DIR)    -lmlx -lX11 -lXext -lm

# Alvos das libs (arquivos gerados pelos próprios projetos)
LIBFT_A     := $(LIBFT_DIR)/libft.a
PRINTF_A    := $(PRINTF_DIR)/libftprintf.a
MLX_A       := $(MLX_DIR)/libmlx.a

# ----- Alvos principais -----
.PHONY: all clean fclean re run

all: $(NAME)

$(NAME): $(LIBFT_A) $(PRINTF_A) $(MLX_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o $@
	@echo "✅ $(NAME) criado com sucesso."

bonus:
	$(MAKE) OBJS="$(OBJS_BONUS)" all

# mandatory
$(OBJ_MANDATORY_DIR)/%.o: $(SRC_MANDATORY_DIR)/%.c | $(OBJ_MANDATORY_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# bonus
$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c | $(OBJ_BONUS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@


# ----- Dependências (sub-makes) -----
# libft completa (teu Makefile tem o alvo 'full' = all + bonus)
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR) full --no-print-directory

# printf com bônus (flags, etc.)
$(PRINTF_A):
	@$(MAKE) -C $(PRINTF_DIR) bonus --no-print-directory

# minilibx (usa o Makefile próprio)
$(MLX_A):
	@$(MAKE) -C $(MLX_DIR) --no-print-directory

# ----- Utilidades -----
clean:
	@rm -rf $(OBJ_MANDATORY_DIR) $(OBJ_BONUS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean  --no-print-directory
	@$(MAKE) -C $(PRINTF_DIR) clean --no-print-directory
	@echo "🧹 Objetos removidos."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR)  fclean --no-print-directory
	@$(MAKE) -C $(PRINTF_DIR) fclean --no-print-directory
	@echo "🧼 Binário e libs removidos."

re: fclean all

# ------- Criação das sub pasta para objs -----
$(OBJ_MANDATORY_DIR):
	mkdir -p $@

$(OBJ_BONUS_DIR):
	mkdir -p $@

release: CFLAGS += -O3
release: re

debug: CFLAGS += -O0 -g -fsanitize=address,undefined -fno-omit-frame-pointer
debug: re