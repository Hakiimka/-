#include <iostream>
#include "CarEngine.h"
#include "TestBench.h"
#include "Console.h"

int main()
{
    CarEngine test(0.1, 110, 20, 0.01, 0.0001, 0.1);
    CarTestBench test2;
    Console test3;
    int weather;
        weather= test3.InitWeather();
  std::cout << test.MakeCountOfVc(weather,20) << " " << test.MakeCountOfVH();
   
    
    test3.result((test2.BeginTest(test, weather)));
}

