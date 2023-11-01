NAME = philo

SRC_DIR := .

SRCS = \
	main.c\
	utils.c\
	philo.c\
	routine.c\
	management.c

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

BUILD_DIR := .build

CC := gcc
CFLAG := -Wall -Wextra -Werror -g3 -fsanitize=thread
PTHREAD := -pthread

LOCKS = locks
LOCKS_DIR = ./locks
LOCKS_RULE = $(LOCKS_DIR)/lib$(LOCKS).a
LOCKS_L = -L $(LOCKS_DIR)
LOCKS_H = -I $(LOCKS_DIR)
LOCKS_A = -l $(LOCKS)

INCLUDES = $(LOCKS_H)
LIBS_DIR = $(LOCKS_L)
LIBS = $(PTHREAD) $(LOCKS_A)

RM := rm -rf
MAKEFLAG += --no-print-directory
DIR_DUP = mkdir -p $(@D)

all: $(NAME)

$(NAME): $(LOCKS_RULE) $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) -o $(NAME) $(INCLUDES) $(LIBS_DIR) $(LIBS)
	$(info CREATED $(NAME))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CCFLAGS) -c $< -o $@
	$(info CREATED $@)

$(LOCKS_RULE):
	echo make $(LOCKS_RULE)
	@$(MAKE) -C $(LOCKS_DIR)
	$(info CREATED $@)

clean:
	@$(MAKE) -C $(LOCKS_DIR) clean
	$(RM) $(BUILD_DIR)


fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LOCKS_DIR) fclean

re:
	$(MAKE) fclean
	$(MAKE) all