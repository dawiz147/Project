#include "ReceivingStation.h"

ReceivingStation::ReceivingStation()
{
  packet_received_ = nullptr;
}
void ReceivingStation::AddPacket(Package* packet)
{
  packet_received_ = packet;
}
