#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <list>
class Plant
{
	std::string name; // �������� ��������
	std::string typeOfPlant; // ��� �������� (��������, "������", "������")  ���-�� �� ����� ����� ������� ��������
	int height; // ������ �������� � �����������

public:

	// ����������� ��� ����������
	Plant();

	// ����������� � �����������
	Plant(std::string name, int height, std::string typeOfPlant);

	// ����������� �����������
	Plant(const Plant& other);

	// ����������
	~Plant();

	// ������ name
	void setName(std::string newName);

	// ������ type
	void setType(std::string newType);

	// ������ height
	void setHeight(int newHeight);

	// ����������� �������� name
	std::string getName();

	// ����������� �������� type
	std::string getType();

	// ����������� �������� height
	int getHeight();

	// ���������� ��������� ��������
	Plant operator+(const Plant& other);

	// ���������� ��������� ���������
	bool operator>(const Plant& other);

	// ���������� ��������� ���������
	bool operator<(const Plant& other);

	// ���������� ��������� ���������
	bool operator==(const Plant& other);

	// ���������� ��������� ���������
	bool operator!=(const Plant& other);

	// ���������� �������� ������������ ��� �����������
	const Plant& operator= (const Plant& other);

	// ���������� �������� ������������ � ������������
	const Plant& operator=(Plant&& other) noexcept;

	// ����� ��� ������ ���������� � ��������
	void display();
};