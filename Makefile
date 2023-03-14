MAKEFLAGS += --no-builtin-rules

NAME := push_swap

CC := clang
CFLAGS := -Wall -Wextra -Werror -g3 -MMD -I ./

TEST_FOLDER := tests
SOURCES_FOLDER := src
SOURCES := \
	doubly_linked_list/doubly_linked_list.c \
	main.c
OBJECTS_FOLDER := objs
OBJECTS := $(SOURCES:%.c=objs/%.o)
DEPENDS := $(OBJECTS:%.o=%.d)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

-include $(DEPENDS)

$(OBJECTS_FOLDER)/%.o: $(SOURCES_FOLDER)/%.c Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all

tests: all
	$(MAKE) -C $(TEST_FOLDER)

.PHONY: all clean fclean re tests
