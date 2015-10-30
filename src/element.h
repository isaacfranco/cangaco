#ifndef _ELEMENT_H_
#define _ELEMENT_H_

#include "scene.h"

class Scene;

class Element {
private:
	Scene *scene;
public:
	Element();
	void AttachToScene(Scene *scene); // must be called only by Scene::SpawnElement
};

#endif