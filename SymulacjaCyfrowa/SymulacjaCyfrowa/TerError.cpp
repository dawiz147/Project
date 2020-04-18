#include "TerError.h"
TerError::TerError(int time, Package* package, WirelessNetwork* network)
{
  time_ = time;
  package_ = package;
  network_ = network;
}

void TerError::Execute()
{
  if (network_->GetNumberOfMaxRetrasmission() > package_->GetLR())
  {
    package_->IncrementLR();
    // Wsysy³amy do retransmisji (dodaæ 2 kolejke)
  }
  else
  {
    // ustawiamy do usuniêcia
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
