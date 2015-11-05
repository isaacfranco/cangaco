#include "vector2.h"
#include <cmath>

Vector2::Vector2() {

}

double Vector2::Distance(Vector2 &p1, Vector2 &p2) {
	return sqrt( pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) );
}