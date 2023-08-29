NAME = trim-x86

RESOURCES = ./resources
SRCS = $(RESOURCES)/srcs
BUILDS = $(RESOURCES)/builds
HEADER = $(RESOURCES)/includes
HEADER := $(addprefix -I, $(HEADER))

FILES = $(wildcard $(SRCS)/*.cpp)
OBJS = $(patsubst $(SRCS)/%.cpp,$(BUILDS)/%.o,$(FILES))
DEP = $(OBJS:.o=.d)

CC = g++
DEL = rm -rf
MKDIR = mkdir -p

CFLAGS = -Wall -Werror -Wextra -g3
DEPFLAGS = -MMD -MF

DEL_MSG = @printf "[-][\e[0;31m DEL \e[0m] "
BIN_MSG = @printf "[*][\e[0;32m BIN \e[0m] $(NAME)\n"
BLD_MSG = @printf "[+][\e[0;34m BLD \e[0m] "
MKD_MSG = @printf "[+][\e[0;35m MKD \e[0m] "

all: $(NAME) trimui

$(NAME): $(BUILDS) $(OBJS)
	$(BIN_MSG)
	@$(CC) $(CFLAGS) $(OBJS) $(HEADER) -o $@ -lcurl

trimui:
	$(BIN_MSG)
	@make -s -C $(RESOURCES)

clean:
	$(DEL_MSG)
	$(DEL) $(BUILDS)
	@make clean -s -C $(RESOURCES)

fclean: clean
	$(DEL_MSG)
	$(DEL) ./$(NAME)
	@make fclean -s -C $(RESOURCES)

re: fclean all

run: $(NAME)
	clear

$(BUILDS):
	$(MKD_MSG)
	@$(MKDIR) $@

$(BUILDS)/%.o: $(SRCS)/%.cpp | $(BUILDS)
	$(BLD_MSG)
	@printf "Building ... %s\n" $@
	@$(CC) $(CFLAGS) $(HEADER) -c $< -o $@ $(DEPFLAGS) $(@:.o=.d)

.PHONY: all clean fclean re run trimui

-include $(DEP)

