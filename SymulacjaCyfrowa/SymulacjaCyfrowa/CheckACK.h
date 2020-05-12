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
  Package* delete_;
  double time_one_;
  double time_sec_;
};
#endif

