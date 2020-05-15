#ifndef CHECKINGCHANNEL_H
#define CHECKINGCHANNEL_H
#include "TimeEvent.h"
#include "Channel.h"
using namespace std;
#include <iostream>
#include "WirelessNetwork.h"
#include "TimeEventList.h"

class CheckingChannel :public TimeEvent
{
public:
	CheckingChannel(double time, WirelessNetwork* network, int id_base_station, int counter, TimeEventList* list);
	void Execute();
	void Print();
	double GetTime();
private:
	int counter_;
	TimeEvent* next_;
	const double KDifs = 2;
	double time_;
	Channel* channel_;
	WirelessNetwork* network_;
	int id_base_station_;
	TimeEventList* list_;
};
#endif
