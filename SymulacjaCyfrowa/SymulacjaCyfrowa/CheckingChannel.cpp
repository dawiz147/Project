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
      conditional_->AddPacketToSend(id_base_station_);
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
CheckingChannel::CheckingChannel(double time, bool first, WirelessNetwork* network, int id_base_station,ConditionalEvent* conditional)
{
  time_ = time;
  first_ = first;
  network_ = network;
  channel_ = network_->GetChannel();
  conditional_ = conditional;
  id_base_station_=id_base_station;
}