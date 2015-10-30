#ifndef _GAME_H_
#define _GAME_H_

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

class Game {
private:
	bool finalized;
	ALLEGRO_DISPLAY *display;
	double fps;
	ALLEGRO_FONT *title_font;
	ALLEGRO_TIMER *main_timer;
	ALLEGRO_EVENT_QUEUE *main_event_queue;
	int width, height; // display width and height

	void Update();

	void Draw();

	bool IsFinalized();

public:
	Game(int width, int height, double fps);

	~Game();

	bool Init();

	void Start();
};

extern Game *game; // global game

#endif