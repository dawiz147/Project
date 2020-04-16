#pragma once
#include "TimeEvent.h"
#include "Package.h"
#include "WirelessNetwork.h"
class TerError :public TimeEvent
{
  TerError(int time, Package* package, WirelessNetwork* network);
  void Execute();
  void Print();
private:
  double time_;
  Package* package_;
  WirelessNetwork* network_;
};

