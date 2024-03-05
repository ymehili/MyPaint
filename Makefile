##
## EPITECH PROJECT, 2023
## my_paint
## File description:
## Makefile
##

CC                := gcc
CFLAGS            := -c -Wall -g3
LIB               := -lcsfml-graphics -lcsfml-system -lcsfml-window -lm
LDFLAGS           := -g3 $(LIB)
TEST_EXE          := unit_tests
EXECUTABLE        := my_paint

SOURCES_FILES     := $(wildcard src/*.c) $(wildcard src/tools/*.c) main.c
OBJECTS_FILES     := $(SOURCES_FILES:.c=.o)
SRC_TO_TEST       := $(wildcard src/*.c) $(wildcard src/tools/*.c)
TEST_FILE         := $(wildcard tests/*.c)

all: $(SOURCES_FILES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS_FILES)
	$(CC) $^ $(LDFLAGS) -o $@
	make clean

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	@rm -f $(OBJECTS_FILES)
	@rm -f unit_tests
	@rm -f *.gcno
	@rm -f *.gcda
	@rm -f tests/*.o

fclean: clean
	@rm -f $(EXECUTABLE)

unit_tests:
	@gcc $(SRC_TO_TEST) $(TEST_FILE) -lcriterion $(LIB) \
		--coverage -o $(TEST_EXE)

tests_run: unit_tests
	./$(TEST_EXE)

re: fclean all

.PHONY: all clean fclean unit_tests tests_run re