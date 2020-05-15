#include "CheckACK.h"
CheckACK::CheckACK(double time,  WirelessNetwork* network,int id)
{
  time_ = time;
  network_ = network;
  id_ = id;
}

void CheckACK::Execute()
{
  if (network_->CheckACK(id_) == true)
  {
    network_->SetCheckACK(true);
    if (network_->GetTypeInfo() != 3)
    {
      if (network_->GetTypePrint() != 2)
      {
        cerr << "package from base station id: " << id_ << " has been correctly transported" << endl;
      }
    }

    delete_=network_->GetPackageToTer(id_);
    ofstream save("DeletedPackage.txt", ios_base::app);
    save << "id deleted package: " << delete_->GetId() << endl;
    save << "from station: " << delete_->GetIdStation() << endl;
    save.close();
    network_->IncrementNumberOfPacket();
    network_->IncrementSumOfRetransmission(delete_->GetLR());
    time_one_= delete_->GetExitBuffor();
    time_sec_= delete_->GetExitChannel();
    network_->AddAverageDelayBuffor(time_one_);
    network_->AddAverageDelayChannel(time_sec_);
    delete delete_;
  }
  else
  {
    if (network_->GetTypeInfo() != 3)
    {
      if (network_->GetTypePrint() != 2)
      {
        cerr << "package from base station id: " << id_ << " did not arrive correctly. error occurrence ter" << endl;

      }
    }

    network_->SaveBaseStationTer(id_);
  }
}

void CheckACK::Print()
{
  if (network_->GetTypePrint() == 1)
  {
    cerr << "Schedule an check ack messege: " << time_ << endl;
  }
  else
  {
    ofstream save("debug.txt", ios_base::app);
    save << "Schedule an check ack messege: " << time_ << endl;
    save.close();
  }
}

double CheckACK::GetTime()
{
  return time_;
}
