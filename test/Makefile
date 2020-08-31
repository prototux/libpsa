NAME = test

CC = cc
RM = rm -f
CFLAGS = -L$(LIBDIR) -I$(INCDIR) -l psa -std=gnu99 -W -Wall -pedantic

LIBDIR = ../
INCDIR = ../include

SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) -o $(NAME) $(OBJ) -L$(LIBDIR) -lpsa

re:			fclean all

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

.PHONY: all re clean fclean
