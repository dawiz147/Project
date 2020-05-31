#include "EndOfPacketTransmission.h"
EndOfPacketTransmission::EndOfPacketTransmission(double time, WirelessNetwork* wireless, int id_base)
{
  time_ = time;
  channel = wireless->GetChannel();
  id_base_station_ = id_base;
  network_ = wireless;


}
void EndOfPacketTransmission::Execute()
{
  if (channel->GetSize() == 1) {
    channel->SetChannelFree(true);
    Package* received = channel->GetPackage(id_base_station_);
    if (network_->GetTypeInfo() == 2) {
      if (network_->GetTypePrint() == 1)
      {
        cerr << "Complete transmission of the packet from station id: " << id_base_station_ << " Packet id: " << received->GetId() << endl;
      }
      else
      {
        ofstream save("debug.txt", ios_base::app);
        save << "Complete transmission of the packet from station id: " << id_base_station_ << " Packet id: " << received->GetId() << endl;
        save.close();
      }
    }
    ofstream save("InitialPhase.txt", ios_base::app);
    save << network_->GetTime()<< " " << network_->GetChartInitialPhase() << endl;
    save.close();
    //cerr << "DODANO DO STACJI ODBIORCZEJ" << endl;
    network_->AddPacketToReceivingStation(received, id_base_station_);
    network_->SaveIdToCheckToSendACK(id_base_station_);
  }
  else// kolizja!
  {
   // cerr << "rozmiar kanaly przy koncu " << channel->GetSize() << endl;
    channel->SetCollision();
  }
}

void EndOfPacketTransmission::Print()
{
  if (network_->GetTypeInfo() != 3) {
    if (network_->GetTypePrint() == 1)
    {
      cerr << "Complete transmission of the packet on time: " << time_ <<" From station id: "<< id_base_station_<< endl;
    }
    else
    {
      ofstream save("debug.txt", ios_base::app);
      save << "Complete transmission of the packet on time: " << time_<<" From station id: " << id_base_station_ << endl;
      save.close();
    }
  }
}

double EndOfPacketTransmission::GetTime()
{
  return time_;
}

int EndOfPacketTransmission::RetrunId()
{
  return id_event_;
}
