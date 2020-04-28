#pragma once
#include "TimeEvent.h"
#include "WirelessNetwork.h"
class FinishSendACK :public TimeEvent
{
public:
FinishSendACK(double time, WirelessNetwork* network,int id);
void Execute();
void Print();
double GetTime();
private:
  WirelessNetwork* network_;
  double time_;
  int id_base_station_;
};

