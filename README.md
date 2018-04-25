# Data Packer - size and stack efficient way of storing large number of small chunks of data

# Toc

### INTRO
### COMPILE
### INSTALL
### USAGE
### RESULTS

---

# INTRO

The project's aim is to provide a simple and efficient way of storing lots of small data pieces. Sometimes there are many small indexes that have to be stored in array or in a struct. If stored separately each entity occupies from 1 byte (at best) to 8 bytes. E.g. there are 3 types of banking cards to be stored in a struct. The index can fit into 2-bit area, so theoretically it is possible to store up to 4 times more data in one byte. 

Bitfields supposed to solve this problem, but these are compiler dependant and not as efficient as could be. So the only way to optimize storage is to use bit masks and bitwise operators.

But this will clutter the code. Using functions is out of question: stack and execution overhead will buildup especially on embedded systems. The solution is to use `#define` postprocessor directives.

A working example of bitwise operatirs as well as struct bitfields and array approach is contained in `main.c` file. Preprocessor directives are contained in `packer.h` file. 

# COMPILE

`make pack` will create `pack.exe` - the binary with packer algorytthm.

`make struct` will create `struct.exe` - struct with bitfields.

`make array` will create `array.exe` - array approach.

`make all` will build all of the above.

# INSTALL

The binaries can be run from the build directory.

# USE

Study the source code in `main.c` and `packer.h` to understand the workings of binary operators. Remember - #define just puts whatever is 'defined' in place of the pseudo-functions. To test the running time of different algorythms execute `make test_{binary}`. It is recommended to run `make test_all` several times to leverage the prefetch optimisations. It is good idea to start with `MAX_SIZE` of about 1/32 of free memory and then double the value if necessary to see meaningful results.
 
# RESULTS

I put some results in `test_results` file - those were obtained on `Darwin Kernel Version 14.3.0 root:xnu-2782.20.48~5/RELEASE_X86_64 x86_64`. Surprisingly the memory usage of `STRUCT` is still worse than `PACK` despite using bitfields.
