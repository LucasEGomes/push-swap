MAKEFLAGS += --no-builtin-rules

NAME := push_swap

TEST_FOLDER := tests
SOURCES_FOLDER := src
OBJECTS_FOLDER := objs

CC := clang
CFLAGS := -Wall -Wextra -Werror -g3 -MMD -I $(PWD)/$(SOURCES_FOLDER)

SOURCES := \
	application/start.c \
	doubly_linked_list/destructors.c \
	doubly_linked_list/factories.c \
	doubly_linked_list/handlers.c \
	doubly_linked_list/properties.c \
	main.c
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

retests: re
	$(MAKE) -C $(TEST_FOLDER) re

.PHONY: all clean fclean re tests retests
