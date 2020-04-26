#include "EndOfPacketTransmission.h"
EndOfPacketTransmission::EndOfPacketTransmission(double time, WirelessNetwork* wireless, int id_base, ConditionalEvent* conditional)
{
  time_ = time;
  channel = wireless->GetChannel();
  id_base_station_ = id_base;
  network_ = wireless;
  conditional_ = conditional;

}
void EndOfPacketTransmission::Execute()
{
  channel->SetChannelFree(true);
  Package* received = channel->GetPackage();
  if (network_->GetTypeInfo() == 2)
  {
    if (network_->GetTypePrint() == 1)
    {
      cerr << "Package with id: " << received->GetId()<<"has been generated. Added to station with id: "<<id_base_station_ << endl;
    }
    else
    {
      ofstream save("debug.txt", ios_base::app);
      save << "Package with id: " << received->GetId() << "has been generated. Added to station with id: " << id_base_station_ << endl;
      save.close();
    }
  }

  network_->AddPacketToReceivingStation(received,id_base_station_);
  conditional_->ACKMessage();
}

void EndOfPacketTransmission::Print()
{
  if (network_->GetTypePrint() == 1)
  {
    cerr << "Complete transmission of the packet on time" << time_ << endl;
  }
  else
  {
    ofstream save("debug.txt", ios_base::app);
   save << "Complete transmission of the packet on time" << time_ << endl;
    save.close();
  }
}

double EndOfPacketTransmission::GetTime()
{
  return time_;
}

void Print()
{
 
}