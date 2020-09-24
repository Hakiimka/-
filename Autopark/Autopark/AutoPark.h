#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Strelka.h"
using namespace std;

class AutoPark
{
	
	int n= getN(n); // считывание значение из текстового файла
	struct Car {
		string b_date; // год выпуска
		string creator; // производитель
		string car_model; // модель авто
		string body_type; // тип кузова
	};
	
	Car* park = new Car[n];
	
	
public:
	AutoPark()
	{
	
	} 
	Car FileWrite(Car* park) // Функция для записи машин в файл
	{
		ofstream file;
		file.open("cars.txt");
		file << n << endl;
		for (int i = 0; i < n; i++)
		{
			file << park[i].creator << endl;
			file << park[i].car_model << endl;
			file << park[i].body_type << endl;
			file << park[i].b_date << endl;
		}
		file.close();
		return*park;
	}
	int getN(int n)
	{
		ifstream file;
		file.open("cars.txt");
		file >> n;
		return n;
	}
	Car FileRead(Car* park) // считывание файла
	{
		ifstream file;
		file.open("cars.txt");
		file >> n;
		for (int i = 0; i < n; i++)
		{
			file >> park[i].creator;
			file >> park[i].car_model;
			file >> park[i].body_type;
			file >> park[i].b_date;
		}
		file.close();
		return*park;
	}
	Car getCar(Car car)
	{
		return car;
	}

	void show(Car car)
	{
		cout << car.creator << " " << car.car_model << endl;
	}
    void CurrentCars(Car* park) // Весь текущий список авто(марка и модель)
	{
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << ". ";
			cout << park[i].creator << " " << park[i].car_model << endl;
		}
		cout << endl;
	}
	void ShowCarInfo(Car car) // Вывести информацию об конкретном авто
	{ 
		cout << "-------------------------------------" << endl;
		cout << "Марка авто: " <<car.creator << endl;
		cout << "Модель: "<<car.car_model << endl;
		cout << "Тип кузова: "<<car.body_type << endl;
		cout << "Год выпуска: "<<car.b_date << endl;
		cout << "-------------------------------------" << endl;
	}
	void RedCarInfo() // Подменю для изменения информации
	{
		cout << "1. Марка авто " << endl;
		cout << "2. Модель " << endl;
		cout << "3. Тип кузова " << endl;
		cout << "4. Год выпуска " <<endl;
	}
	Car* addCar(Car* car, int& n) // Добавление авто в список
	{
		Car* temp = new Car[n + 1];
		for (int i = 0; i < n; i++)
			temp[i] = car[i];
		delete[] car;

		cout << "Укажите марку авто: ";
		cin >> temp[n].creator;
		cout << "Укажите модель авто: ";
		cin >> temp[n].car_model;
		cout << "Введите тип кузова: ";
		cin >> temp[n].body_type;
		cout << "Год выпуска: ";
		cin >> temp[n].b_date;
		n += 1;
		return temp;
	}
	Car* deleteCar(Car* car, int& n, int number) // Функция удаления авто из списка
	{
		
		Car* temp = new Car[n];
		if (number == n)
		{
			for (int i = 0; i < number; i++)
				temp[i] = car[i];
			n -= 1;
			delete[]car;
			return temp;
		}
		else
		for (int i = 0; i < number; i++)
			temp[i] = car[i];
		for (int i = number; i < n; i++)
		{
			temp[i - 1] = car[i];
		}
		n -= 1;
		delete[] car;
		return temp;
	}
	int Menu() // основная функция меню
	{
		
		for (int i = 0; i < n; i++) // массив структур подргужается из файла для дальнейшей работы
		{
			FileRead(park);
		}
		system("chcp 1251");
		while (true)
		{
			int ch = 1;
			showArrow(ch);
			system("cls");
			cout << "Выберите действие(Стрелочками на клавиатуре. Enter - выбрать) " << endl;
			{
				cout << "\t1. Показать список автомобилей в справочнике " << endl;
				cout << "\t2. Добавить автомобиль в список " << endl;
				cout << "\t3. Удалить автомобиль из списка " << endl;
				cout << "\t4. Редактировать информацию об автомобиле" << endl;
				cout << "\t5. Сохранить внесенные изменения" << endl;
				cout << "\t6. Выход " << endl;
				cout << endl;
			}
			while (true)
			{
				if (_kbhit())
				{
					int key = _getch();
					if (key == 72)
					{
						ch--;
						if (ch == 0)
							ch = 6;
						showArrow(ch);
					}
					if (key == 80) {
						ch++;
						if (ch == 7)
							ch = 1;
						showArrow(ch);
					}

					if (key == 13)
					{
						system("cls");
						switch (ch)
						{
						case 1:
						{
							for (int i = 0; i < n; i++)
							{
								ShowCarInfo(park[i]);
							}
							cout << endl;
							cout << "Нажмите Enter,чтобы продолжить";
							cin.get();
							break;
						case 2: {
							park = addCar(park, n);
							cout << endl;
							cout << "Авто успешно добавлено";
							Sleep(1000);
							FileWrite(park);
							break;
						}
						case 3: {
							CurrentCars(park);
							cout << "Введите порядковый номер авто,которое вы хотите убрать из справочника: "; // 0 1 2 3 4 | n=5
							int x;
							cin >> x;
							if (x <= n)
							{
								park = deleteCar(park, n, x);
								cout << endl;
								cout << "Авто успешно удалено";
								Sleep(1000);
								FileWrite(park);
								break;
							}
							else
							{
								cout << "Неверный номер";
								Sleep(1000);
								break;
							}
						}
						case 4: {
							CurrentCars(park);
							cout << "Введите порядковый номер авто,о котором вы хотите изменить информацию: ";
							int x;
							cin >> x;
							if (x <= n)
							{
								system("cls");
								ShowCarInfo(park[x - 1]);
								cout << endl;
								RedCarInfo();
								cout << endl;
								cout << "Что именно вы хотите изменить? ";
								int info;
								bool change = false;
								while (change == false)
								{
									system("cls");
									ShowCarInfo(park[x - 1]);
									RedCarInfo();
									cin >> info;
									switch (info)
									{
									case 1: cout << "Изменение марки авто: "; cin >> park[x - 1].creator; break;
									case 2: cout << "Изменение модели авто: "; cin >> park[x - 1].car_model; break;
									case 3: cout << "Изменение типа кузова: "; cin >> park[x - 1].body_type; break;
									case 4: cout << "Изменение года выпуска: "; cin >> park[x - 1].b_date; break;
									default: cout << "Вы выбрали неверное действие";
									}
									cout << endl; cout << "Вы хотите изменить что-то еще? (Y- да) (N - нет) ";
									char a;
									cin >> a;
									if (a == 'y' || a == 'Y')
										change = false;
									else if (a == 'n' || a == 'N')
										change = true;
								}
							}
							else
							{
								cout << "Ошибка(Неверный номер)";
								Sleep(1000);
							}
					         break;
						}
						case 5: FileWrite(park); cout << endl; cout << "Данные успешно сохранены "; Sleep(1000); break;  // запись в файл
						case 6:FileWrite(park); return 0; break;
						default:cout << "Не верный пункт" << endl;
							cin.get();
						}
						}
						break;
					}
					
				}
			}
		}
	}
	
	
};

