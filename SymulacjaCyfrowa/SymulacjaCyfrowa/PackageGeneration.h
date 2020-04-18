#pragma once
#include "TimeEvent.h"
#include <iostream>
#include "Package.h"
#include "WirelessNetwork.h"
#include "TimeEventList.h"

class PackageGeneration:TimeEvent
{
public:
	PackageGeneration(int time, WirelessNetwork* network, int id_base_station);
	~PackageGeneration() = default;
	double GetTime();
	void Execute();
	void Print();

private:
	double time_;
	WirelessNetwork* network_;
	int id_base_station_;
};
