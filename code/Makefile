C_COMPILER := gcc -std=c18
C_DEBUG_FLAGS := -Wall -Wextra -g
C_DEV_COMPILER := $(C_COMPILER) $(C_DEBUG_FLAGS)

run_main: link_all dist/main
	./dist/main

link_all: compile_all dist/main.o dist/fibonacci.o
	$(C_DEV_COMPILER) dist/main.o dist/fibonacci.o -o dist/main

compile_all: src/main.c src/fibonacci.c create_dist
	$(C_DEV_COMPILER) -c src/fibonacci.c -o dist/fibonacci.o
	$(C_DEV_COMPILER) -c src/main.c -o dist/main.o

create_dist:
	mkdir -p dist

clean:
	rm -rf dist/

$(V).SILENT:
