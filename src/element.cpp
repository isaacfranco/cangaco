#include "element.h"

Element::Element() {
	
}

void Element::AttachToScene(Scene *scene) {
	this->scene = scene;
}