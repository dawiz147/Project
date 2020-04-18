#include "TerError.h"
TerError::TerError(double time,  WirelessNetwork* network)
{
  time_ = time;
  //conditional_ = conditional;
  network_ = network;
}

void TerError::Execute()
{
  channel_ = network_->GetChannel();
  package_=channel_->GetPackage();
  if (network_->GetNumberOfMaxRetrasmission() > package_->GetLR())
  {
    package_->IncrementLR();
    network_->AddToRetransmission(package_,package_->GetIdStation());
    package_ = nullptr;
    // Wsysy³amy do retransmisji (dodaæ 2 kolejke)
  }
  else
  {
    
  }
}

void TerError::Print()
{
  cerr<<"temp"<<endl;
}

double TerError::GetTime()
{
  return time_;
}
