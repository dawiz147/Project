#ifndef PACKAGEGENERATION_H
#define PACKAGEGENERATION_H
#include "TimeEvent.h"
#include <iostream>
#include "Package.h"
#include "WirelessNetwork.h"
#include "TimeEventList.h"
#include "CheckingChannel.h"


class PackageGeneration:public TimeEvent
{
public:
	PackageGeneration(double time, WirelessNetwork* network, int id_base_station, TimeEventList* list);
	~PackageGeneration() = default;
	double GetTime();
	void Execute();
	void Print();
	int RetrunId();
private:
	double time_;
	double time_temp;
	WirelessNetwork* network_;
	int id_base_station_;
	TimeEventList* list_;

};
#endif
