# all is a target, compile is a dependency.
# all is the most important target, as it's your start point.

# Dependency: always run compile before processing all.
# Dependencies must be listed on the same line as their related target.
all: compile

compile: main.o func1.o func2.o
	gcc -o binary main.o func1.o func2.o

main.o: main.c
	gcc -c main.c

func1.o: func1.c
	gcc -c func1.c

func2.o: func2.c
	gcc -c func2.c
