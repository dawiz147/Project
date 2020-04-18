#ifndef PACKAGEGENERATION_H
#define PACKAGEGENERATION_H
#include "TimeEvent.h"
#include <iostream>
#include "Package.h"
#include "WirelessNetwork.h"
#include "TimeEventList.h"
#include "ConditionalEvent.h"


class PackageGeneration:public TimeEvent
{
public:
	PackageGeneration(int time, WirelessNetwork* network, int id_base_station, TimeEventList* list, ConditionalEvent* conditional);
	~PackageGeneration() = default;
	double GetTime();
	void Execute();
	void Print();

private:
	double time_;
	WirelessNetwork* network_;
	int id_base_station_;
	TimeEventList* list_;
	ConditionalEvent* conditional_;
};
#endif
