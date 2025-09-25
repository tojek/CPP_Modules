#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	Data data;

	data.id = 1;
	data.name = "John";
	data.surname = "Doe";

	std::cout << "Original Data address: " << &data << std::endl;
	std::cout << "Original Data values: " << data.id << ", " << data.name << ", " << data.surname << std::endl;

	uintptr_t serialized = Serializer::serialize(&data);
	std::cout << "Serialized Data (as uintptr_t): " << serialized << std::endl;

	Data* deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized Data address: " << deserialized << std::endl;
	std::cout << "Deserialized Data values: " << deserialized->id << ", " << deserialized->name << ", " << deserialized->surname << std::endl;

	return 0;
}