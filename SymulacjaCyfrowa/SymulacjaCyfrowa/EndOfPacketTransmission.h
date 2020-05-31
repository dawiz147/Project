#ifndef ENDOFPACKAGETRANSMISSION_H
#define ENDOFPACKAGETRANSMISSION_H
#include "TimeEvent.h"
#include "WirelessNetwork.h"

class EndOfPacketTransmission :public TimeEvent
{
public:
EndOfPacketTransmission(double time, WirelessNetwork* wireless, int id_base);
void Execute();
void Print();
double GetTime();
int RetrunId();
private:
  int id_event_=2;
  double time_;
  Channel* channel;
  int id_base_station_;
  WirelessNetwork* network_;

};
#endif
