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


  if (network_->GetTypeInfo() != 3) {
    if (network_->GetTypePrint() == 1)
    {
      cerr << "Schedule an finished send ack messege: " << time_ << endl;
    }
    else
    {
      ofstream save("debug.txt", ios_base::app);
      save << "Schedule an finished send ack messege: " << time_ << endl;
      save.close();
    }
  }
}

double FinishSendACK::GetTime()
{
  return time_;
}
