#ifndef CHECKACK_H
#define CHECKACK_H

#include "WirelessNetwork.h"
#include "TimeEvent.h"

class CheckACK :public TimeEvent
{
  public:
  CheckACK(double time, WirelessNetwork* network, int id);
  void Execute();
  void Print();
  double GetTime();
private:
  double time_;
  WirelessNetwork* network_;
  int id_;
};
#endif

