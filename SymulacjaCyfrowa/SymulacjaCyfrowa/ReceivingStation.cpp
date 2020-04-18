#include "ReceivingStation.h"


ReceivingStation::ReceivingStation()
{
  //conditional_ = conditional;
  packet_received_ = nullptr;
}
void ReceivingStation::AddPacket(Package* packet)
{
  packet_received_ = packet;
  //conditional_->ACKMessage();

}
