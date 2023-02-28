NAME        := mandatory/so_long
B_NAME        := bonus/so_long
CC        := gcc
FLAGS    := -Wall -Wextra -Werror -Imlx -lmlx -framework OpenGL -framework AppKit


################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=      mandatory/_ft_printf/ft_itoa.c \
                          mandatory/_ft_printf/ft_print_ad.c \
                          mandatory/_ft_printf/ft_print_hex.c \
                          mandatory/_ft_printf/ft_print_unsigned.c \
                          mandatory/_ft_printf/ft_printf.c \
                          mandatory/_ft_printf/ft_printf_utils.c \
                          mandatory/_get_next_line/get_next_line.c \
                          mandatory/_get_next_line/get_next_line_utils.c \
                          mandatory/_libft/ft_atoi.c \
                          mandatory/_libft/ft_bzero.c \
                          mandatory/_libft/ft_calloc.c \
                          mandatory/_libft/ft_isalnum.c \
                          mandatory/_libft/ft_isalpha.c \
                          mandatory/_libft/ft_isascii.c \
                          mandatory/_libft/ft_isdigit.c \
                          mandatory/_libft/ft_isprint.c \
                          mandatory/_libft/ft_lstadd_back_bonus.c \
                          mandatory/_libft/ft_lstadd_front_bonus.c \
                          mandatory/_libft/ft_lstclear_bonus.c \
                          mandatory/_libft/ft_lstdelone_bonus.c \
                          mandatory/_libft/ft_lstiter_bonus.c \
                          mandatory/_libft/ft_lstlast_bonus.c \
                          mandatory/_libft/ft_lstmap_bonus.c \
                          mandatory/_libft/ft_lstnew_bonus.c \
                          mandatory/_libft/ft_lstsize_bonus.c \
                          mandatory/_libft/ft_memchr.c \
                          mandatory/_libft/ft_memcmp.c \
                          mandatory/_libft/ft_memcpy.c \
                          mandatory/_libft/ft_memmove.c \
                          mandatory/_libft/ft_memset.c \
                          mandatory/_libft/ft_putchar_fd.c \
                          mandatory/_libft/ft_putendl_fd.c \
                          mandatory/_libft/ft_putnbr_fd.c \
                          mandatory/_libft/ft_putstr_fd.c \
                          mandatory/_libft/ft_split.c \
                          mandatory/_libft/ft_strchr.c \
                          mandatory/_libft/ft_strdup.c \
                          mandatory/_libft/ft_striteri.c \
                          mandatory/_libft/ft_strjoin.c \
                          mandatory/_libft/ft_strlcat.c \
                          mandatory/_libft/ft_strlcpy.c \
                          mandatory/_libft/ft_strlen.c \
                          mandatory/_libft/ft_strmapi.c \
                          mandatory/_libft/ft_strncmp.c \
                          mandatory/_libft/ft_strnstr.c \
                          mandatory/_libft/ft_strrchr.c \
                          mandatory/_libft/ft_strtrim.c \
                          mandatory/_libft/ft_substr.c \
                          mandatory/_libft/ft_tolower.c \
                          mandatory/_libft/ft_toupper.c \
                          mandatory/so_long.c \
                          mandatory/utils/mlx_moves.c \
                          mandatory/utils/mlx_utils.c \
                          mandatory/utils/sub_mlx_utils.c \
                          mandatory/utils/sub_utils.c \
                          mandatory/utils/utils.c \
     
B_SRCS        :=      bonus/_ft_printf/ft_itoa.c \
                         bonus/_ft_printf/ft_print_ad.c \
                         bonus/_ft_printf/ft_print_hex.c \
                         bonus/_ft_printf/ft_print_unsigned.c \
                         bonus/_ft_printf/ft_printf.c \
                         bonus/_ft_printf/ft_printf_utils.c \
                         bonus/_get_next_line/get_next_line.c \
                         bonus/_get_next_line/get_next_line_utils.c \
                         bonus/_libft/ft_atoi.c \
                         bonus/_libft/ft_bzero.c \
                         bonus/_libft/ft_calloc.c \
                         bonus/_libft/ft_isalnum.c \
                         bonus/_libft/ft_isalpha.c \
                         bonus/_libft/ft_isascii.c \
                         bonus/_libft/ft_isdigit.c \
                         bonus/_libft/ft_isprint.c \
                         bonus/_libft/ft_lstadd_back_bonus.c \
                         bonus/_libft/ft_lstadd_front_bonus.c \
                         bonus/_libft/ft_lstclear_bonus.c \
                         bonus/_libft/ft_lstdelone_bonus.c \
                         bonus/_libft/ft_lstiter_bonus.c \
                         bonus/_libft/ft_lstlast_bonus.c \
                         bonus/_libft/ft_lstmap_bonus.c \
                         bonus/_libft/ft_lstnew_bonus.c \
                         bonus/_libft/ft_lstsize_bonus.c \
                         bonus/_libft/ft_memchr.c \
                         bonus/_libft/ft_memcmp.c \
                         bonus/_libft/ft_memcpy.c \
                         bonus/_libft/ft_memmove.c \
                         bonus/_libft/ft_memset.c \
                         bonus/_libft/ft_putchar_fd.c \
                         bonus/_libft/ft_putendl_fd.c \
                         bonus/_libft/ft_putnbr_fd.c \
                         bonus/_libft/ft_putstr_fd.c \
                         bonus/_libft/ft_split.c \
                         bonus/_libft/ft_strchr.c \
                         bonus/_libft/ft_strdup.c \
                         bonus/_libft/ft_striteri.c \
                         bonus/_libft/ft_strjoin.c \
                         bonus/_libft/ft_strlcat.c \
                         bonus/_libft/ft_strlcpy.c \
                         bonus/_libft/ft_strlen.c \
                         bonus/_libft/ft_strmapi.c \
                         bonus/_libft/ft_strncmp.c \
                         bonus/_libft/ft_strnstr.c \
                         bonus/_libft/ft_strrchr.c \
                         bonus/_libft/ft_strtrim.c \
                         bonus/_libft/ft_substr.c \
                         bonus/_libft/ft_tolower.c \
                         bonus/_libft/ft_toupper.c \
                         bonus/so_long.c \
                         bonus/utils/mlx_moves.c \
                         bonus/utils/mlx_utils.c \
                         bonus/utils/sub_mlx_utils.c \
                         bonus/utils/sub_utils.c \
                         bonus/utils/utils.c \
                         bonus/utils/mlx_animation.c \
						 bonus/utils/mlx_enemy_animation.c\
                         bonus/utils/sub_mlx_enemy_animation.c\

O_SRCS = $(SRCS:.c=.o)
BO_SRCS = $(B_SRCS:.c=.o)
#
.SILENT:
all : $(NAME)

$(NAME) : $(O_SRCS)
	$(CC) $(FLAGS) $(O_SRCS) -o $(NAME)

bonus :  $(B_NAME)

$(B_NAME) : $(BO_SRCS)
	$(CC) $(FLAGS) $(BO_SRCS) -o $(B_NAME)
clean :
	rm -rf $(O_SRCS) $(BO_SRCS)
fclean : clean
	rm -rf $(NAME) $(B_NAME)
