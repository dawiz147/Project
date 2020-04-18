#include "CheckingChannelStatus.h"
CheckingChannelStatus::CheckingChannelStatus(int time, WirelessNetwork* network)
{
  time_ = time;
  channel_ = network->GetChannel();
}

void CheckingChannelStatus::Execute()
{
  bool temp= channel_->GetInformationOnChannelUsage();

}

void CheckingChannelStatus::Print()
{
  cerr << "the channel is: " ;
  if ((channel_->GetInformationOnChannelUsage() == 1))
  {
    cerr << "free" << endl;
  }
  else cerr << "busy" << endl;
}

double CheckingChannelStatus::GetTime()
{
  return time_;
}
