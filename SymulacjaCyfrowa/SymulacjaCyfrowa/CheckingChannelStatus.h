#ifndef CHECKINGCHANNELSTATUS_H
#define CHECKINGCHANNELSTATUS_H
#include "TimeEvent.h"
#include "WirelessNetwork.h"

class CheckingChannelStatus :public TimeEvent
{
public:
	CheckingChannelStatus(int time, WirelessNetwork* network);
	void Execute();
	void Print();
	double GetTime();

private:
	Channel* channel_;
	double time_;

};
#endif
