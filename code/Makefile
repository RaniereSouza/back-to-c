C_COMPILER := gcc -std=c18
C_DEBUG_FLAGS := -Wall -Wextra -g
C_DEV_COMPILER := $(C_COMPILER) $(C_DEBUG_FLAGS)

### Helper definition to print all documented commands based on https://diamantidis.github.io/tips/2020/07/01/list-makefile-targets 
.DEFAULT_GOAL := help
.PHONY: help

help:
	echo "List of available (documented) commands:"
	grep -Po '^[a-zA-Z0-9_-]+:.*?## .*$$' $(MAKEFILE_LIST) \
	| sed -n 's/^\(.*\): \(.*\)##\(.*\)/  \1##←\3/p' \
	| column -t -s '##'
	echo "To document a command, just add a ## comment at the end of the target's line, after the prerequisites"
### End of helper definition to print all documented commands

run_main: compile_main ## Run the compiled result file from the src/main.c file
	./dist/main.o

compile_main: src/main.c create_dist ## Compile the src/main.c file into the dist/main.o file
	$(C_DEV_COMPILER) -o dist/main.o src/main.c

create_dist: ## Create the dist/ directory if it doesn't exist
	mkdir -p dist

clean: ## Clean up all files generated in the dist/ directory
	rm -rf dist/

$(V).SILENT:
