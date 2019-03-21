// depth-net.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Net.h"

int main()
{
	std::vector<double> i = {1,2,3,4,5};
	Net netw(i);
	netw.Study(10, stdKoffLearn);
}
