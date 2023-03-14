MAKEFLAGS += --no-builtin-rules

SOURCES_FOLDER := ../src
CC := clang
CFLAGS := -Wall -Wextra -Werror -g3 -MMD -I ./$(SOURCES_FOLDER) -lcriterion

SOURCE_OBJECTS := $(wildcard ../objs/**/*.o)
TESTS := \
	test_doubly_linked_list.c
TESTS_FOLDER := tests
TESTS_PROGRAMS := $(TESTS:%.c=$(TESTS_FOLDER)/%.out)

all: $(TESTS_PROGRAMS)
	$(foreach TEST_PROGRAM, $^, ./$(TEST_PROGRAM))

$(TESTS_FOLDER)/%.out: %.c Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $< $(SOURCE_OBJECTS) -o $@

clean:
	rm -rf $(TESTS_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
