#pragma once
#include "TimeEvent.h"
#include <iostream>
#include "Package.h"
#include "BaseStation.h"

class PackageGeneration:TimeEvent
{
	PackageGeneration(int time, BaseStation* base);
	~PackageGeneration() = default;

	void Execute();
	void Print();

private:
	double time_;
	BaseStation* base_;
};
