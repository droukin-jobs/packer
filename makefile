pack:
	gcc -o pack.exe -DPACK main.c

struct:
	gcc -o struct.exe -DSTRUCT main.c

array:
	gcc -o array.exe -DARRAY main.c
all: pack struct array

test_pack:
	@echo Test pack
	time ./pack.exe > /dev/null

test_struct:
	@echo Test struct
	time ./struct.exe > /dev/null

test_array:
	@echo Test array
	time ./array.exe > /dev/null

test_all: test_pack test_struct test_array

