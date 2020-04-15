#pragma once
#include "TimeEvent.h"

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
