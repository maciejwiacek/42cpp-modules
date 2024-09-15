#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a = Point(1, 1);
	Point b = Point(6, 1);
	Point c = Point(3, 4);
	Point x = Point(0, 1);
	if (bsp(a, b, c, x))
		std::cout << "Point " << x.getX().toFloat() << "x" << x.getY().toFloat() << " is inside of triangle\n";
	else
		std::cout << "Point " << x.getX().toFloat() << "x" << x.getY().toFloat() << " is outside of triangle\n";
	return 0;
}