#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void ) {
	Point a = Point(3, 9);
	Point b = Point(7, 5);
	Point c = Point(2, 2);
	Point x = Point(2, 2);
	if (bsp(a, b, c, x))
		std::cout << "Point " << x.getX().toFloat() << "x" << x.getY().toFloat() << " is inside of triangle\n";
	else
		std::cout << "Point " << x.getX().toFloat() << "x" << x.getY().toFloat() << " is outside of triangle\n";
	return 0;
}