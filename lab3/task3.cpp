#include <iostream>
#include "plant.h"
#include <vector>
#include <list>
#include <random>
#include <algorithm>
#include <numeric>
#include <ctime>

void printVector(std::vector<Plant> plant)
{
	for (int i = 0; i < plant.size(); i++)
	{
		std::cout << i + 1 << ". "; plant[i].display();
	}
}

void printList(std::list<Plant> plants)
{
	int i = 0;
	for (auto plant : plants)
	{
		std::cout << i + 1 << ". "; plant.display();
		i++;
	}
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");

	// Задача #1: Создать вектор v1 размером N

	//задание случайного значения N
	int N = rand() % 501 + 500;
	std::vector<Plant> v1(N);

	//вектора для генерирования значений
	std::string typePlant[6] = { "мох", "папоротник", "хвощ", "плаун", "голосеменное", "цветковое" };
	std::string namePlant[10] = { "Василёк", "Розалина", "Лилияна", "Иван-чай", "Геранина", "Дубрава", "Фиалис", "Камелия", "Вероника", "Ясмина" };

	//заполнение вектора значениями и вывод на экран
	std::cout << "Задача #1: Создать вектор v1 размером N" << std::endl;
	std::cout << "N = " << N << std::endl;
	for (int i = 0; i < N; i++)
	{
		v1[i].setHeight(rand() % 200);
		v1[i].setName(namePlant[rand() % 10]);
		v1[i].setType(typePlant[rand() % 6]);

		std::cout << i + 1 << ". "; v1[i].display();
	}

	// Задача #2: Создать вектор v2, поместив в него последние 200 элементов вектора v1
	std::cout << "\nЗадача #2: Создать вектор v2, поместив в него последние 200 элементов вектора v1" << std::endl;

	int b = N - 200, e = N;
	std::vector<Plant> v2(v1.begin() + b, v1.begin() + e);

	//вывод на экран
	printVector(v2);

	// Задача #3: Сформировать список list1, поместив в него первые n (от 20 до 50) наибольших элементов вектора v1
	std::cout << "\nЗадача #3: Сформировать список list1, поместив в него первые n (от 20 до 50) наибольших элементов вектора v1" << std::endl;

	std::vector<Plant> sorted_v1 = v1;
	std::sort(sorted_v1.begin(), sorted_v1.end(), 
		[](Plant& a, Plant& b) {return a > b; });

	int n = rand() % 31 + 20;
	std::list<Plant> list1(sorted_v1.begin(), sorted_v1.begin() + n);

	//вывод на экран
	std::cout << "n = " << n << std::endl;
	printList(list1);

	// Задача #4: Сформировать список list2, поместив в него последние n (от 20 до 50) наименьших элементов вектора v2
	std::cout << "\nЗадача #4: Сформировать список list2, поместив в него последние n (от 20 до 50) наименьших элементов вектора v2" << std::endl;

	n = rand() % 31 + 20;
	std::vector<Plant> temp(v2);
	std::partial_sort(temp.begin(), temp.begin() + n, temp.end());

	std::list<Plant> list2(temp.begin(), temp.begin() + n);

	//вывод на экран
	std::cout << "n = " << n << std::endl;
	printList(list2);

	// Задача #5: Удалить из векторов v1 и v2 перемещенные элементы
	std::cout << "\nЗадача #5: Удалить из векторов v1 и v2 перемещенные элементы" << std::endl;
	std::cout << "Элементов в v1: было: " << v1.size();
	v1.erase(std::remove_if(v1.begin(), v1.end(),
		[&list1](Plant& plant) {
			return std::find(list1.begin(), list1.end(), plant) != list1.end();
		}),
		v1.end());
	std::cout << ", стало: " << v1.size();

	std::cout << "\nЭлементов в v2: было: " << v2.size();
	v2.erase(std::remove_if(v2.begin(), v2.end(),
		[&list2](Plant& plant) {
			return std::find(list2.begin(), list2.end(), plant) != list2.end();
		}),
		v2.end());
	std::cout << ", стало: " << v2.size();

	//вывод на экран
	std::cout << "\nv1:\n";
	printVector(v1);
	std::cout << "\nv2:" << std::endl;
	printVector(v2);

	// Задача #6: Для списка list1 найти элемент со средним значением. Перегруппировать элементы списка (не имеет смысла)
	std::cout << "\nЗадача #6: Для списка list1 найти элемент со средним значением. Перегруппировать элементы списка" << std::endl;

	float totalHeight = std::accumulate(
		list1.begin(), list1.end(), 0.0f,
		[](float sum, Plant& plant) {
			return sum + plant.getHeight();
		});
	float averageHeight = totalHeight / list1.size();

	std::cout << "Среднее значение высоты: " << averageHeight << "\n";

	auto isGreaterThanAverage = [averageHeight](Plant& plant) {
		return plant.getHeight() > averageHeight;
		};
	list1.sort([isGreaterThanAverage](Plant& a, Plant& b) {
		return isGreaterThanAverage(a) && !isGreaterThanAverage(b);
		});

	//вывод на экран
	std::cout << "\nПерегруппировка элементов списка (не имеет смысла):" << std::endl;
	printList(list1);

	// Задача #7: Удалить из списка list2 все цветковые растения с именем длиннее 6 символов
	std::cout << "\nЗадача #7: Удалить из списка list2 все цветковые растения с именем дленнее 6 символов" << std::endl;

	list2.remove_if([](Plant& plant) {
		return plant.getType() == "цветковое" && plant.getName().length() > 6;
		});

	//вывод на экран
	printList(list2);

	// Задача #8: Создать вектор v3 из элементов, которые присутствуют и в векторе v1, и в векторе v2
	std::cout << "\nЗадача #8: Создать вектор v3 из элементов, которые присутствуют и в векторе v1, и в векторе v2" << std::endl;

	std::vector<Plant> v3;
	std::copy_if(v2.begin(), v2.end(), std::back_inserter(v3), [&v1](Plant& plant) {
		return std::find(v1.begin(), v1.end(), plant) != v1.end();
		});

	//вывод на экран
	std::cout << "Размер вектора v3: " << v3.size() << ", размер вектора v2: " << v2.size() << std::endl;
	printVector(v3);

	// Задача #9: Для списков list1 и list2 из списка с большим числом элементов удалить первые n так, чтобы оба списка имели бы 
	// одинаковый размер. Сформировать из них список list3, который будет хранить пары
	std::cout << "\nЗадача #9: Для списков list1 и list2 из списка с большим числом элементов удалите первые n так, чтобы оба списка имели бы "
		"одинаковый размер.Сформируйте из них список list3, который будет хранить пары" << std::endl;

	if (list1.size() > list2.size()) {
		list1.resize(list2.size());
	}
	else if (list2.size() > list1.size()) {
		list2.resize(list1.size());
	}

	std::list<std::pair<Plant, Plant>> list3;
	std::transform(
		list1.begin(), list1.end(),
		list2.begin(),
		std::back_inserter(list3),
		[](Plant& a, Plant& b) {
			return std::make_pair(a, b);
		});

	//вывод на экран
	int i = 0;
	for (auto plant : list3)
	{
		std::cout << i + 1 << ". "; plant.first.display();  plant.second.display();
		i++;
	}

	// Задача #10: Решить предыдущую задачу для векторов v1 и v2 без предварительного приведения векторов к одному размеру. Пар с пустыми значениями быть не должно.
	std::cout << "\nЗадача #10: Решить предыдущую задачу для векторов v1 и v2 без предварительного приведения векторов к одному размеру. Пар с пустыми значениями быть не должно." << std::endl;

	std::vector<std::pair<Plant, Plant>> merged(v2.size());
	std::transform(v1.begin(), v1.begin() + v2.size(), v2.begin(), merged.begin(),
		[](Plant& p1, Plant& p2) {
			return std::make_pair(p1, p2); // Формируем пару
		});

	for (int i = 0; i < merged.size(); i++)
	{
		std::cout << i + 1 << ". "; merged[i].first.display(); merged[i].second.display();
	}
}
