CC=g++
OBJS=game.o element.o scene.o vector2.o
SRCDIR=src
BUILDDIR=build

game.o: game.h game.cpp
	$(CC) game.cpp -c

vector2.o: vector2.h vector2.cpp
	$(CC) vector2.cpp -c

rotation.o: rotation.h rotation.cpp
	$(CC) rotation.cpp -c

element.o: element.h element.cpp
	$(CC) element.cpp -c

scene.o: scene.h scene.cpp
	$(CC) scene.cpp -c

cangaco: cangaco.cpp $(OBJS)
	g++ cangaco.cpp $(OBJS) -o ../bin/cangaco -lallegro -lallegro_main -lallegro_primitives -lallegro_ttf -lallegro_font
	rm -fr ../bin/fonts
	cp -a ../fonts ../bin/

clean:
	rm ../bin/cangaco $(OBJS)