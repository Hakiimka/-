#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Strelka.h"
using namespace std;

class AutoPark
{
	
	int n= getN(n); // ���������� �������� �� ���������� �����
	struct Car {
		string b_date; // ��� �������
		string creator; // �������������
		string car_model; // ������ ����
		string body_type; // ��� ������
	};
	
	Car* park = new Car[n];
	
	
public:
	AutoPark()
	{
	
	} 
	Car FileWrite(Car* park) // ������� ��� ������ ����� � ����
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
	Car FileRead(Car* park) // ���������� �����
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
    void CurrentCars(Car* park) // ���� ������� ������ ����(����� � ������)
	{
		for (int i = 0; i < n; i++)
		{
			cout << i + 1 << ". ";
			cout << park[i].creator << " " << park[i].car_model << endl;
		}
		cout << endl;
	}
	void ShowCarInfo(Car car) // ������� ���������� �� ���������� ����
	{ 
		cout << "-------------------------------------" << endl;
		cout << "����� ����: " <<car.creator << endl;
		cout << "������: "<<car.car_model << endl;
		cout << "��� ������: "<<car.body_type << endl;
		cout << "��� �������: "<<car.b_date << endl;
		cout << "-------------------------------------" << endl;
	}
	void RedCarInfo() // ������� ��� ��������� ����������
	{
		cout << "1. ����� ���� " << endl;
		cout << "2. ������ " << endl;
		cout << "3. ��� ������ " << endl;
		cout << "4. ��� ������� " <<endl;
	}
	Car* addCar(Car* car, int& n) // ���������� ���� � ������
	{
		Car* temp = new Car[n + 1];
		for (int i = 0; i < n; i++)
			temp[i] = car[i];
		delete[] car;

		cout << "������� ����� ����: ";
		cin >> temp[n].creator;
		cout << "������� ������ ����: ";
		cin >> temp[n].car_model;
		cout << "������� ��� ������: ";
		cin >> temp[n].body_type;
		cout << "��� �������: ";
		cin >> temp[n].b_date;
		n += 1;
		return temp;
	}
	Car* deleteCar(Car* car, int& n, int number) // ������� �������� ���� �� ������
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
	int Menu() // �������� ������� ����
	{
		
		for (int i = 0; i < n; i++) // ������ �������� ������������ �� ����� ��� ���������� ������
		{
			FileRead(park);
		}
		system("chcp 1251");
		while (true)
		{
			int ch = 1;
			showArrow(ch);
			system("cls");
			cout << "�������� ��������(����������� �� ����������. Enter - �������) " << endl;
			{
				cout << "\t1. �������� ������ ����������� � ����������� " << endl;
				cout << "\t2. �������� ���������� � ������ " << endl;
				cout << "\t3. ������� ���������� �� ������ " << endl;
				cout << "\t4. ������������� ���������� �� ����������" << endl;
				cout << "\t5. ��������� ��������� ���������" << endl;
				cout << "\t6. ����� " << endl;
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
							cout << "������� Enter,����� ����������";
							cin.get();
							break;
						case 2: {
							park = addCar(park, n);
							cout << endl;
							cout << "���� ������� ���������";
							Sleep(1000);
							FileWrite(park);
							break;
						}
						case 3: {
							CurrentCars(park);
							cout << "������� ���������� ����� ����,������� �� ������ ������ �� �����������: "; // 0 1 2 3 4 | n=5
							int x;
							cin >> x;
							if (x <= n)
							{
								park = deleteCar(park, n, x);
								cout << endl;
								cout << "���� ������� �������";
								Sleep(1000);
								FileWrite(park);
								break;
							}
							else
							{
								cout << "�������� �����";
								Sleep(1000);
								break;
							}
						}
						case 4: {
							CurrentCars(park);
							cout << "������� ���������� ����� ����,� ������� �� ������ �������� ����������: ";
							int x;
							cin >> x;
							if (x <= n)
							{
								system("cls");
								ShowCarInfo(park[x - 1]);
								cout << endl;
								RedCarInfo();
								cout << endl;
								cout << "��� ������ �� ������ ��������? ";
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
									case 1: cout << "��������� ����� ����: "; cin >> park[x - 1].creator; break;
									case 2: cout << "��������� ������ ����: "; cin >> park[x - 1].car_model; break;
									case 3: cout << "��������� ���� ������: "; cin >> park[x - 1].body_type; break;
									case 4: cout << "��������� ���� �������: "; cin >> park[x - 1].b_date; break;
									default: cout << "�� ������� �������� ��������";
									}
									cout << endl; cout << "�� ������ �������� ���-�� ���? (Y- ��) (N - ���) ";
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
								cout << "������(�������� �����)";
								Sleep(1000);
							}
					         break;
						}
						case 5: FileWrite(park); cout << endl; cout << "������ ������� ��������� "; Sleep(1000); break;  // ������ � ����
						case 6:FileWrite(park); return 0; break;
						default:cout << "�� ������ �����" << endl;
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

