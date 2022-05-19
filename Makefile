##
## EPITECH PROJECT, 2022
## DUO STUMPER-7
## File description:
## Makefile
##

SRC	=	src/arg_check.c					\
		src/write_file.c				\
		src/open_file.c

MAIN_SRC	=	src/main.c

TEST_SRC	=	tests/tests.c

MAIN_OBJ	=	$(MAIN_SRC:.c=.o)

TEST_OBJ	=	$(TEST_SRC:.c=.o)

OBJ	=	$(SRC:.c=.o)

NAME	=	cesar

CPPFLAGS	=	-I ./include/

all:	$(NAME)

$(NAME):	$(OBJ) $(MAIN_OBJ)
	gcc -o $(NAME) $(OBJ) $(MAIN_OBJ) $(CPPFLAGS)

tests_run:	$(TEST_OBJ)
	gcc -o unit_tests $(TEST_OBJ) $(SRC) $(CPPFLAGS)\
--coverage -lcriterion
	./unit_tests

clean:
	rm -f $(OBJ) $(MAIN_OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(TEST_OBJ)
	rm -f unit_tests
	rm -f *.gc*

re:	fclean all

.PHONY: all clean fclean re
