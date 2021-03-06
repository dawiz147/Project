#include "ReceivingStation.h"


ReceivingStation::ReceivingStation()
{
  packet_received_ = nullptr;
}
void ReceivingStation::AddPacket(Package* packet)
{
  packet_received_ = packet;
}

Package* ReceivingStation::GetPackage()
{
  return packet_received_;
}

void ReceivingStation::SaveTime(double time)
{
  packet_received_->ExitChannel(time);
}
