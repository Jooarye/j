BINARY = main
SOURCE_DIR = src
OBJECT_DIR = bin
GRAMMAR_DIR = grammar
INCLUDE_DIR = include

CC = g++
BISON = bison
FLEX = flex
CFLAGS = -I$(INCLUDE_DIR)/ -std=c++20 -g

SOURCE_FILES = $(shell find $(SOURCE_DIR)/ -name *.cpp)
OBJECT_FILES = $(patsubst $(SOURCE_DIR)/%.cpp, $(OBJECT_DIR)/%.o, $(SOURCE_FILES))

all: $(OBJECT_FILES) parser scanner
	$(CC) $(CFLAGS) -o $(OBJECT_DIR)/$(BINARY) $(OBJECT_FILES)

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

$(SOURCE_DIR)/%.cpp: %.lpp
	$(FLEX) -o$@ $<

.PHONY: parser
parser:
	$(BISON) -o $(SOURCE_DIR)/parser.cpp --header=$(INCLUDE_DIR)/parser.hpp $(GRAMMAR_DIR)/parser.ypp

.PHONY: scanner
scanner:
	$(FLEX) -o $(SOURCE_DIR)/scanner.cpp $(GRAMMAR_DIR)/scanner.lpp

clean:
	rm -rf $(OBJECT_DIR)/*
