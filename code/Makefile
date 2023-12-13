C_COMPILER := gcc -std=c18
C_DEBUG_FLAGS := -Wall -Wextra -g
C_DEV_COMPILER := $(C_COMPILER) $(C_DEBUG_FLAGS)

UNITY_SRC_DIR := deps/Unity-*/src

### Helper definition to print all documented commands based on https://diamantidis.github.io/tips/2020/07/01/list-makefile-targets 
.DEFAULT_GOAL := help
.PHONY: help

help:
	echo "List of available (documented) commands:"
	grep -Po '^[a-zA-Z0-9_-|\/|\%|\.]+:.*?## .*$$' $(MAKEFILE_LIST) \
	| sed -n 's/^\(.*\): \(.*\)##\(.*\)/  \1##←\3/p' \
	| column -t -s '##'
	echo "To document a command, just add a ## comment at the end of the target's line, after the prerequisites"
### End of helper definition to print all documented commands

run_main: compile_all link_all ## Execute the entire pipeline to run the code in the src/main.c file
	./dist/main

compile_all: ## Compile all C files inside of src/ into a respective object file inside of dist/
	for source_file in src/*.c; do\
		make dist/$$(echo $${source_file} | grep -Po 'src/\K[\w]*(?#.c)').o -s;\
	done

dist/%.o: src/%.c create_dist ## Compile the src/<name>.c file into the dist/<name>.o file
	$(C_DEV_COMPILER) -c $< -o $@

create_dist: ## Create the dist/ directory if it doesn't exist
	mkdir -p dist

link_all: ## Link all generated object files inside of the dist/ directory into a main executable file
	$(C_DEV_COMPILER) $$(echo dist/*.o) -o dist/main

clean_dist: ## Clean up all files generated inside of the dist/ directory
	rm -rf dist/

install_deps: ## Install into the deps/ folder the remote dependencies from URLs listed in the deps.txt file
	mkdir -p deps
	while read -r deps_line; do\
		wget -O $$(\
			echo $${deps_line} \
			| sed -n 's/^\(.*\) | \(.*\)/ deps\/\1.tar.gz/p'\
		) $$(\
			echo $${deps_line} \
			| sed -n 's/^\(.*\) | \(.*\)/ \2/p'\
		);\
	done < deps.txt
	for tar_file in deps/*.tar.gz; do\
		tar -xvf $${tar_file} -C deps && rm $${tar_file};\
	done

clean_deps: ## Clean up all dependencies downloaded to the deps/ directory
	rm -rf deps/

run_all_tests: $(UNITY_SRC_DIR)/unity.c ## Run all ThrowTheSwitch/Unity test files in the tests/ directory
	for test_file in tests/*.test.c; do\
		$(C_DEV_COMPILER) \
		-include $(UNITY_SRC_DIR)/unity.c \
		-include src/$$(echo $${test_file} | grep -Po 'tests/\K[\w]*(?#.c)').c \
		-o tests/$$(echo $${test_file} | grep -Po 'tests/\K[\w]*(?#.c)').test.out \
		$${test_file};\
		./tests/$$(echo $${test_file} | grep -Po 'tests/\K[\w]*(?#.c)').test.out;\
	done

clean_tests: ## Clean up all output files in the tests/ directory
	rm -rf tests/*.test.out

clean_all: clean_dist clean_tests clean_deps ## Clean all generated files and downloaded dependencies

$(V).SILENT:
