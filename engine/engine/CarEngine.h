#include "Engine.h"
#include <iostream>
#pragma once
class CarEngine : Engine
{
private:
	int n=6;
	int* startM = new int[n] { 20, 75, 100, 105, 75, 0 };
	int* startV= new int[n] { 0, 75, 150, 200, 250, 300 };
	
public:


	CarEngine()
	{
		n = 6;
		M = startM[0];
		V = startV[0];
		
	}
	CarEngine(double I, double Tp, double Td, double Hm, double Hv, double C)
	{
		this->I = I;
		this->M = M;
		this->V = V;
		this->Tp = Tp;
		this->Td = Td;
		this->Hm = Hm;
		this->C = C;
		M = startM[0];
		V = startV[0];
	}
	double getI()
	{
		return I;
	}
	double getM()
	{
		return M;
	}
	double getV()
	{
		return V;
	}
	double getTp()
	{
		return Tp;
	}
	double getTd()
	{
		return Td;
	}
	double getHm()
	{
		return Hm;
	}
	double getC()
	{
		return C;
	}
	int getStartM(int index)
	{
		return startM[index];
	}
	int* getStartM()
	{
		return startM;
	}
	int* getStartV()
	{
		return startV;
	}
	int getStartV(int index)
	{
		return startV[index];
	}
	void setI(int I)
	{
		this->I = I;
	}
	void setM(int M)
	{
		this->M = M;
	}
	void setV(int V)
	{
		this->V = V;
	}
	void setTp(int Tp)
	{
		this->Tp = Tp;
	}
	void setTd(int Td)
	{
		this->Td = Td;
	}
	void setHm(int Hm)
	{
		this->Hm = Hm;
	}
	void setC(int C)
	{
		this->C = C;
	}
	int getn()
	{
		return n;
	}

	double  MakeCountOfVH() // Вычитание скорости нагрева ДВС
	{
		return M * Hm + V * V * Hv;
	}
	double MakeCountOfVc(double Ts,double Td) // Вычитание скорости охлаждения
	{
		 return C * (Ts - Td);
	}
};

