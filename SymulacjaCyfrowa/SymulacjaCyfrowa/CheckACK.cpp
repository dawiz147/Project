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
    if (network_->GetTypeInfo() != 3) cerr << "package from base station id:" << id_ << " has been correctly transported" << endl;
  }
  else
  {
    network_->SetIdTerError(id_);
  }
}

void CheckACK::Print()
{
  cerr<<"Schedule an check ack messege: "<<time_<<endl;
}

double CheckACK::GetTime()
{
  return time_;
}
