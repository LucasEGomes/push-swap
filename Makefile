MAKEFLAGS += --no-builtin-rules

NAME := push_swap

TEST_FOLDER := tests
SOURCES_FOLDER := src
OBJECTS_FOLDER := objs

CC := clang
CFLAGS := -Wall -Wextra -Werror -MMD -I $(PWD)/$(SOURCES_FOLDER)

ifeq ($(DEBUG), 1)
	CFLAGS += -g3 -fsanitize=address,leak,undefined -fno-omit-frame-pointer
else
	CFLAGS += -O2
endif

SOURCES := \
	application/start.c \
	entities/doubly_linked_list/destructors.c \
	entities/doubly_linked_list/factories.c \
	entities/doubly_linked_list/handlers.c \
	entities/doubly_linked_list/properties.c \
	entities/push_swap/setter.c \
	helper/is_sorted.c \
	operations/push.c \
	operations/reverse_rotate.c \
	operations/rotate.c \
	operations/swap.c \
	parser/parser.c \
	parser/validators.c \
	sorters/bubble_sort/bubble_sort.c \
	sorters/merge_sort/handlers.c \
	sorters/merge_sort/merge_groups.c \
	sorters/merge_sort/merge_sort.c \
	sorters/merge_sort/utils.c \
	sorters/merge_sort/validators.c \
	push_swap.c
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
