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
        cerr << "package from base station id:" << id_ << " has been correctly transported" << endl;
      }
    }

    delete_=network_->GetPackageToTer(id_);
  }
  else
  {
    network_->SetIdTerError(id_);
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
