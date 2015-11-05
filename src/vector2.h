#ifndef _VECTOR2_H_
#define _VECTOR2_H_

class Vector2 {
public:
	double x, y;
	Vector2();

	static double Distance(Vector2 &v1, Vector2 &v2);
};

#endif