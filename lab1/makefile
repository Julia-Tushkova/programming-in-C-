all: super_main

super_main: generator
	g++ func.cpp main.cpp -o main
	./main

generator:
	g++ generator.cpp -o generator
	./generator
