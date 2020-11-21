#pragma once
class Engine
{
protected:

	double I; // Момент инерции двигателя
	double M; // Крутящий момент
	double V; // Скорость вращения коленвала
	double Tp; // Температура перегрева
	double Td; // Температура двигателя
	double Hm;// Коэф. завис. скор. от крутящего момента
	double Hv; // нагрев от скорости вращения
	double C; // скорость охлаждения двиг от т. окруж среды
public:
	Engine()
	{
		I = 0;
		M = 0;
		V = 0;
		Tp = 0;
		Td = 0;
		Hm = 0;
		Hv = 0;
		C = 0;
	}
	Engine(double I, double Tp, double Td, double Hm, double Hv, double C)
	{
		this->I = I;
		
		this->Tp = Tp;
		this->Td = Td;
		this->Hm = Hm;
		this->C = C;
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

};

