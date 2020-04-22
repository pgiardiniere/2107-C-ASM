# Make : requires a static library index
all: static_library_index

# Create index to contents of archive (library)
static_library_index: libVector.a
	ranlib libVector.a

# Creates archive (library) from binary object files
libVector.a: sub.o swap.o create_vector.o add_from_con.o write_to_file.o equals.o search.o copy_range.o copy.o dbl_equals.o empty_vector.o delete_vector.o zeros.o fill.o divv.o stdv.o avg.o print_vec.o var.o print_min.o dot.o add.o get_from_con.o sort.o mul.o sum.o read_from_file.o clear_vector.o reverse.o insert.o
	ar rc libVector.a sub.o swap.o create_vector.o add_from_con.o write_to_file.o equals.o search.o copy_range.o copy.o dbl_equals.o empty_vector.o delete_vector.o zeros.o fill.o divv.o stdv.o avg.o print_vec.o var.o print_min.o dot.o add.o get_from_con.o sort.o mul.o sum.o read_from_file.o clear_vector.o reverse.o insert.o

# Create all binary object files
sub.o: sub.c
	gcc -c -I. sub.c

swap.o: swap.c
	gcc -c -I. swap.c

create_vector.o: create_vector.c
	gcc -c -I. create_vector.c

add_from_con.o: add_from_con.c
	gcc -c -I. add_from_con.c

write_to_file.o: write_to_file.c
	gcc -c -I. write_to_file.c

equals.o: equals.c
	gcc -c -I. equals.c

search.o: search.c
	gcc -c -I. search.c

copy_range.o: copy_range.c
	gcc -c -I. copy_range.c

copy.o: copy.c
	gcc -c -I. copy.c

dbl_equals.o: dbl_equals.c
	gcc -c -I. dbl_equals.c

empty_vector.o: empty_vector.c
	gcc -c -I. empty_vector.c

delete_vector.o: delete_vector.c
	gcc -c -I. delete_vector.c

zeros.o: zeros.c
	gcc -c -I. zeros.c

fill.o: fill.c
	gcc -c -I. fill.c

divv.o: divv.c
	gcc -c -I. divv.c

stdv.o: stdv.c
	gcc -c -I. stdv.c

avg.o: avg.c
	gcc -c -I. avg.c

print_vec.o: print_vec.c
	gcc -c -I. print_vec.c

var.o: var.c
	gcc -c -I. var.c

print_min.o: print_min.c
	gcc -c -I. print_min.c

dot.o: dot.c
	gcc -c -I. dot.c

add.o: add.c
	gcc -c -I. add.c

get_from_con.o: get_from_con.c
	gcc -c -I. get_from_con.c

sort.o: sort.c
	gcc -c -I. sort.c

mul.o: mul.c
	gcc -c -I. mul.c

sum.o: sum.c
	gcc -c -I. sum.c

read_from_file.o: read_from_file.c
	gcc -c -I. read_from_file.c

clear_vector.o: clear_vector.c
	gcc -c -I. clear_vector.c

reverse.o: reverse.c
	gcc -c -I. reverse.c

insert.o: insert.c
	gcc -c -I. insert.c


# Compile using static library index
compile:
	gcc -o main main.c -L. -lVector -lm

# Cleanup intermediate object-file output
clean:
	rm -r *.o
