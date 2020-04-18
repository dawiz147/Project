#pragma once
#include "TimeEvent.h"
#include "Package.h"
#include "WirelessNetwork.h"
class TerError :public TimeEvent
{
  public:
  TerError(int time, Package* package, WirelessNetwork* network);
  void Execute();
  void Print();
  double GetTime();
private:
  double time_;
  Package* package_;
  WirelessNetwork* network_;
};

