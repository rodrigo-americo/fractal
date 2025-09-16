NAME     := libftprintf.a

# Diretórios
SRC_MANDATORY_DIR := src/mandatory
SRC_BONUS_DIR     := src/bonus
OBJ_MANDATORY_DIR := obj/mandatory
OBJ_BONUS_DIR     := obj/bonus
INCLUDE_DIR       := include
LIBFT_DIR         := ../libft
LIBFT_A           := $(LIBFT_DIR)/libft.a

# Compilador e flags
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/include

# ===== Listas de fontes (nomes simples) =====
SRCS_MANDATORY := \
	ft_printf.c \
	ft_handle_format.c \
	ft_handle_string.c \
	ft_puthex.c \
	ft_putpoint.c \
	ft_putul_base.c

# Para o bônus, reusa os mandatórios sem os que conflitam
SRCS_MANDATORY_BONUS := $(filter-out ft_printf.c ft_handle_string.c,$(SRCS_MANDATORY))

SRCS_BONUS := \
	ft_zero_pad_prefixed_bonus.c \
	ft_is_flag_bonus.c \
	ft_apply_sign_flag_bonus.c \
	ft_apply_flags_hex_bonus.c \
	ft_apply_str_precision_bonus.c \
	ft_utoa_base_bonus.c \
	ft_handle_signed_bonus.c \
	ft_handle_unsigned_bonus.c \
	ft_handle_hex_bonus.c \
	ft_handle_flags_bonus.c \
	ft_handle_percent_bonus.c \
	ft_printf_bonus.c \
	ft_apply_width_bonus.c \
	ft_strdup_safe_bonus.c \
	ft_zero_pad_bonus.c \
	ft_handle_precission_bonus.c \
	ft_handle_string_bonus.c \
	ft_strjoin_free_bonus.c \
	ft_handle_char_bonus.c \
	ft_apply_int_precision_bonus.c \
	ft_handle_format_bonus.c \
	ft_handle_pointer_bonus.c \
	ft_start_flags_bonus.c

# ===== Objetos com addprefix =====
OBJS_MANDATORY       := $(addprefix $(OBJ_MANDATORY_DIR)/,$(SRCS_MANDATORY:.c=.o))
OBJS_MANDATORY_BONUS := $(addprefix $(OBJ_MANDATORY_DIR)/,$(SRCS_MANDATORY_BONUS:.c=.o))
OBJS_BONUS           := $(addprefix $(OBJ_BONUS_DIR)/,$(SRCS_BONUS:.c=.o))

# ===== Targets =====
.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS_MANDATORY)
	@cp $(LIBFT_A) $(NAME)
	@ar rcs $(NAME) $(OBJS_MANDATORY)
	@echo "✨ Mandatório: $(NAME) gerado"

# Garante que a libft exista (sem herdar VARs)
$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR) all --no-print-directory

# Compilação de objetos (pattern rules)
$(OBJ_MANDATORY_DIR)/%.o: $(SRC_MANDATORY_DIR)/%.c | $(OBJ_MANDATORY_DIR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_BONUS_DIR)/%.o: $(SRC_BONUS_DIR)/%.c | $(OBJ_BONUS_DIR)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

# Diretórios de objetos
$(OBJ_MANDATORY_DIR) $(OBJ_BONUS_DIR):
	@mkdir -p $@

# Bônus: libft + mandatórios reduzidos + bônus
bonus: $(LIBFT_A) $(OBJS_MANDATORY_BONUS) $(OBJS_BONUS)
	@cp $(LIBFT_A) $(NAME)
	@ar rcs $(NAME) $(OBJS_MANDATORY_BONUS) $(OBJS_BONUS)
	@echo "✨ Bônus:     $(NAME) gerado"

clean:
	@rm -rf $(OBJ_MANDATORY_DIR) $(OBJ_BONUS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo "🧹 Objetos limpos."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@echo "🧼 Tudo limpo (incluindo lib)."

re: fclean all
