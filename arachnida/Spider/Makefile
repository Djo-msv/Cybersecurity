NAME	:= Spider
MAKEFLAGS += --no-print-directory

#==============================COMPIL===========================#

CC = g++
CFLAGS = 
VALUE =
ifeq ($(DEBUG), 1)
	CFLAGS += -g
	VALUE += -D DEBUG=1
endif

#==============================COLORS==============================#
NOC			= \e[0m
BOLD		= \e[1m
DIM			= \e[2m
UNDERLINE	= \e[4m
BLACK		= \e[1;30m
RED			= \e[1m\e[38;5;196m
GREEN		= \e[1m\e[38;5;76m
YELLOW		= \e[1m\e[38;5;220m
BLUE		= \e[1m\e[38;5;33m
PURPLE		= \e[1;35m
CYAN		= \e[1;36m
WHITE		= \e[1;37m
SPECIAL		= \e[1m\e[38;5;223m

BLACK_BG 	= \033[0;40m
RED_BG 		= \033[0;41m
GREEN_BG 	= \033[0;42m
YELLOW_BG 	= \033[0;43m
BLUE_BG 	= \033[0;44m
MAGENTA_BG 	= \033[0;45m
CYAN_BG 	= \033[0;46m
WHITE_BG 	= \033[0;47m
RESET_BG	= \033[0m

#================================DIRS============================#

SRC_DIR		:=	srcs
HEADER_DIR	:=	includes
BUILD_DIR	:=	.build

#==============================SOURCES===========================#

SRCS_FILES	:=	main.cpp \
				parserSetting.cpp \
				readWebPages.cpp

SRCS	:=		$(addprefix $(SRC_DIR)/, $(SRCS_FILES))

#=============================OBJECTS===========================#

OBJS:=			${SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o}

#===============================DEPS=============================#

DEPS:=			${SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.d}

#=============================INCLUDES===========================#

INC:=			-I$(HEADER_DIR) -I$(HOME)/.local/include -L$(HOME)/.local/lib -lcurl -Wl,-rpath,$(HOME)/.local/lib

#================================DIR=============================#

DIRS			:=	$(sort $(shell dirname $(OBJS)))

#===============================RULES============================#

all: $(NAME)

$(DIRS):
	@mkdir -p $@

$(NAME):  $(OBJS)
	@echo "\n$(GREEN)Create binaries$(NOC)"
	$(CC) $(CFLAGS) $(OBJS) $(INC) -o $@
	@echo "$(RED)"
	@echo "              ( ";
	@echo "               ) ";
	@echo "              ( ";
	@echo "        /\\  .-\"\"\"-.  /\\ ";
	@echo "       //\\\\\\/  ,,,  \\//\\\\\\ ";
	@echo "       |/\\| ,;;;;;, |/\\| ";
	@echo "       //\\\\\\\\\\;-\"\"\"-;///\\\\\\ ";
	@echo "      //  \\/   .   \\/  \\\\\\ ";
	@echo "     (| ,-_| \\ | / |_-, |) ";
	@echo "       //\`__\\.-.-./__\`\\\\\\ ";
	@echo "      // /.-(() ())-.\\ \\\\\\ ";
	@echo "     (\\ |)   '---'   (| /) ";
	@echo "      \` (|           |) \` ";
	@echo "        \\)           (/ ";
	@echo "$(NOC)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(DIRS)
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(CFLAGS) $(VALUE) $(INC) $(LIB) -MMD -MP -c $< -o $@

clean:
	@echo "$(RED)Remove objects$(NOC)"
	@rm -rf $(BUILD_DIR)

fclean: clean
	@echo "$(RED)Remove binary$(NOC)"
	@rm -f $(NAME)
	@rm -f $(BONUS_NAME)

re: fclean
	@make

.PHONY: all clean fclean re

-include $(DEPS)
