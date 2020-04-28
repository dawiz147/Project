#include "FinishSendACK.h"
FinishSendACK::FinishSendACK(double time, WirelessNetwork* network, int id)
{
  time_ = time;
  network_ = network;
  id_base_station_ = id;
}
void FinishSendACK::Execute()
{
  network_->SentAckOnChannel();
  network_->SetAck(id_base_station_);
  network_->SaveBaseStationTer(id_base_station_);
}

void FinishSendACK::Print()
{
  cerr << " " << endl;
}

double FinishSendACK::GetTime()
{
  return 0.0;
}
