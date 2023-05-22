Back to C (studies)
===================
Devcontainer environment that I made to get back in contact with C and C++: experimenting and learning the basics once again.

## Environment
- Debian GNU/Linux v11 (bullseye)
- GCC v10.2.1 (Debian)
- GNU Make v4.3
- Git v2.40.1

## How to run
- In the command line, `cd` into the `code` folder
- To just compile the C code from `src/main.c`, run `make compile_main`
- To run the C code in `src/main.c`, run `make run_main`
- To clean up the generated files, run `make clean`
> Obs. 1: The contents generated from compilation will be in the `dist` folder
> Obs. 2: If you want the commands in the Makefile to be echoed, pass the argument `V=1` to the `make` command for verbosity (`make V=1 (...)` or `make (...) V=1`, for example)
