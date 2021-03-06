NAME = libpsa.a

CC = cc
AR = ar -rc
RM = rm -f
RANLIB = ranlib
CFLAGS = -I./include -std=gnu11 -W -Wall -pedantic -g3

INCDIR = include
SRCDIR = src

SRC = $(wildcard $(SRCDIR)/*.c)
SRC += $(wildcard $(SRCDIR)/*/*.c)
SRC += $(wildcard $(SRCDIR)/*/*/*.c)
OBJ = $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(AR) $(NAME) $(OBJ)
			$(RANLIB) $(NAME)

re:			fclean all

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

.PHONY: all re clean fclean
