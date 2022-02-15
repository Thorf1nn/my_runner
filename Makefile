##
## EPITECH PROJECT, 2021
## bs_initcsfml
## File description:
## makefile
##

CC 		= gcc

CFLAGS 	= -W -Wall -Wextra -I./include

LDFLAGS = -L/usr/local/lib -lcsfml-window \
				  -lcsfml-graphics -lcsfml-system -lcsfml-audio

SRC 	= $(wildcard ./src/*.c)

OBJ		= $(SRC:.c=.o)

TARGET 	= my_runner

all 		: 	$(TARGET)

$(TARGET) 	: 	$(OBJ)
			$(CC) -o $@ $^ $(LDFLAGS)

clean		:
			$(RM) $(OBJ)

fclean		: clean
			$(RM) $(TARGET)

re			: fclean all
