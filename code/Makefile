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

run_main: compile_all link_all
	./dist/main

link_all:
	$(C_DEV_COMPILER) $$(echo dist/*.o) -o dist/main

compile_all:
	for source_file in src/*.c; do\
		make dist/$$(echo $${source_file} | grep -Po 'src/\K[\w]*(?#.c)').o -s;\
	done

dist/%.o: src/%.c create_dist
	$(C_DEV_COMPILER) -c $< -o $@

create_dist: ## Create the dist/ directory if it doesn't exist
	mkdir -p dist

clean: ## Clean up all files generated in the dist/ directory
	rm -rf dist/

$(V).SILENT:
