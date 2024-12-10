#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
class Plant
{
	std::string name; // Название растения
	std::string typeOfPlant; // Тип растения (например, "дерево", "цветок")  что-то из этого нужно сделать массивом
	int height; // Высота растения в сантиметрах

public:

	// Конструктор без параметров
	Plant();

	// Конструктор с параметрами
	Plant(std::string name, int height, std::string typeOfPlant);

	// Конструктор копирования
	Plant(const Plant& other);

	// Деструктор
	~Plant();

	// Запись name
	void setName(std::string newName);

	// Запись type
	void setType(std::string newType);

	// Запись height
	void setHeight(int newHeight);

	// Возвращение значения name
	std::string getName();

	// Возвращение значения type
	std::string getType();

	// Возвращение значения height
	int getHeight();

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