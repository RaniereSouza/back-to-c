C_COMPILER := gcc -std=c18

run_main: compile_main
	./dist/main.o

compile_main: src/main.c create_dist
	$(C_COMPILER) -o dist/main.o src/main.c

create_dist:
	mkdir -p dist

clean:
	rm -rf dist/

$(V).SILENT:
