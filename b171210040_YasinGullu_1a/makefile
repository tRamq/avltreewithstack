all: derle	calistir

derle:
	g++ -I ./include/ -o ./lib/Kisi.o -c ./src/Kisi.cpp
	g++ -I ./include/ -o ./lib/stack.o -c ./src/stack.cpp
	g++ -I ./include/ -o ./lib/node.o -c ./src/node.cpp
	g++ -I ./include/ -o ./lib/avlagaci.o -c ./src/avlagaci.cpp
	g++ -I ./include/ -o ./bin/test ./lib/avlagaci.o ./lib/node.o ./lib/Kisi.o ./lib/stack.o ./src/test.cpp

calistir:
	./bin/test