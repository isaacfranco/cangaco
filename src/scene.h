#ifndef _SCENE_H_
#define _SCENE_H_

#include <list>
#include <string>
#include "element.h"
#include "globals.h"

class Element;

class Scene {
private:
	std::string name;
	std::list<Element *> elements;
public:
	Scene(std::string name);

	void SpawnElement(Element *element);

	bool ElementIsPresent(Element *element);

	void RemoveElement(Element *element);
};

#endif