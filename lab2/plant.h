#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
class Plant
{
	std::string name; // Название растения
	std::string type_of_plant; // Тип растения (например, "дерево", "цветок")  что-то из этого нужно сделать массивом
	int height; // Высота растения в сантиметрах

public:

	// Конструктор без параметров
	Plant();

	// Конструктор с параметрами
	Plant(std::string name, int height, std::string type_of_plant);

	// Конструктор копирования
	Plant(const Plant& other);

	// Деструктор
	~Plant();

	// Перегрузка оператора сложения
	Plant operator+(const Plant& other);

	// Перегрузка оператора сравнения
	bool operator>(const Plant& other);

	// Перегрузка оператора сравнения
	bool operator<(const Plant& other);

	// Перегрузка оператора сравнения
	bool operator==(const Plant& other);

	// Перегрузка оператора сравнения
	bool operator!=(const Plant& other);

	// Перегрузка операции присваивания без перемещения
	const Plant& operator= (const Plant& other);

	// Перегрузка операции присваивания с перемещением
	const Plant& operator=(Plant&& other) noexcept;

	// Метод для вывода информации о растении
	void display();
};
