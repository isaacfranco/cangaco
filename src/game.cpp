#include "game.h"

Game *game; // extern declared on game.h

using namespace std;

Game::Game(int width, int height, double fps) {
	this->width = width;
	this->height = height;
	this->fps = fps;
	this->finalized = false;
}

Game::~Game() {
	al_destroy_font(this->title_font);
	al_destroy_display(this->display);
}


void Game::Update() {

}

void Game::Draw() {
	al_clear_to_color(al_map_rgb(255, 255, 255));

	al_draw_text(this->title_font, al_map_rgb(150, 0, 0), this->width/2, (this->height/2) - 50, ALLEGRO_ALIGN_CENTER, "Cangaço");

	al_flip_display();
}

bool Game::IsFinalized() {

}


bool Game::Init() {
	if (!al_init()) {
		cerr << "Error initializing Allegro" << endl;
		return false;
	}

	// Mouse
	if (!al_install_mouse()) {
		cerr << "Error initializing Mouse" << endl;
		return false;
	}

	// Keyboard
	if (!al_install_keyboard()) {
		cerr << "Error initializing Keyboard" << endl;
		return false;
	}
	
	// initialize the font addon
	al_init_font_addon();

	// initialize the ttf (True Type Font) addon
	al_init_ttf_addon();

	this->display = al_create_display(this->width, this->height);

	if (!display) {
		cerr << "Error initializing display" << endl;
		return false;
	}

	// Fonts
	this->title_font = al_load_ttf_font("fonts/Logger.ttf",72,0);

	if (!this->title_font) {
		cerr << "Error loading font" << endl;
		return false;
	}

	this->main_timer = al_create_timer(1.0/this->fps);

	if (!this->main_timer) {
		cerr << "Error creating main timer" << endl;
		return false;
	}

	this->main_event_queue = al_create_event_queue();

	if (!this->main_event_queue) {
		cerr << "Error creating main event queue" << endl;
		return false;
	}

	// Registering event sources on main queue
	al_register_event_source(this->main_event_queue, al_get_mouse_event_source());
	al_register_event_source(this->main_event_queue, al_get_keyboard_event_source());
	al_register_event_source(this->main_event_queue, al_get_timer_event_source(this->main_timer));


	return true;
}

void Game::Start() {
	al_start_timer(this->main_timer);

	ALLEGRO_EVENT event;

	while (!this->IsFinalized()) {
		al_wait_for_event(this->main_event_queue, &event);
		switch(event.type) {
			case ALLEGRO_EVENT_TIMER:
				this->Update();
				this->Draw();
				break;
		}
	}
}
