#
# **************************************************************
# *                Simple C++ Makefile Template                *
# *                                                            *
# * Author: Arash Partow (2003)                                *
# * URL: http://www.partow.net/programming/makefile/index.html *
# *                                                            *
# * Copyright notice:                                          *
# * Free use of this C++ Makefile template is permitted under  *
# * the guidelines and in accordance with the the MIT License  *
# * http://www.opensource.org/licenses/MIT                     *
# *                                                            *
# **************************************************************
#

CXX      := gcc
CXXFLAGS := -pedantic-errors -Wall -Wextra -Werror
LDFLAGS  :=  -L/usr/lib -lstdc++ -lm -lpthread -fPIC
BUILD    := ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)/apps
TARGET   := program
INCLUDE  := -Iinclude/
SRC      :=                      \
   $(wildcard src/model/Entity/*.cpp) \
   $(wildcard src/model/Alien/*.cpp) \
   $(wildcard src/model/Bullet/*.cpp) \
   $(wildcard src/model/Board/*.cpp) \
   $(wildcard src/model/Bullet/*.cpp) \
   $(wildcard src/model/Player/*.cpp) \
   $(wildcard src/model/Game/*.cpp) \
   $(wildcard src/*.cpp) \



ASSEMBLY_OBJECTS := 			\
	$(wildcard src/assembly/*.o)\

OBJECTS  := $(SRC:%.cpp=$(OBJ_DIR)/%.o)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	nasm -f elf64 src/assembly/endgame.asm
	nasm -f elf64 src/assembly/menu.asm
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c  $< -o $@ $(LDFLAGS)

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS) $(ASSEMBLY_OBJECTS)

.PHONY: all build clean debug release

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)

debug: CXXFLAGS += -DDEBUG -g
debug: all

release: CXXFLAGS += -O2
release: all

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*
