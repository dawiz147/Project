#ifndef ENDOFPACKAGETRANSMISSION_H
#define ENDOFPACKAGETRANSMISSION_H
#include "TimeEvent.h"
#include "WirelessNetwork.h"
#include "ConditionalEvent.h"
class EndOfPacketTransmission :public TimeEvent
{
public:
EndOfPacketTransmission(double time, WirelessNetwork* wireless, int id_base, ConditionalEvent* conditional);
void Execute();
void Print();
double GetTime();
private:
  double time_;
  Channel* channel;
  int id_base_station_;
  WirelessNetwork* network_;
ConditionalEvent* conditional_;
};
#endif
