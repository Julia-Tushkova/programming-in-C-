#include "plant.h"

// ����������� ��� ����������
Plant::Plant() : name("def"), height(0), typeOfPlant("def") {
}

// ����������� � �����������
Plant::Plant(std::string name, int height, std::string typeOfPlant)
	: name(name), height(height), typeOfPlant(typeOfPlant) {
}

// ����������� �����������
Plant::Plant(const Plant& other) {
	name = other.name;
	height = other.height;
	typeOfPlant = other.typeOfPlant;
}

// ����������
Plant::~Plant()
{
	height = -1;
}

// ���������� ��������� ��������
Plant Plant::operator+(const Plant& other)
{
	std::string new_name = name + " & " + other.name;
	int new_height = height + other.height;
	std::string new_typeOfPlant = typeOfPlant + "/" + other.typeOfPlant;
	return Plant(new_name, new_height, new_typeOfPlant);
}

// ���������� ��������� ���������
bool Plant::operator>(const Plant& other)
{
	if (height > other.height) return true;
	return false;
}

// ���������� ��������� ���������
bool Plant::operator<(const Plant& other)
{
	if (height < other.height) return true;
	return false;
}

// ���������� ��������� ���������
bool Plant::operator==(const Plant& other)
{
	if (height == other.height && name
		== other.name && typeOfPlant
		== other.typeOfPlant) return true;
	return false;
}

// ���������� ��������� ���������
bool Plant::operator!=(const Plant& other)
{
	return !(*this == other);
}

// ���������� �������� ������������ ��� �����������
const Plant& Plant::operator= (const Plant& other) { // ������� ������ �� lvalue
	if (this != &other) {
		name = other.name;
		height = other.height;
		typeOfPlant = other.typeOfPlant;
	}
	return *this;
}

// ���������� �������� ������������ � ������������
const Plant& Plant::operator= (Plant&& other) noexcept { // ������� ������ �� rvalue
	if (this != &other) {
		name = other.name;
		height = other.height;
		typeOfPlant = other.typeOfPlant;
	}
	return *this;
}

// ����� ��� ������ ���������� � ��������
void Plant::display()
{
	std::cout << "���: " << name
		<< ", ������: " << height << " cm"
		<< ", ���: " << typeOfPlant << std::endl;
}

// ������ name
void Plant::setName(std::string newName)
{
	name = newName;
}

// ������ type
void Plant::setType(std::string newType)
{
	typeOfPlant = newType;
}

// ������ height
void Plant::setHeight(int newHeight)
{
	height = newHeight;
}

// ����������� �������� name
std::string Plant::getName()
{
	return name;
}

// ����������� �������� type
std::string Plant::getType()
{
	return typeOfPlant;
}

// ����������� �������� height
int Plant::getHeight()
{
	return height;
}