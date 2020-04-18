#pragma once
#include "TimeEvent.h"
#include "WirelessNetwork.h"
class EndOfPacketTransmission :public TimeEvent
{
public:
EndOfPacketTransmission(double time, WirelessNetwork* wireless, int id_base);
void Execute();
void Print();
double GetTime();
private:
  double time_;
  Channel* channel;
  int id_base_station_;
  WirelessNetwork* network_;
};

