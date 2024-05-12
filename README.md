Back to C (studies)
===================
Devcontainer environment that I made to get back in contact with C and C++: experimenting and learning the basics once again.

## Environment
- Debian GNU/Linux v11 (bullseye)
- GCC v10.2.1 (Debian)
- GNU Make v4.3
- Git v2.40.1

## 3rd party depencencies
- [ThrowTheSwitch/Unity](https://www.throwtheswitch.org/unity) - Used for Unit Testing in C
- [Raylib](https://www.raylib.com/) - Used to facilitate graphics implementation
  - [RayGUI](https://github.com/raysan5/raygui) - External Raylib additional module that implements common UI elements

## How to run
- In the command line, `cd` into the `code/` folder
- To see what each (documented) command does, run `make` or `make help`
- To just compile the C code from `src/main.c` and all other C files on `src/`, run `make compile_all`
- To run the C code in `src/main.c` (as well as link all object files needed for that), run `make run_main`
- To install all 3rd party dependencies listed in `deps.txt`, run `make install_deps`
  - To clean all installed files from 3rd party dependencies, run `clean_deps`
- To define the dependency hierarchy of `src/foo.c` for building and testing purposes, write a target called `include_foo` in the Makefile
  - This target will be used to define the `-include` values needed for the correct compilation and running of `src/foo.c` (example: if `src/foo.c` doesn't have any dependencies, the compiler will only need a `-include src/foo.c` argument; if the file depends on `src/bar.c`, the compiler will need the `-include src/bar.c -include src/foo.c` arguments)
- To run all unit tests, run `make run_all_tests`
  - Write tests for `src/foo.c` in a `tests/foo.test.c` file
  - To run tests for a specific `src/foo.c` file, run `make test_foo`
  - To clean all executables generated for testing, run `make clean_tests`
- To clean up all generated and downloaded files, run `make clean_all`
> Obs. 1: The contents generated from default compilation will be in the `dist/` folder
> Obs. 2: The downloaded contents for 3rd party dependencies will be in the `deps/` folder
> Obs. 3: The files for testing purposes will be in the `tests/` folder
> Obs. 4: If you want the commands in the Makefile targets to be shown in the command line, pass the argument `V=1` to the `make` command for verbosity (`make V=1 (...)` or `make (...) V=1`, for example; this verbosity argument doesn't work well for some commands, so it still needs some fixing)
