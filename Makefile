#g++ -Wall program.cpp -o output_name `sdl2-config --cflags --libs`
#Monta o Defs.cpp com Defs.hpp
#Monta o main.cpp com Defs.hpp
#Monta o executavel com main.o e defs.o

all: main

main: ./obj/main.o ./obj/Defs.o
	g++ -Wall obj/main.o obj/Defs.o -o ./bin/main `sdl2-config --cflags --libs`


./obj/main.o: ./src/main.cpp ./include/Defs.hpp
	g++ -Wall -c ./src/main.cpp -o ./obj/main.o `sdl2-config --cflags --libs`

./obj/Defs.o: ./src/Defs.cpp ./include/Defs.hpp
	g++ -Wall -c ./src/Defs.cpp -o ./obj/Defs.o `sdl2-config --cflags --libs`

clean:
	rm -rf ./obj/*.o ./bin/main
