SHELL := /bin/bash
MAKEFLAGS += --no-print-directory

C_COMPILER := gcc -std=c18
C_DEBUG_FLAGS := -Wall -Wextra -g
C_DEV_COMPILER := $(C_COMPILER) $(C_DEBUG_FLAGS)

CODE_DIR := src
BUILD_DIR := dist
DEPS_DIR := deps
TESTS_DIR := tests

UNITY_SRC_DIR := $(DEPS_DIR)/unity_testing_library/src
RAYLIB_SRC_DIR := $(DEPS_DIR)/raylib_5/src
RAYLIB_LIB_DIR := $(DEPS_DIR)/raylib_5/lib
RAYGUI_SRC_DIR := $(DEPS_DIR)/raygui_4/src

RAYLIB_LIB_PATH_VAR := LD_LIBRARY_PATH=$(RAYLIB_LIB_DIR)

DEPS_LIST_FILE := deps.txt
UNITY_MAIN_FILE := $(UNITY_SRC_DIR)/unity.c

#>> Helper definition to print all documented commands (based on https://diamantidis.github.io/tips/2020/07/01/list-makefile-targets)
.DEFAULT_GOAL := help
.PHONY: help

help: ## Show info about described targets/commands
	echo "List of available (documented) commands:"
	grep -Po '^[a-zA-Z0-9|_|-|/|$$|(|)|%|\.]+:.*?## .*$$' $(MAKEFILE_LIST) \
	| sed -n 's/^\(.*\): \(.*\)##\(.*\)/  \1##←\3/p' \
	| column -t -s '##'
	echo "To document a command, just add a ## comment at the end of the target's line, after the prerequisites"
#<< Helper definition to print all documented commands [END]

.PHONY: run_main link_all compile_all compile_raylib clean_raylib clean_raygui clean_all_raylib compile_cfiles create_dist clean_dist include_dynamic_array include_fibonacci install_deps create_deps clean_deps run_all_tests test_% clean_tests clean_all

run_main: link_all ## Execute the entire pipeline to run the code in the src/main.c file
	$(RAYLIB_LIB_PATH_VAR) ./$(BUILD_DIR)/main

link_all: compile_all ## Link all generated object files inside of the dist/ directory into a main executable file
	$(C_DEV_COMPILER) -L $(RAYLIB_LIB_DIR) \
	$(BUILD_DIR)/*.o -o $(BUILD_DIR)/main \
	-lraylib -lraygui

compile_all: compile_raylib compile_cfiles ## Compile all C files in src/ and all their needed dependencies and libs

compile_raylib: $(RAYLIB_LIB_DIR)/libraylib.so $(RAYLIB_LIB_DIR)/libraygui.so ## Compile lib files for Raylib and RayGUI

$(RAYLIB_LIB_DIR)/libraylib.so: $(RAYLIB_SRC_DIR)/Makefile
	mkdir -p $(RAYLIB_LIB_DIR)
	$(MAKE) -C $(RAYLIB_SRC_DIR) GRAPHICS=GRAPHICS_API_OPENGL_11 RAYLIB_RELEASE_PATH=../lib RAYLIB_LIBTYPE=SHARED

clean_raylib: ## Clean Raylib generated files
	rm -f $(RAYLIB_LIB_DIR)/libraylib.so

$(RAYLIB_LIB_DIR)/libraygui.so: $(RAYGUI_SRC_DIR)/raygui.h $(RAYLIB_LIB_DIR)/libraylib.so
	cp $(RAYGUI_SRC_DIR)/raygui.h $(RAYLIB_SRC_DIR)/raygui.h
	cp $(RAYLIB_SRC_DIR)/raygui.h $(RAYLIB_SRC_DIR)/raygui.c
	$(C_DEV_COMPILER) -L $(RAYLIB_LIB_DIR) \
	-o $(RAYLIB_LIB_DIR)/libraygui.so $(RAYLIB_SRC_DIR)/raygui.c \
	-shared -fpic -DRAYGUI_IMPLEMENTATION -lraylib \
	-lGL -lm -lpthread -ldl -lrt -lX11

clean_raygui: ## Clean RayGUI generated files
	rm -f $(RAYLIB_LIB_DIR)/libraygui.so
	rm -f $(RAYLIB_SRC_DIR)/raygui.c
	rm -f $(RAYLIB_SRC_DIR)/raygui.h

clean_all_raylib: clean_raygui clean_raylib ## Clean Raylib's (and its additional modules) generated files and directories
	rm -rf $(RAYLIB_LIB_DIR)/

compile_cfiles: ## Compile each C file inside of src/ into a respective object file inside of dist/
	for source_file in $(CODE_DIR)/*.c; do\
		make $(BUILD_DIR)/$$(echo $${source_file} | grep -Po '$(CODE_DIR)/\K[\w]*(?#.c)').o -s;\
	done

$(BUILD_DIR)/%.o: $(CODE_DIR)/%.c create_dist ## Compile the src/<name>.c file into the dist/<name>.o file
	$(C_DEV_COMPILER) -c $< -o $@

create_dist: ## Create the dist/ directory if it doesn't exist
	mkdir -p $(BUILD_DIR)

clean_dist: ## Clean up all files generated inside of the dist/ directory
	rm -rf $(BUILD_DIR)/

install_deps: create_deps ## Install into the deps/ folder the remote dependencies from URLs listed in the deps.txt file
	while read -r deps_line; do\
		wget -O $$(\
			echo $${deps_line} \
			| sed -n 's/^\(.*\) | \(.*\)/ $(DEPS_DIR)\/\1.tar.gz/p'\
		) $$(\
			echo $${deps_line} \
			| sed -n 's/^\(.*\) | \(.*\)/ \2/p'\
		);\
	done < $(DEPS_LIST_FILE)
	for tar_file in $(DEPS_DIR)/*.tar.gz; do\
		tar -xvf $${tar_file} -C $(DEPS_DIR) --one-top-level --strip-components=1 \
		&& rm $${tar_file};\
	done

create_deps: ## Create the deps/ directory if it doesn't exist
	mkdir -p $(DEPS_DIR)

clean_deps: ## Clean up all dependencies downloaded to the deps/ directory
	rm -rf $(DEPS_DIR)/

include_dynamic_array: $(CODE_DIR)/dynamic_array.c
	@echo "-include $(CODE_DIR)/dynamic_array.c"

include_fibonacci: $(CODE_DIR)/fibonacci.c
	@echo "$(shell $(MAKE) include_dynamic_array) -include $(CODE_DIR)/fibonacci.c"

run_all_tests: $(UNITY_MAIN_FILE) ## Run all test files in the tests/ directory
	for test_file in $(TESTS_DIR)/*.test.c; do\
		$(MAKE) test_$$(basename $${test_file} .test.c);\
	done

test_%: $(CODE_DIR)/%.c $(TESTS_DIR)/%.test.out ## Use test_<name> to run tests in tests/<name>.test.c for src/<name>.c
	./$(TESTS_DIR)/$*.test.out

$(TESTS_DIR)/%.test.out: $(UNITY_MAIN_FILE) $(TESTS_DIR)/%.test.c
	$(C_DEV_COMPILER) \
	-include $(UNITY_MAIN_FILE) \
	$(shell $(MAKE) include_$*) \
	-o $(TESTS_DIR)/$*.test.out \
	$(TESTS_DIR)/$*.test.c

clean_tests: ## Clean up all output files in the tests/ directory
	rm -rf $(TESTS_DIR)/*.test.out

clean_all: clean_dist clean_tests clean_deps ## Clean all generated files and downloaded dependencies

$(V).SILENT:
