#include "CheckingChannelStatus.h"
CheckingChannelStatus::CheckingChannelStatus(int time, WirelessNetwork* network)
{
  time_ = time;
  channel_ = network->GetChannel();
}

void CheckingChannelStatus::Execute()
{
  bool temp= channel_->GetInformationOnChannelUsage();
  // POPRAWIÆ 
}

void CheckingChannelStatus::Print()
{
  cerr << "TO DO" << endl;
}

double CheckingChannelStatus::GetTime()
{
  return time_;
}
