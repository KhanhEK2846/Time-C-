#pragma once
#include<iostream>
#include<ctime>
#include<time.h>
#pragma warning(disable:4996)
using namespace std;

class Clock
{
private:
	int year, month, day, hour, minute, second;
public:
	Clock();
	void LocalNow();
	void UTCNow();
	void CurrentSystem();
	void Adjust(int y, int m, int d, int h, int mi, int s);
	void Correct();
	void Output();
};

