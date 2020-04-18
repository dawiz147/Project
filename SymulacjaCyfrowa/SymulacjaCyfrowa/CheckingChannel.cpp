#include "CheckingChannel.h"
void CheckingChannel::Execute()//True- zak³adamy ¿e kana³ sprawdzamy 1 rz, false sprawdzenie po czasie DIFS
{
  /*
  1.Sprawdz czy kana³ by³ wolny d³u¿ej ni¿ 2ms 
  2.Je¿eli Tak, przeœlij pakiet je¿eli ,Nie ,zaplanuj ponownie sprawdzenie czy kana³ by³ wolny d³u¿ej ni¿ 2ms */
  if (first_ == true) 
  {

    //ZAPLANUJ KOLEJNE SPRAWDZENIE KANALU ZA CZAS DIFS Z je¿eli parametr free_ kana³u jest wolny to :parametrem bool = false, jezeli nie to true
  }
  else
  {
    if (channel_->GetInformationOnChannelUsage() == true)
    {
      package_ = base_->SendPackage();
      channel_->AddPackageToChannel(package_);
      package_ = nullptr;
    }
    else
    {
      //ZAPLANUJ KOLEJNE SPRAWDZENIE KANALU ZA CZAS DIFS z Prametrem first_ = true
    }
  }
}
void CheckingChannel::Print()
{
  if (first_ == true)
  {
    cerr << "Create time event checking channel time: "<<time_ << endl;
  }
  else cerr << "Checking if the channel is free for more than 2 ms, time: " << time_ << endl;
}
double CheckingChannel::GetTime()
{
  return time_;
}
CheckingChannel::CheckingChannel(double time, bool first,Channel* channel, BaseStation* base)
{
  time_ = time;
  first_ = first;
  channel_ = channel;
  base_ = base;
  package_ = nullptr;
}