#pragma once
#include "TimeEvent.h"
#include <iostream>
#include "Package.h"
#include "BaseStation.h"

class PackageGeneration:TimeEvent
{
public:
	PackageGeneration(int time, BaseStation* base);
	~PackageGeneration() = default;
	double GetTime();
	void Execute();
	void Print();

private:
	double time_;
	BaseStation* base_;
};
