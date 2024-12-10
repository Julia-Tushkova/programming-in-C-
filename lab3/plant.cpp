#include "plant.h"

// Конструктор без параметров
Plant::Plant() : name("def"), height(0), typeOfPlant("def") {
}

// Конструктор с параметрами
Plant::Plant(std::string name, int height, std::string typeOfPlant)
	: name(name), height(height), typeOfPlant(typeOfPlant) {
}

// Конструктор копирования
Plant::Plant(const Plant& other) {
	name = other.name;
	height = other.height;
	typeOfPlant = other.typeOfPlant;
}

// Деструктор
Plant::~Plant()
{
	height = -1;
}

// Перегрузка оператора сложения
Plant Plant::operator+(const Plant& other)
{
	std::string new_name = name + " & " + other.name;
	int new_height = height + other.height;
	std::string new_typeOfPlant = typeOfPlant + "/" + other.typeOfPlant;
	return Plant(new_name, new_height, new_typeOfPlant);
}

// Перегрузка оператора сравнения
bool Plant::operator>(const Plant& other)
{
	if (height > other.height) return true;
	return false;
}

// Перегрузка оператора сравнения
bool Plant::operator<(const Plant& other)
{
	if (height < other.height) return true;
	return false;
}

// Перегрузка оператора сравнения
bool Plant::operator==(const Plant& other)
{
	if (height == other.height && name
		== other.name && typeOfPlant
		== other.typeOfPlant) return true;
	return false;
}

// Перегрузка оператора сравнения
bool Plant::operator!=(const Plant& other)
{
	return !(*this == other);
}

// Перегрузка операции присваивания без перемещения
const Plant& Plant::operator= (const Plant& other) { // Передаём ссылку на lvalue
	if (this != &other) {
		name = other.name;
		height = other.height;
		typeOfPlant = other.typeOfPlant;
	}
	return *this;
}

// Перегрузка операции присваивания с перемещением
const Plant& Plant::operator= (Plant&& other) noexcept { // Передаём ссылку на rvalue
	if (this != &other) {
		name = other.name;
		height = other.height;
		typeOfPlant = other.typeOfPlant;
	}
	return *this;
}

// Метод для вывода информации о растении
void Plant::display()
{
	std::cout << "Имя: " << name
		<< ", высота: " << height << " cm"
		<< ", тип: " << typeOfPlant << std::endl;
}

// Запись name
void Plant::setName(std::string newName)
{
	name = newName;
}

// Запись type
void Plant::setType(std::string newType)
{
	typeOfPlant = newType;
}

// Запись height
void Plant::setHeight(int newHeight)
{
	height = newHeight;
}

// Возвращение значения name
std::string Plant::getName()
{
	return name;
}

// Возвращение значения type
std::string Plant::getType()
{
	return typeOfPlant;
}

// Возвращение значения height
int Plant::getHeight()
{
	return height;
}