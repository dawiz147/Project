#pragma once
#include "TimeEvent.h"
#include "Channel.h"
using namespace std;
#include <iostream>
#include "BaseStation.h"
class CheckingChannel :public TimeEvent
{
public:
	CheckingChannel(double time,bool first, Channel* channel,BaseStation* base);
	void Execute();
	void Print();
	double GetTime();
private:
	TimeEvent* next_;
	const double KDifs = 2;
	double time_;
	bool first_;
	Channel* channel_;
	BaseStation* base_;
	Package* package_;
};

