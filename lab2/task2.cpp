#include "plant.h"
#define N 10 //пожалуйста, не ставь меня меньше 9
#define M 6 //пожалуйста, не ставь меня меньше 3

Plant arr_plant(Plant& plant1, Plant plant2)
{
	std::cout << "\nвызов N конструкторов с параметрами" << std::endl;
	Plant shop_plant[N];

	std::cout << "\nоперация копирования" << std::endl;
	shop_plant[2] = plant1;

	std::cout << "\n создание экземпляра для суммы; операция перемещение и удаление экземпляра" << std::endl;
	shop_plant[6] = plant2 + plant1;

	std::cout << "\nвызов конструктора с параметрами, операции присваивания с перемещением, удаление экземпляра" << std::endl;
	shop_plant[8] = Plant("Aspen", 4, "Tree");

	std::cout << "\nвывод записей" << std::endl;
	for (int i = 0; i < N; i++)
	{
		shop_plant[i].display(); 
	}
	std::cout << "\nвызов конструктора копирования и удаление всех записей" << std::endl;
	return shop_plant[8];

	//вариант с возвратом типа ссылка на класс:
	//Plant &plant = shop_plant[8];
	//return plant;
	
}

int main() 
{
	setlocale(LC_ALL, "Russian");
	// Создание статического и динамического экцемпляра класса 
	std::cout << "step 1:\nсоздание двух экземпляров";
	Plant plant1("Rose", 2, "Flower");
	Plant* plant2 = new Plant("Oak", 5, "Tree");

	std::cout << "\nудаление динамического экземпляра" << std::endl;
	delete plant2;

	// Работа с вектором и передача экземпляров в функцию
	std::cout << "\nstep 2:\nсоздание ссылки" << std::endl;
	Plant& no_plant = plant1;
	arr_plant(no_plant, plant1).display();
	std::cout <<"после N вызовов деструктора, была вызвана функция display() для переданного из функции экземпляра класса" << std::endl;

	std::cout << "\nstep 3:\nvector" << std::endl;
	std::cout << "\nсоздание вектора из M объектов" << std::endl;
	std::vector<Plant> my_plants(M);

	std::cout << "\nlist\nсоздание списка из M объектов" << std::endl;
	std::list<Plant> other_plants(M);

	std::cout << "\nочень много копируем" << std::endl;
	other_plants.assign(2, my_plants[2] = Plant("Oak", 5, "Tree"));

	int i = 0;
	for (auto plant : other_plants)
	{
		std::cout << std::endl;
		std::cout << "сравнение типа plant1 > plant2" << std::endl;
		plant > my_plants[i];
		std::cout << "\nсравнение типа plant1 < plant2" << std::endl;
		plant < my_plants[i];
		std::cout << "\nсравнение типа plant1 != plant2" << std::endl;
		plant != my_plants[i];
		std::cout << "\nсравнение типа plant1 == plant2" << std::endl;
		plant == my_plants[i];
		i++;
	}

	std::cout << std::endl;
	return 0;
}