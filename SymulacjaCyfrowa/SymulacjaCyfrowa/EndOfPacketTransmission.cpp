#include "EndOfPacketTransmission.h"
EndOfPacketTransmission::EndOfPacketTransmission(double time, WirelessNetwork* wireless,int base)
{
  time_ = time;
  channel = wireless->GetChannel();
  id_base_station_ = base;
}
void EndOfPacketTransmission::Execute()
{
  channel->SetChannelFree(true);
}

void Print()
{
 
}