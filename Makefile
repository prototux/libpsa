NAME = libpsa.a

CC = cc
AR = ar -rc
RM = rm -f
RANLIB = ranlib
CFLAGS = -std=gnu99 -W -Wall -pedantic

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
