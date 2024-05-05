// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream> 
#include <set>
using namespace std;
#include "ConsoleApplication1.h"
#include <algorithm>

int main()
{
	//устанавливаем русский язык в консоль и вводим переменные и наше множество
	setlocale(LC_ALL, "Russian");

	int k = 0;
	int input;
	int power = 16;
	int min, max;

	set<int> setA, setB, setC, setD, setE, tempres,tempres1, result;

	bool exit=false;
	bool generated = false;

	// Возвращает псевдослучайное число из диапазона [min, max)
	

	///////////////////////////////////////////////////////////////
	
	
	while (exit==false)
	{
		//рисуем менюшку
		printf("\nВыберите пункт меню\n\n");
		printf("1.Заполнить множества вручную\n");
		printf("2.Сгенерировать случайные набор 16 чисел\n");
		printf("3.Выход\n");
		printf("4.Вывести множества\n\n");
		printf("5.Запустить машину судного дня.\n");
	
		cin >> input;
		cout << endl;

		//обрабатываем введёный пункт
		
		switch (input) {
		
		case 1: //вводим множество ручками
		{
			printf("Множество A: ");
			for (; k < power; k++)
			{
				int t;
				std::cin >> t;
				setA.insert(t);
			}
			printf("\n");

			printf("Множество B: ");
			for (; k < power; k++)
			{
				int t;
				std::cin >> t;
				setB.insert(t);
			}
			printf("\n");

			printf("Множество C: ");
			for (; k < power; k++)
			{
				int t;
				std::cin >> t;
				setC.insert(t);
			}
			printf("\n");

			printf("Множество D: ");
			for (; k < power; k++)
			{
				int t;
				std::cin >> t;
				setD.insert(t);
			}
			printf("\n");

			printf("Множество E: ");
			for (; k < power; k++)
			{
				int t;
				std::cin >> t;
				setE.insert(t);
			}
			printf("\n");

			break;
			
		}
		case 2: //используем великий рандом
		{
			printf("Введите диапозон:\n");
			printf("Минимальное значение - ");
			std::cin >> min;

			printf("\nМаксимальное значение - ");
			std::cin >> max;
			std::cout << std::endl;

			for (; k < power; k++)
			{
				int t;
				t = Random(min,max);
				setA.insert(t);
			}
			

			
			for (k=0; k < power; k++)
			{
				int t;
				t = Random(min, max);
				setB.insert(t);
			}
			

			
			for (k=0; k < power; k++)
			{
				int t;
				t = Random(min, max);
				setC.insert(t);
			}
			

			
			for (k=0; k < power; k++)
			{
				int t;
				t = Random(min, max);
				setD.insert(t);
			}
			

			
			for (k=0; k < power; k++)
			{
				int t;
				t = Random(min, max);
				setE.insert(t);
			}
			
			generated = true;
			printf("Множества сгенерированны!\n");
		}
		break;
		case 3: //просто сразу выходим из программы
		{
			exit = true;
			
		}
		case 4: //выводим множества на экран
		{
			
			cout << endl;
			
				printf("Полученные множества:\n");
				printf("A:");
				for (auto& item : setA)
				{
					cout << item;
					cout << " ";
					
				}
				cout << endl;

				printf("B:");
				for (auto& item : setB)
				{
					cout << item;
					cout << " ";
				}
				cout << endl;

				printf("C:");
				for (auto& item : setC)
				{
					cout << item;
					cout << " ";
				}
				cout << endl;

				printf("D:");
				for (auto& item : setD)
				{
					cout << item;
					cout << " ";
				}
				cout << endl;

				printf("E:");
				for (auto& item : setE)
				{
					cout << item;
					cout << " ";
				}
				cout << endl;
				break;
			
			
			
		}
		case 5:
			if (generated == true) {
				printf("Началось...\n\n");
				//A ∪ B ⊕ C \ D \ E
				set_union(setA.begin(), setA.end(), setB.begin(), setB.end(), inserter(tempres, tempres.begin()));
				set_symmetric_difference(tempres.begin(), tempres.end(), setC.begin(), setC.end(), inserter(tempres1, tempres1.begin()));
				set_difference(tempres.begin(), tempres.end(), setD.begin(), setD.end(), inserter(tempres, tempres.begin()));
				set_difference(tempres1.begin(), tempres1.end(), setE.begin(), setE.end(), inserter(result, result.begin()));

				printf("Полученное множество:\n\n");
				printf("Результат (убил):\n");
				for (auto& item : result)
				{
					cout << item;
					cout << " ";

				}
				cout << endl;
			}
			else
			{
				printf("Не-а, вы не можете запустить машину судного дня без генерации векторов");
			}
			

		default://если кто-то решил поумничать и ввести то, чего в пунктах нет
			
			printf("Выберите одну из доступных опций.\n");
			break;
		}
	}
	

}


