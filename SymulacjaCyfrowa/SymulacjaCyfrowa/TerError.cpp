#include "TerError.h"
TerError::TerError(double time,  WirelessNetwork* network, ConditionalEvent* conditional)
{
  time_ = time;
  conditional_ = conditional;
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
    // Wyslij do retransmisji zaplanuj zdarzenie czasowe utworzenia sprawdzenia zajetosci kana³u
  }
  else
  {
    conditional_->SetPackageToDelete(package_);
  }
}

void TerError::Print()
{
  cerr<<"Schedule an error to occur on time: "<<time_<<endl;
}

double TerError::GetTime()
{
  return time_;
}
