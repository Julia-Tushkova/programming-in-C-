#include "plant.h"

// ����������� ��� ����������
Plant::Plant() : name("def"), height(0), type_of_plant("def") {
	std::cout << "Constructor without parameters" << std::endl;
}

// ����������� � �����������
Plant::Plant(std::string name, int height, std::string type_of_plant)
	: name(name), height(height), type_of_plant(type_of_plant) {
	std::cout << "Constructor with parameters" << std::endl;
}

// ����������� �����������
Plant::Plant(const Plant& other) {
	name = other.name;
	height = other.height;
	type_of_plant = other.type_of_plant;
	std::cout << "Copy constructor" << std::endl;
}

// ����������
Plant::~Plant()
{
	height = -1;
	std::cout << "Destructor" << std::endl;
}

// ���������� ��������� ��������
Plant Plant::operator+(const Plant& other)
{
	std::string new_name = name + " & " + other.name;
	int new_height = height + other.height;
	std::string new_type_of_plant = type_of_plant + "/" + other.type_of_plant;
	return Plant(new_name, new_height, new_type_of_plant);
}

// ���������� ��������� ���������
bool Plant::operator>(const Plant& other)
{
	std::cout << "operation>" << std::endl;
	if (height > other.height) return true;
	return false;
}

// ���������� ��������� ���������
bool Plant::operator<(const Plant& other)
{
	std::cout << "operation<" << std::endl;
	if (height < other.height) return true;
	return false;
}

// ���������� ��������� ���������
bool Plant::operator==(const Plant& other)
{
	std::cout << "operation==" << std::endl;
	if (height == other.height && name
		== other.name && type_of_plant
		== other.type_of_plant) return true;
	return false;
}

// ���������� ��������� ���������
bool Plant::operator!=(const Plant& other)
{
	std::cout << "operation!=" << std::endl;
	return !(*this == other);
}

// ���������� �������� ������������ ��� �����������
const Plant& Plant::operator= (const Plant& other) { // ������� ������ �� lvalue
	if (this != &other) {
		name = other.name;
		height = other.height;
		type_of_plant = other.type_of_plant;
	}
	std::cout << "Copy operation" << std::endl;
	return *this;
}

// ���������� �������� ������������ � ������������
const Plant& Plant::operator= (Plant&& other) noexcept { // ������� ������ �� rvalue
	if (this != &other) {
		name = other.name;
		height = other.height;
		type_of_plant = other.type_of_plant;
	}
	std::cout << "Moving operation" << std::endl;
	return *this;
}

// ����� ��� ������ ���������� � ��������
void Plant::display()
{
	std::cout << "Plant(Name: " << name
		<< ", Height: " << height << " cm"
		<< ", Type: " << type_of_plant << ")"
		<< std::endl;
}
