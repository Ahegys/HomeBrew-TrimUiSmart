NAME = trim
FILES = homebrew.cpp
OBJS = $(addprefix $(BUILDS)/, $(FILES:.cpp=.o))
DEP = $(OBJS:.o=.d)
SRCS = ./srcs
VPATH = 
VPATH := $(SRCS) $(addprefix $(SRCS)/, $(VPATH))
HEADER = ./inc
HEADER := $(addprefix -I, $(HEADER))
BUILDS = ./builds
CC = arm-linux-gnueabihf-g++-10
CFLAGS = -Wall -Werror -Wextra -g
DEPFLAGS = -MMD -MF
DEL = rm -rf
MKDIR = mkdir -p

DEL_MSG = @printf "[-][\e[0;31m DEL \e[0m] "
BIN_MSG = @printf "[*][\e[0;32m BIN \e[0m] $(NAME)\n"
BLD_MSG = @printf "[+][\e[0;34m BLD \e[0m] "
MKD_MSG = @printf "[+][\e[0;35m MKD \e[0m] "

all: $(NAME)

$(NAME): $(BUILDS) $(OBJS)
	$(BIN_MSG)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADER) -o $@

clean:
	$(DEL_MSG)
	$(DEL) $(BUILDS)

fclean: clean
	$(DEL_MSG)
	$(DEL) ./$(NAME)

re: fclean all

run: all
	clear
	@qemu-arm -L /usr/arm-linux-gnueabihf/ ./$(NAME) $(ARGS)

$(BUILDS):
	$(MKD_MSG)
	@$(MKDIR) $@

$(BUILDS)/%.o: %.cpp
	$(BLD_MSG)
	@printf "Building ... %s\n" $@
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@ $(DEPFLAGS) $(@:.o=.d)

.PHONY: all clean fclean re

-include $(DEP)

