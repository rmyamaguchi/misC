# Environment
BIN_DIR     := /usr/bin
INC_DIR     := ./inc
SRC_DIR     := ./src

# Commands
MKDIR        = mkdir
CP           = cp
RM           = rm

# Paths for searching header and source files
vpath %.c $(SRC_DIR)

# Object Files
SRCS        := $(notdir $(wildcard $(SRC_DIR)/*.c))
OBJS	      := $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))
MAIN_SRC    := main.c
MAIN_OBJ    := $(OBJ_DIR)/main.o

# C/C++ Compiler
CC           = $(BIN_DIR)/x86_64-linux-gnu-gcc
CCC          = $(BIN_DIR)/x86_64-linux-gnu-g++
CXX          = $(BIN_DIR)/x86_64-linux-gnu-g++
AR           = $(BIN_DIR)/x86_64-linux-gnu-ar
RANLIB       = $(BIN_DIR)/x86_64-linux-gnu-ranlib

# C Compiler Flags
CFLAGS 		= -c -Wall -std=c99
CINCFLAGS	= -I$(INC_DIR)
CDEFINES    = 

ifeq ($(CFG),OPTMIZE)
CDEFINES    += -O3
else
CFLAGS		+= -g -O
CDEFINES 	+= -D_DEBUG_
endif

#==============================================================================

.PHONY: all applic shared_obj clean

# Build both application and shared object
all: $(APP) $(SHAREDOBJ)

# Build Application
applic: $(APP)

# Build Shared Object
shared_obj: $(SHAREDOBJ)

# Clean Targets
clean:
	@echo "Cleaning files..."
	@-$(RM) -rfv $(OBJ_DIR)
	@-$(RM) -rfv $(APP)
	@-$(RM) -rfv $(OUT_DIR)/$(SHAREDOBJ)
	@-$(RM) -fv  $(addprefix $(OUT_DIR)/,*.map)

#==============================================================================

$(APP): $(MAIN_OBJ) $(OBJS)
	@echo "Building application $@..."   
	@$(CC) $(MAIN_OBJ) $(OBJS) -Wl,-Map=$(OUT_DIR)/output.map -o $@

$(SHAREDOBJ): $(OBJS)
	@echo "Building Shared Library $@..."
	@$(CC) $(OBJS) -o $@

$(OBJ_DIR)/%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(CINCFLAGS) $(CDEFINES) $< -o $@

$(APP): | $(OUT_DIR)
$(SHAREDOBJ): | $(OUT_DIR)

$(OBJS) $(MAIN_OBJ): | $(OBJ_DIR)

$(OUT_DIR): $(OBJ_DIR)

# EOF #
