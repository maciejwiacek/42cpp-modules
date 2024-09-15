#include "Point.hpp"

Point::Point(): x(0), y(0) {
}

Point::Point(const float x, const float y): x(x), y(y) {
}

Point::Point(const Point &point): x(point.x), y(point.y) {
}

Point &Point::operator=(const Point &copy) {
	if (this != &copy)
		return *this;
	return *this;
}

Point::~Point() {
}

const Fixed Point::getX() const {
	return this->x;
}

const Fixed Point::getY() const {
	return this->y;
}