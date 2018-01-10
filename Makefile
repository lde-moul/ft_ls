# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lde-moul <lde-moul@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 16:24:36 by lde-moul          #+#    #+#              #
#    Updated: 2018/01/10 16:47:47 by lde-moul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = ft_ls

CC = clang
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src
OBJDIR = obj

SRCBASE = main.c\
		  entry.c\
		  dir.c\
		  sort.c\
		  parse.c\
		  error.c\
		  util.c\

DEP = src/ft_ls.h

SRC = $(SRCBASE:%=$(SRCDIR)/%)
OBJ = $(SRCBASE:%.c=$(OBJDIR)/%.o)

LIBFT_DIR = libft
LIBFT_NAME = $(LIBFT_DIR)/libft.a
LIBFT_INC = $(LIBFT_DIR)/includes


all: $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@/bin/rm -f $(NAME)

re: fclean all

$(NAME): $(LIBFT_NAME) $(OBJDIR) $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT_NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(DEP)
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(LIBFT_INC)

$(OBJDIR):
	@/bin/mkdir $(OBJDIR)

$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

.PHONY: all clean fclean re
