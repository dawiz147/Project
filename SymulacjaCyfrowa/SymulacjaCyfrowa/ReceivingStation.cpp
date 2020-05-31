#include "ReceivingStation.h"


ReceivingStation::ReceivingStation()
{
  packet_received_ = nullptr;
}
void ReceivingStation::AddPacket(Package* packet)
{
  //cerr << "WPISANIE PAKIETU DO STACJI ODBIORCZEJ" << packet->GetId();
  packet_received_ = packet;

}

Package* ReceivingStation::GetPackage()
{
 // cerr << "wczytanie  PAKIETU DO STACJI ODBIORCZEJ" << packet_received_->GetId();
  return packet_received_;
}

void ReceivingStation::SaveTime(double time)
{
  packet_received_->ExitChannel(time);
}
