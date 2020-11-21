#include "CarEngine.h"
#define ABSOLUTE_ERROR 10e-2

class CarTestBench 
{
private:
	int Time;
	int index;
public:
	CarTestBench()
	{
		Time = 0;
		index = 0;
	}
	void setTime(int Time)
	{
		this->Time = Time;
	}
	int getTime()
	{
		return Time;
	}

	int BeginTest(CarEngine &engine,int Temperature)
	{

		double a = engine.getM() * engine.getI(); // ускорение
		double temper = engine.getTp() - engine.getTd(); // сравнение температуры двигатели и температуры перегрева
		while (temper<= 110 && Time < 600)
		{
				Time++;
				double v = engine.getV();
				v += a;
				
				int n = engine.getn();
				int* tempM = new int[n];
				int* tempV= new int [n];
				tempM = engine.getStartM();
				tempV = engine.getStartV();
				if (index < n - 2)
				{
					index += v < tempV[index + 1] ? 0 : 1;
				}
				double up = v - tempV[index];
				double down = tempV[index + 1] - tempV[index];
				double factor = tempM[index + 1] - tempM[index];
				double m = engine.getM();
				m = up / down * factor + tempM[index];
				double engineT = engine.getTd();
				engineT += engine.MakeCountOfVc(Temperature, engineT) + engine.MakeCountOfVH();
				a = engine.getTp() - engineT;
				temper = engine.getTp() - engineT;
		}
		return Time;
	}
};

