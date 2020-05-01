# Variable for compiler
CC=gcc
# Variable for compiler options
CFLAGS=-c -Wall -fPIC -I.
# Variable for cleanup command
# to clean .o file
CLEANUP=rm -rf *o

# Entry point and exit point for call to "make".
# all is the target and compile is dependency.
# makeRanLib will be completed before all.
all: makeLink

# Execute this after moveLib
# Creates links to library
makeLink: makeLib
	ln -sf libString.so.0.0 libString.so.0
	ln -sf libString.so.0 libString.so

# Execute this after all String object files are created
# Create a library files libString.so and libString.so.1
makeLib: toUpper.o toLower.o strLen.o strCpy.o strCat.o strCmp.o strCmpIgnoreCase.o strEql.o strEqlIgnoreCase.o
	gcc -shared -Wl,-soname,libString.so.0 -o libString.so.0.0 *.o

# Create object files
toUpper.o: toUpper.c
	$(CC) $(CFLAGS) toUpper.c

toLower.o: toLower.c
	$(CC) $(CFLAGS) toLower.c

strLen.o: strLen.c
	$(CC) $(CFLAGS) strLen.c

strCpy.o: strCpy.c
	$(CC) $(CFLAGS) strCpy.c

strCat.o: strCat.c
	$(CC) $(CFLAGS) strCat.c

strCmp.o: strCmp.c
	$(CC) $(CFLAGS) strCmp.c

strCmpIgnoreCase.o: strCmpIgnoreCase.c
	$(CC) $(CFLAGS) strCmpIgnoreCase.c

strEql.o: strEql.c
	$(CC) $(CFLAGS) strEql.c

strEqlIgnoreCase.o: strEqlIgnoreCase.c
	$(CC) $(CFLAGS) strEqlIgnoreCase.c

# This compiles the executable file test.exe
# using the static library libString.a
compile:
	gcc -o test.exe main.c -L. -lString

# Run the executable with the library path
run:
	LD_LIBRARY_PATH="." ./test.exe

# Remove object
clean:
	$(CLEANUP)
