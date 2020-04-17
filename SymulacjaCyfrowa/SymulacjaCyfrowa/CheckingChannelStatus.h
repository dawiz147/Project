#pragma once
#include "TimeEvent.h"
#include "WirelessNetwork.h"

class CheckingChannelStatus :public TimeEvent
{
	CheckingChannelStatus(int time, WirelessNetwork* network);
	void Execute();
	void Print();
private:
	Channel* channel_;
	double time_;

};

