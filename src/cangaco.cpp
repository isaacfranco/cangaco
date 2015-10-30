#include <iostream>
//#include "globals.h"
#include "game.h"

using namespace std;

int main(int argc, char *argv[]) {
	game = new Game(800, 600, 30);

	if (!game->Init()) {
		cerr << "Error initializing game" << endl;
		return -1;
	}

	game->Start();

	delete(game);

	return 0;
}
