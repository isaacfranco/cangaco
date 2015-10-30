#include "scene.h"

Scene::Scene(std::string name) {
	this->name = name;	
}

void Scene::SpawnElement(Element *element) {
	element->AttachToScene(this);
	this->elements.push_back(element);
}

bool Scene::ElementIsPresent(Element *element) {
	std::list<Element *>::iterator iter = this->elements.begin();
	while (iter != this->elements.end()) {
		if (*iter == element) {
			return true;
		}
	}
	return false;
}

void Scene::RemoveElement(Element *element) {
	this->elements.remove(element);
}