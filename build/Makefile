# Environment
BIN_DIR     := /usr/bin
INC_DIR     := ./inc
SRC_DIR     := ./src

BMP_DIR     := ./libBMP
BMPSRC_DIR	:= $(BMP_DIR)/src
BMPINC_DIR	:= $(BMP_DIR)/inc

CLA_DIR		:= ./libClass
CLASRC_DIR	:= $(CLA_DIR)/src
CLAINC_DIR	:= $(CLA_DIR)/inc

# Commands
MKDIR        = mkdir
CP           = cp
RM           = rm

# Paths for searching header and source files
vpath %.c $(SRC_DIR):$(BMPSRC_DIR):$(CLASRC_DIR)

# Object Files
SRCS        := $(notdir $(wildcard $(SRC_DIR)/*.c))
OBJS	    := $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

BMP_SRCS	:= $(notdir $(wildcard $(BMPSRC_DIR)/*.c))
BMP_OBJS    := $(addprefix $(OBJ_DIR)/,$(BMP_SRCS:.c=.o))

CLA_SRCS	:= $(notdir $(wildcard $(CLASRC_DIR)/*.c))
CLA_OBJS    := $(addprefix $(OBJ_DIR)/,$(CLA_SRCS:.c=.o))

# C/C++ Compiler
CC           = $(BIN_DIR)/x86_64-linux-gnu-gcc
CCC          = $(BIN_DIR)/x86_64-linux-gnu-g++
CXX          = $(BIN_DIR)/x86_64-linux-gnu-g++
AR           = $(BIN_DIR)/x86_64-linux-gnu-ar
RANLIB       = $(BIN_DIR)/x86_64-linux-gnu-ranlib

# C Compiler Flags
CFLAGS 		= -c -Wall -std=c99
CINCFLAGS	= -I$(INC_DIR) -I$(BMPINC_DIR) -I$(CLAINC_DIR)
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

$(APP): $(OBJS) $(BMP_OBJS) $(CLA_OBJS)
	@echo "Building application $@..."   
	@$(CC) $(OBJS) $(BMP_OBJS) $(CLA_OBJS) -Wl,-Map=$(OUT_DIR)/output.map -o $@

$(SHAREDOBJ): $(BMP_OBJS) $(CLA_OBJS)
	@echo "Building Shared Library $@..."
	@$(CC) $(OBJS) -o $@

$(OBJ_DIR)/%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(CINCFLAGS) $(CDEFINES) $< -o $@

$(APP): | $(OUT_DIR)
$(SHAREDOBJ): | $(OUT_DIR)

$(OBJS)  $(BMP_OBJS) $(CLA_OBJS): | $(OBJ_DIR)

$(OUT_DIR): $(OBJ_DIR)

# EOF #
