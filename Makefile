# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 16:38:07 by mpeulet           #+#    #+#              #
#    Updated: 2023/10/20 15:52:45 by mpeulet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colors

DEF_COLOR		= \033[0;39m
GRAY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m

#Colors / Perso / Bright

ORANGE			= \033[38;5;214m

#Variables

NAME 			= libft.a
INCLUDE			= include
SRC_DIR_LIB		= src_lib/
OBJ_DIR_LIB		= obj_lib/
CC				= cc
FLAGS			= -Wall -Werror -Wextra -I
RM				= rm -f
AR				= ar rcs

#Sources

BITS_DIR		= bits/
BITS_FUNCTIONS	= print_bits

GNL_DIR			= gnl/
GNL_FUNCTIONS	= gnl get_next_line_bonus get_next_line

IS_DIR			= is/
IS_FUNCTIONS	= ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_isprint ft_iswhitespace \
					ft_int_over_maxmin ft_is_sign

LST_DIR			= lst/
LST_FUNCTIONS	= ft_lstadd_back ft_lstadd_front ft_lstclear ft_lstdelone ft_lstiter \
					ft_lstlast ft_lstmap ft_lstnew ft_lstsize ft_sort_list
					
MATH_DIR		= math/
MATH_FUNCTIONS	= abs_value lcm pgcd

MEM_DIR			= mem/
MEM_FUNCTIONS	= ft_bzero ft_calloc ft_memchr ft_memcmp ft_memmove ft_memset ft_memcpy

OTH_DIR			= other/
OTH_FUNCTIONS	= ft_swap free_tab

PF_DIR			= printf/
PF_FUNCTIONS	= ft_printf ft_printf_c_s_d_i_u ft_printf_p_x_X ft_printf_fd

PUT_DIR			= put/
PUT_FUNCTIONS	= ft_putchar_fd ft_putendl_fd ft_putnbr_fd ft_putstr_fd ft_putchar_stdout \
					ft_putstr_stdout ft_putendl_stdout

TO_DIR			= to/
TO_FUNCTIONS	= ft_atoi ft_itoa ft_toupper ft_tolower ft_atof ft_atol

STR_DIR			= str/
STR_FUNCTIONS	= ft_split ft_strchr ft_strdup ft_striteri ft_strjoin ft_strlcat ft_strlcpy \
					ft_strlen ft_strmapi ft_strncmp ft_strnstr ft_strrchr ft_strtrim ft_substr \
					ft_strcmp ft_str_isdigit

TO_SRC+=$(addprefix $(BITS_DIR),$(BITS_FUNCTIONS))
TO_SRC+=$(addprefix $(GNL_DIR),$(GNL_FUNCTIONS))
TO_SRC+=$(addprefix $(IS_DIR),$(IS_FUNCTIONS))
TO_SRC+=$(addprefix $(LST_DIR),$(LST_FUNCTIONS))
TO_SRC+=$(addprefix $(MATH_DIR),$(MATH_FUNCTIONS))
TO_SRC+=$(addprefix $(MEM_DIR),$(MEM_FUNCTIONS))
TO_SRC+=$(addprefix $(OTH_DIR),$(OTH_FUNCTIONS))
TO_SRC+=$(addprefix $(PF_DIR),$(PF_FUNCTIONS))
TO_SRC+=$(addprefix $(PUT_DIR),$(PUT_FUNCTIONS))
TO_SRC+=$(addprefix $(TO_DIR),$(TO_FUNCTIONS))
TO_SRC+=$(addprefix $(STR_DIR),$(STR_FUNCTIONS))

SRC_LIB			= $(addprefix $(SRC_DIR_LIB), $(addsuffix .c, $(TO_SRC)))
OBJ_LIB			= $(addprefix $(OBJ_DIR_LIB), $(addsuffix .o, $(TO_SRC)))

IFMAKE_DIR_LIB	= .cache_exists

#Instructions

all: 			$(NAME)

$(NAME): 		$(OBJ_LIB)
						@$(AR) $(NAME) $(OBJ_LIB)
						@ranlib $(NAME)
						@echo "$(RED)S$(ORANGE)u$(YELLOW)c$(GREEN)c$(CYAN)e$(BLUE)s$(MAGENTA)s$(DEF_COLOR)"
						@echo "$(GREEN)Libft compiled!$(DEF_COLOR)"

$(OBJ_DIR_LIB)%.o : $(SRC_DIR_LIB)%.c | $(IFMAKE_DIR_LIB)
						@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

$(IFMAKE_DIR_LIB):
						@mkdir -p $(OBJ_DIR_LIB)
						@mkdir -p $(OBJ_DIR_LIB)$(BITS_DIR)
						@mkdir -p $(OBJ_DIR_LIB)$(GNL_DIR)
						@mkdir -p $(OBJ_DIR_LIB)$(IS_DIR)
						@mkdir -p $(OBJ_DIR_LIB)$(LST_DIR)
						@mkdir -p $(OBJ_DIR_LIB)$(MATH_DIR)
						@mkdir -p $(OBJ_DIR_LIB)$(MEM_DIR)
						@mkdir -p $(OBJ_DIR_LIB)$(OTH_DIR)
						@mkdir -p $(OBJ_DIR_LIB)$(PF_DIR)
						@mkdir -p $(OBJ_DIR_LIB)$(PUT_DIR)
						@mkdir -p $(OBJ_DIR_LIB)$(TO_DIR)
						@mkdir -p $(OBJ_DIR_LIB)$(STR_DIR)

clean:
						@$(RM) -rf $(OBJ_DIR_LIB)
						@$(RM) -f $(IFMAKE_DIR_LIB)
						@echo "$(MAGENTA)libft objects files cleaned!$(DEF_COLOR)"				

fclean:			clean
						@$(RM) -f $(NAME)
						@echo "$(RED)libft executable files cleaned!$(DEF_COLOR)"

re:						fclean all
						@echo "$(GREEN)Cleaned and rebuilt everything for libft!$(DEF_COLOR)"

norm:
						@norminette $(SRC_LIB) $(INCLUDE) | grep -v Norme -B1 || true
						@echo "Norminet the cat says : $(RED)M$(ORANGE)e$(YELLOW)o$(GREEN)w$(CYAN) !$(BLUE)!$(MAGENTA)!$(DEF_COLOR)"

.PHONY: 		all clean fclean re norm
