
NAME = msh

SRC = main.c \
	  	loop.c \
	  	read.c \
	  	tokenize.c \
	  	token_parse.c \
	  	launch.c \
	  	link_executable.c \
	  	execute.c \
	  	data_structures/hashmap.c \
	  	data_structures/doubly_linked_list.c \
	  	data_structures/serialize.c \
	  	util.c \
	  	freedom.c \
	  	env.c


SRCDIR = ./src
OBJDIR = ./obj
INCDIR = ./includes

FTDIR = ./libft
FTLIB = $(addprefix $(FTDIR)/, libft.a)
FTINC = -I $(FTDIR)
FTLNK = -L $(FTDIR) -l ft

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
CC = gcc
FLAGS =	-Wall -Werror -Wextra -g

all: obj $(FTLIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)/data_structures

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(FLAGS) $(FTINC) -I $(INCDIR) -o $@ -c $<

$(FTLIB):
	make -C $(FTDIR)

$(NAME): $(OBJ) $(FTLIB)
	$(CC) $(FLAGS) $(OBJ) $(FTLNK) -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(FTDIR) fclean

re: fclean all

.PHONY: clean, fclean, re
