MAKEFLAGS += --no-builtin-rules

NAME := push_swap

CC := clang
CFLAGS := -Wall -Wextra -Werror -g3 -MMD -I ./

SOURCES := \
	main.c
OBJECTS_FOLDER := objs
OBJECTS := $(SOURCES:%.c=objs/%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJECTS_FOLDER)/%.o: %.c Makefile
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJECTS_FOLDER)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
