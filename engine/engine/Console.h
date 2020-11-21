#pragma once
#include <iostream>
class Console
{
private:
	int WeatherTemperature;
public:
	int InitWeather()
	{
		std::cout << "insert weather temperature: ";
		int temperature;
		std::cin >> temperature;
		system("cls");
		return temperature;
	}
	void result(int time)
	{
		std::cout << "time until overheating is: " << time;
	}
};

