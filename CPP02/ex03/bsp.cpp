#include "Point.hpp"

static float area(const Point a, const Point b, const Point c) {
	float area;

	// Area = 1/2 (x1(y2-y3) + x2(y3-y1) + x3(y1-y2))
	area = 0.5 * (a.getX().toFloat() * (b.getY().toFloat() - c.getY().toFloat())
			+ b.getX().toFloat() * (c.getY().toFloat() - a.getY().toFloat())
			+ c.getX().toFloat() * (a.getY().toFloat() - b.getY().toFloat()));
	return area >= 0 ? area : -area;
}

static bool isOnLine(const Point a, const Point b, const Point c) {
	return ((c.getY().toFloat() < a.getY().toFloat() != c.getY().toFloat() < b.getY().toFloat())
			&& (c.getX().toFloat() < a.getX().toFloat() != c.getX().toFloat() < b.getX().toFloat())
			&& ((b.getX().toFloat() - a.getX().toFloat()) * (c.getY().toFloat() - a.getY().toFloat()) == (b.getY().toFloat() - a.getY().toFloat()) * (c.getX().toFloat() - a.getX().toFloat())));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	float p1, p2, p3, p4;

	p1 = area(a, b, c);
	p2 = area(point, b, c);
	p3 = area(a, point, c);
	p4 = area(a, b, point);
	if (!isOnLine(a, b, point) && !isOnLine(a, c, point) && !isOnLine(b, c, point) && p1 == p2 + p3 + p4)
		return true;
	return false;
}