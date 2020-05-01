# Make : requires a static library index
all: dynamic_link

# Create index to contents of archive (library)
dynamic_link: makeLib
	ln -sf libVector.so.0.0 libVector.so.0
	ln -sf libVector.so.0 libVector.so


# Creates archive (library) from binary object files
makeLib: sub.o swap.o create_vector.o add_from_con.o write_to_file.o equals.o search.o copy_range.o copy.o dbl_equals.o empty_vector.o delete_vector.o zeros.o fill.o divv.o stdv.o avg.o print_vec.o var.o print_min.o dot.o add.o get_from_con.o sort.o mul.o sum.o read_from_file.o clear_vector.o reverse.o insert.o
	gcc -shared -Wl,-soname,libVector.so.0 -o libVector.so.0.0 *.o

# Create all binary object files
sub.o: sub.c
	gcc -c -fPIC -I. sub.c

swap.o: swap.c
	gcc -c -fPIC -I. swap.c

create_vector.o: create_vector.c
	gcc -c -fPIC -I. create_vector.c

add_from_con.o: add_from_con.c
	gcc -c -fPIC -I. add_from_con.c

write_to_file.o: write_to_file.c
	gcc -c -fPIC -I. write_to_file.c

equals.o: equals.c
	gcc -c -fPIC -I. equals.c

search.o: search.c
	gcc -c -fPIC -I. search.c

copy_range.o: copy_range.c
	gcc -c -fPIC -I. copy_range.c

copy.o: copy.c
	gcc -c -fPIC -I. copy.c

dbl_equals.o: dbl_equals.c
	gcc -c -fPIC -I. dbl_equals.c

empty_vector.o: empty_vector.c
	gcc -c -fPIC -I. empty_vector.c

delete_vector.o: delete_vector.c
	gcc -c -fPIC -I. delete_vector.c

zeros.o: zeros.c
	gcc -c -fPIC -I. zeros.c

fill.o: fill.c
	gcc -c -fPIC -I. fill.c

divv.o: divv.c
	gcc -c -fPIC -I. divv.c

stdv.o: stdv.c
	gcc -c -fPIC -I. stdv.c

avg.o: avg.c
	gcc -c -fPIC -I. avg.c

print_vec.o: print_vec.c
	gcc -c -fPIC -I. print_vec.c

var.o: var.c
	gcc -c -fPIC -I. var.c

print_min.o: print_min.c
	gcc -c -fPIC -I. print_min.c

dot.o: dot.c
	gcc -c -fPIC -I. dot.c

add.o: add.c
	gcc -c -fPIC -I. add.c

get_from_con.o: get_from_con.c
	gcc -c -fPIC -I. get_from_con.c

sort.o: sort.c
	gcc -c -fPIC -I. sort.c

mul.o: mul.c
	gcc -c -fPIC -I. mul.c

sum.o: sum.c
	gcc -c -fPIC -I. sum.c

read_from_file.o: read_from_file.c
	gcc -c -fPIC -I. read_from_file.c

clear_vector.o: clear_vector.c
	gcc -c -fPIC -I. clear_vector.c

reverse.o: reverse.c
	gcc -c -fPIC -I. reverse.c

insert.o: insert.c
	gcc -c -fPIC -I. insert.c


# Compile using dynamic linking
compile:
	gcc -o main main.c -L. -lVector -lm

run:
	LD_LIBRARY_PATH="." ./main

# Cleanup intermediate object-file output
clean:
	rm -r *.o
