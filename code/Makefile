C_COMPILER := gcc -std=c18

run_main: link_all dist/main
	./dist/main

link_all: compile_all dist/main.o dist/fibonacci.o
	$(C_COMPILER) dist/main.o dist/fibonacci.o -o dist/main

compile_all: src/main.c src/fibonacci.c create_dist
	$(C_COMPILER) -c src/fibonacci.c -o dist/fibonacci.o
	$(C_COMPILER) -c src/main.c -o dist/main.o

create_dist:
	mkdir -p dist

clean:
	rm -rf dist/

$(V).SILENT:
