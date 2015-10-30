CC=g++
OBJS=game.o
SRCDIR=src
BUILDDIR=build

game.o: game.h game.cpp
	$(CC) game.cpp -c

cangaco: cangaco.cpp $(OBJS)
	g++ cangaco.cpp $(OBJS) -o ../bin/cangaco -lallegro -lallegro_main -lallegro_primitives -lallegro_ttf -lallegro_font
	cp -a ../fonts ../bin/

clean:
	rm cangaco $(OBJS)