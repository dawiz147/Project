#include "EndOfPacketTransmission.h"
EndOfPacketTransmission::EndOfPacketTransmission(double time, WirelessNetwork* wireless, int id_base)
{
  time_ = time;
  channel = wireless->GetChannel();
  id_base_station_ = id_base;
  network_ = wireless;
  //conditional_ = conditional;

}
void EndOfPacketTransmission::Execute()
{
  channel->SetChannelFree(true);
  Package* received = channel->GetPackage();
  network_->AddPacketToReceivingStation(received,id_base_station_);
  //conditional_->ACKMessage();
}

void EndOfPacketTransmission::Print()
{
  cerr << "temp" << endl;
}

double EndOfPacketTransmission::GetTime()
{
  return time_;
}

void Print()
{
 
}