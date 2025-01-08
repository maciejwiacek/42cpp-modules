#include "Classes.hpp"

int main() {
	Base* randClass = generate();
	identify(randClass);
	delete randClass;
}