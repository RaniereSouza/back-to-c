C_COMPILER := gcc -std=c18
C_DEBUG_FLAGS := -Wall -Wextra -g
C_DEV_COMPILER := $(C_COMPILER) $(C_DEBUG_FLAGS)

run_main: compile_main
	./dist/main.o

compile_main: src/main.c create_dist
	$(C_DEV_COMPILER) -o dist/main.o src/main.c

create_dist:
	mkdir -p dist

clean:
	rm -rf dist/

$(V).SILENT:
