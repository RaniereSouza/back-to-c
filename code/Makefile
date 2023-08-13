C_COMPILER := gcc -std=c18
C_DEBUG_FLAGS := -Wall -Wextra -g
C_DEV_COMPILER := $(C_COMPILER) $(C_DEBUG_FLAGS)

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

create_dist:
	mkdir -p dist

clean:
	rm -rf dist/

$(V).SILENT:
