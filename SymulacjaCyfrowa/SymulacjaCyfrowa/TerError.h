#pragma once

#include "WirelessNetwork.h"
#include "TimeEvent.h"
#include "ConditionalEvent.h"
class TerError :public TimeEvent
{
  public:
  TerError(double time, WirelessNetwork* network, ConditionalEvent* conditional);
  void Execute();
  void Print();
  double GetTime();
private:
  double time_;
  Package* package_;
  WirelessNetwork* network_;
  Channel* channel_;
  ConditionalEvent* conditional_;

};

