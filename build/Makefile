# Environment
BIN_DIR     := /usr/bin
MAININC_DIR := ./include
MAINSRC_DIR := ./src

SRC_DIR		:= $(APP_DIR)/src
INC_DIR		:= $(APP_DIR)/include

# Commands
MKDIR        = mkdir
CP           = cp
RM           = rm

# Paths for searching header and source files
vpath %.c $(MAINSRC_DIR):$(SRC_DIR)

# Object Files
SRCS        := $(notdir $(wildcard $(SRC_DIR)/*.c))
OBJS	    := $(addprefix $(OBJ_DIR)/,$(SRCS:.c=.o))

MAIN_OBJ	:= $(OBJ_DIR)/$(APPNAME).o

# C/C++ Compiler
CC           = $(BIN_DIR)/gcc
CCC          = $(BIN_DIR)/g++
CXX          = $(BIN_DIR)/g++
AR           = $(BIN_DIR)/ar
RANLIB       = $(BIN_DIR)/ranlib

# C Compiler Flags
CFLAGS 		= -c -Wall -std=c99
CINCFLAGS	= -I$(MAININC_DIR) -I$(INC_DIR)
CDEFINES    = 

ifeq ($(CFG),OPTMIZE)
CDEFINES    += -O3
else
CFLAGS		+= -g -O -fPIC
CDEFINES 	+= -D_DEBUG_
endif

#LIBOBJECTS  := -lm

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
#   @$(CC) $(MAIN_OBJ) $(OBJS) -Wl,-Map=$(OUT_DIR)/output.map -o $@
	@$(CC) $(MAIN_OBJ) $(OBJS) $(LIBOBJECTS) -o $@

$(SHAREDOBJ): $(OBJS)
	@echo "Building Shared Library $@..."
	@$(CC) -shared -o $@ $(OBJS)

$(OBJ_DIR)/%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(CINCFLAGS) $(CDEFINES) $< -o $@

$(APP): | $(OUT_DIR)
$(SHAREDOBJ): | $(OUT_DIR)

$(MAIN_OBJ) $(OBJS): | $(OBJ_DIR)

$(OBJ_DIR): | $(OUT_DIR)
	@$(MKDIR) $@

$(OUT_DIR):
	@$(MKDIR) $@

# EOF #
