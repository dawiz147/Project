#ifndef CHECKINGCHANNEL_H
#define CHECKINGCHANNEL_H
#include "TimeEvent.h"
#include "Channel.h"
using namespace std;
#include <iostream>
#include "WirelessNetwork.h"
#include "ConditionalEvent.h"
class CheckingChannel :public TimeEvent
{
public:
	CheckingChannel(double time, bool first, WirelessNetwork* network, int id_base_station, ConditionalEvent* conditional, int counter);
	void Execute();
	void Print();
	double GetTime();
private:
	int counter_;
	TimeEvent* next_;
	const double KDifs = 2;
	double time_;
	bool first_;
	Channel* channel_;
	WirelessNetwork* network_;
	ConditionalEvent* conditional_;
	int id_base_station_;
};
#endif
