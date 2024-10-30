#include "plant.h"

// Конструктор без параметров
Plant::Plant() : name("def"), height(0), type_of_plant("def") {
	std::cout << "Constructor without parameters" << std::endl;
}

// Конструктор с параметрами
Plant::Plant(std::string name, int height, std::string type_of_plant)
	: name(name), height(height), type_of_plant(type_of_plant) {
	std::cout << "Constructor with parameters" << std::endl;
}

// Конструктор копирования
Plant::Plant(const Plant& other) {
	name = other.name;
	height = other.height;
	type_of_plant = other.type_of_plant;
	std::cout << "Copy constructor" << std::endl;
}

// Деструктор
Plant::~Plant()
{
	height = -1;
	std::cout << "Destructor" << std::endl;
}

// Перегрузка оператора сложения
Plant Plant::operator+(const Plant& other)
{
	std::string new_name = name + " & " + other.name;
	int new_height = height + other.height;
	std::string new_type_of_plant = type_of_plant + "/" + other.type_of_plant;
	return Plant(new_name, new_height, new_type_of_plant);
}

// Перегрузка оператора сравнения
bool Plant::operator>(const Plant& other)
{
	std::cout << "operation>" << std::endl;
	if (height > other.height) return true;
	return false;
}

// Перегрузка оператора сравнения
bool Plant::operator<(const Plant& other)
{
	std::cout << "operation<" << std::endl;
	if (height < other.height) return true;
	return false;
}

// Перегрузка оператора сравнения
bool Plant::operator==(const Plant& other)
{
	std::cout << "operation==" << std::endl;
	if (height == other.height && name
		== other.name && type_of_plant
		== other.type_of_plant) return true;
	return false;
}

// Перегрузка оператора сравнения
bool Plant::operator!=(const Plant& other)
{
	std::cout << "operation!=" << std::endl;
	return !(*this == other);
}

// Перегрузка операции присваивания без перемещения
const Plant& Plant::operator= (const Plant& other) { // Передаём ссылку на lvalue
	if (this != &other) {
		name = other.name;
		height = other.height;
		type_of_plant = other.type_of_plant;
	}
	std::cout << "Copy operation" << std::endl;
	return *this;
}

// Перегрузка операции присваивания с перемещением
const Plant& Plant::operator= (Plant&& other) noexcept { // Передаём ссылку на rvalue
	if (this != &other) {
		name = other.name;
		height = other.height;
		type_of_plant = other.type_of_plant;
	}
	std::cout << "Moving operation" << std::endl;
	return *this;
}

// Метод для вывода информации о растении
void Plant::display()
{
	std::cout << "Plant(Name: " << name
		<< ", Height: " << height << " cm"
		<< ", Type: " << type_of_plant << ")"
		<< std::endl;
}
