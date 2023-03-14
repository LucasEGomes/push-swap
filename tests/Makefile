MAKEFLAGS += --no-builtin-rules

NAME := test_push_swap.out
PROJECT_ROOT := ..
PROJECT_SOURCE_FOLDER := $(PROJECT_ROOT)/src
PROJECT_OBJECTS_FOLDER := $(PROJECT_ROOT)/objs

CC := clang
CFLAGS := -Wall -Wextra -Werror -g3 -MMD -I $(PROJECT_SOURCE_FOLDER)

SOURCES := \
	test_doubly_linked_list.c
OBJECTS_FOLDER := objs
OBJECTS := $(SOURCES:%.c=$(OBJECTS_FOLDER)/%.o)
DEPENDS := $(OBJECTS:%.o=%.d)
PROJECT_OBJECTS_LIB := $(OBJECTS_FOLDER)/libpush_swap.a

all: $(NAME)
	./$<  --always-succeed --json

$(NAME): $(OBJECTS) $(PROJECT_OBJECTS_LIB)
	$(CC) $(CFLAGS) $^ -o $@ -lcriterion

$(PROJECT_OBJECTS_LIB):
	mkdir -p $(dir $@)
	ar -rcs $@ $(wildcard $(PROJECT_OBJECTS_FOLDER)/**/*.o)

$(OBJECTS_FOLDER)/%.o: %.c Makefile $(PROJECT_OBJECTS_LIB)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
