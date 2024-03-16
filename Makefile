# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roglopes <roglopes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/03 14:14:55 by roglopes          #+#    #+#              #
#    Updated: 2024/03/15 19:10:03 by roglopes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap

SOURCES_DIR			= sources/
OBJECTS_DIR			= objects/
HEADERS				= -I ./includes/mandatory/ -I ./libft/include/
OPERATIONS_DIR		= $(SOURCES_DIR)mandatory/operations/
PUSH_SWAP_DIR		= $(SOURCES_DIR)mandatory/push_swap/
LIBFT				= ./libft/library/libft.a

CFLAGS				= -Wextra -Wall -Werror -g3
CC					= cc

VALGRIND_LOG		= valgrind.log

OPERATIONS_SOURCES	= $(OPERATIONS_DIR)push.c          \
					$(OPERATIONS_DIR)rev_rotate.c      \
					$(OPERATIONS_DIR)rotate.c          \
					$(OPERATIONS_DIR)sort_stacks.c     \
					$(OPERATIONS_DIR)sort_three_five.c \
					$(OPERATIONS_DIR)swap.c

PUSH_SWAP_SOURCES	= $(PUSH_SWAP_DIR)handle_errors.c \
					$(PUSH_SWAP_DIR)init_a_and_b.c    \
					$(PUSH_SWAP_DIR)main.c            \
					$(PUSH_SWAP_DIR)split.c           \
					$(PUSH_SWAP_DIR)stack_init.c      \
					$(PUSH_SWAP_DIR)stack_utils.c

SOURCES				= $(OPERATIONS_SOURCES) $(PUSH_SWAP_SOURCES)

OBJS				= $(patsubst $(SOURCES_DIR)%.c,$(OBJECTS_DIR)%.o, $(SOURCES))

LEAK				= "21 3 54 68 10 100 553 43 01 4903 0 123"
COUNT				:= 0
RED					= \033[0;31m
GREEN				= \033[0;32m
MAGENTA				= \033[0;35m
RESET				= \033[0m
CYAN				= \033[36;1;3;208m
YELLOW				= \033[0;33m
COLOR_LIMITER		= "\033[0m"

all: create_objects_dir libft $(OBJECTS_DIR) $(NAME)

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c
	@mkdir -p $(@D)
	@$(eval COUNT=$(shell expr $(COUNT) + 1))
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)
	@printf "$(GREEN)Compiling Push Swap %d%%\r$(RESET)" $$(echo $$(($(COUNT) * 100 / $(words $(SOURCES_DIR)))))

$(NAME): $(OBJS) 
	@$(CC) $(CFLAGS) $(OBJS) $(HEADERS) $(LIBFT) -o $(NAME)

create_objects_dir:
	@mkdir -p $(OBJECTS_DIR)

libft:
	@make -C ./libft --no-print-directory

clean:
	@make clean -C ./libft --no-print-directory
	@rm -rf $(OBJECTS_DIR)
	@rm -rf $(VALGRIND_LOG)
	@printf "$(RED)Deleted objects Push Swap$(RESET)\n"

fclean: clean
	@echo "Cleaning all... 🧹"
	@rm -rf $(NAME)
	@make fclean -C ./libft --no-print-directory
	@printf "$(RED)Project is deleted Push Swap$(RESET)\n"
	@printf "$(RED)File valgrind.log deleted$(RESET)\n"
	@echo "✨ Cleaning complete! ✨"

norm:
	@norminette -R CheckForbiddenSource
	@echo "$(CYAN)NORMINETTE OK $(RESET)"

valgrind: all
	@valgrind --leak-check=full \
	--show-reachable=yes \
	--show-leak-kinds=all -s \
	--track-origins=yes \
	--log-file=$(VALGRIND_LOG) \
	./$(NAME) $(LEAK)
	@cat $(VALGRIND_LOG)

tester_roger:
	@./tester_roger-42sp/./push_swap_tester.sh 10 5

re: fclean all
	@echo "$(BLUE) $(NAME) Cleaned and rebuilt everything!"

.PHONY: all clean fclean re libft bonus norm create_objects_dir valgrind tester_roger