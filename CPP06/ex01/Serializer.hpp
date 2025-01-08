#pragma once

#include <stdint.h>

struct Data {
	int value;
};

class Serializer {
	private:
		Serializer();
		Serializer(Serializer& other);
		Serializer& operator=(Serializer& other);
		~Serializer();
	public:
		static uintptr_t serialize(Data *ptr);
		static Data* serialize(uintptr_t raw);
};
