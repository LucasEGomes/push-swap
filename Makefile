MAKEFLAGS += --no-builtin-rules
ifndef VERBOSE
	MAKEFLAGS += -s
endif

NAME := push_swap
BONUS_NAME := checker

TEST_FOLDER := tests
SOURCES_FOLDER := src
OBJECTS_FOLDER := objs

CC := clang
CFLAGS := -Wall -Wextra -Werror -MMD -I $(PWD)/$(SOURCES_FOLDER)

ifdef DEBUG
	CFLAGS += -g3 -fsanitize=address,leak,undefined -fno-omit-frame-pointer
else
	CFLAGS += -O2
endif

SOURCES := \
	application/run.c \
	application/optimize_sort_steps.c \
	entities/doubly_linked_list/destructors.c \
	entities/doubly_linked_list/factories.c \
	entities/doubly_linked_list/handlers.c \
	entities/doubly_linked_list/properties.c \
	entities/push_swap/setter.c \
	entities/sorter_parameters/setter.c \
	helper/find_element.c \
	helper/get_distance.c \
	helper/has_duplications.c \
	helper/insert_range_b_into_a.c \
	helper/insert_top_b_into_a.c \
	helper/is_sorted.c \
	helper/move_stack_a_to_value.c \
	helper/split_stack_a.c \
	operations/push.c \
	operations/reverse_rotate.c \
	operations/rotate.c \
	operations/swap.c \
	parser/error_handler.c \
	parser/parse_numbers.c \
	parser/parser.c \
	parser/validators.c \
	sorters/bubble_sort/bubble_sort.c \
	sorters/few_elements_sort/few_elements_sort.c \
	sorters/few_elements_sort/sort_2_elements.c \
	sorters/few_elements_sort/sort_3_elements.c \
	sorters/few_elements_sort/sort_4_elements.c \
	sorters/few_elements_sort/sort_5_elements.c \
	sorters/few_elements_sort/sort_6_elements.c \
	sorters/few_elements_sort/sort_7_elements.c \
	sorters/few_elements_sort/sort_8_elements.c \
	sorters/few_elements_sort/sort_patterns_of_3.c \
	sorters/merge_sort/merge_groups.c \
	sorters/merge_sort/merge_sort.c \
	sorters/merge_sort/utils.c \
	sorters/merge_sort/validators.c \
	push_swap.c
OBJECTS := $(SOURCES:%.c=objs/%.o)

BONUS_SOURCES := \
	entities/doubly_linked_list/destructors.c \
	entities/doubly_linked_list/factories.c \
	entities/doubly_linked_list/handlers.c \
	entities/doubly_linked_list/properties.c \
	entities/push_swap/setter.c \
	helper/has_duplications.c \
	helper/is_sorted.c \
	operations/push.c \
	operations/reverse_rotate.c \
	operations/rotate.c \
	operations/swap.c \
	parser/error_handler.c \
	parser/parse_numbers.c \
	parser/parser.c \
	parser/validators.c \
	sorters/bubble_sort/bubble_sort.c \
	bonus/application/application_bonus.c \
	bonus/operations/error.c \
	bonus/operations/skip.c \
	bonus/reader/reader_bonus.c \
	bonus/checker_bonus.c
BONUS_OBJECTS := $(BONUS_SOURCES:%.c=objs/%.o)
DEPENDS := $(OBJECTS:%.o=%.d) $(BONUS_OBJECTS:%.o=%.d)

all: $(NAME)

bonus: | $(NAME) $(BONUS_NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(BONUS_NAME): $(BONUS_OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

-include $(DEPENDS)

$(OBJECTS_FOLDER)/%.o: $(SOURCES_FOLDER)/%.c Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS_FOLDER)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

rebonus: re bonus

tests: all
	$(MAKE) -C $(TEST_FOLDER)

retests: re
	$(MAKE) -C $(TEST_FOLDER) re

.PHONY: all clean fclean re tests retests
