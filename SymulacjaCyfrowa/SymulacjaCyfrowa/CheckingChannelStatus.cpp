#include "CheckingChannelStatus.h"
CheckingChannelStatus::CheckingChannelStatus(int time, WirelessNetwork* network)
{
  time_ = time;
  channel_ = network->GetChannel();
}

bool CheckingChannelStatus::Execute()
{
  return channel_->GetInformationOnChannelUsage();
}

void CheckingChannelStatus::Print()
{
  cerr << "TO DO" << endl;
}
