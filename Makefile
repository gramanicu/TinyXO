# Copyright 2020 Grama Nicolae

.PHONY: gitignore clean memory beauty run
.SILENT: beauty clean memory gitignore

# Compilation variables
CC = g++
CFLAGS = -Wno-unused-parameter -Wall -Wextra -pedantic -g -O3 -std=c++14
EXE = bin/cppX0
SRC = $(wildcard */*.cpp)
OBJ = $(SRC:.cpp=.o)

# Compiles the program
build: $(OBJ)
	-@rm -f bin/* ||:
	-@mv */*.o bin/ ||:
	$(info Compiling code...)
	@$(CC) -o $(EXE) bin/*.o $(CFLAGS) ||:
	$(info Compilation successfull)
	-@rm -f *.o ||:
	@$(MAKE) -s gitignore ||:

%.o: %.cpp
	@$(CC) -o $@ -c $< $(CFLAGS) ||:

# Executes the binary
run: clean build
	./$(EXE)

# Deletes the binary and object files
clean:
	rm -f $(EXE) ./bin/*
	echo "Deleted the binary and object files"

# Automatic coding style, in my personal style
beauty:
	clang-format -i -style=file */*.cpp
	clang-format -i -style=file */*.h

# Checks the memory for leaks
MFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
memory:clean build
	valgrind $(MFLAGS) ./$(EXE)

# Adds and updates gitignore rules
gitignore:
	@echo "bin/*" > .gitignore ||:
	@echo ".vscode*" >> .gitignore ||:	
	echo "Updated .gitignore"
