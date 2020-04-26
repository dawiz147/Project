#include "CheckingChannel.h"
void CheckingChannel::Execute()//True- zak³adamy ¿e kana³ sprawdzamy 1 rz, false sprawdzenie po czasie DIFS
{
  if (network_->GetTypeInfo()==2)
  {
    if (network_->GetTypePrint()==1)
    {
      if (first_ == true)
      {
        cerr << "Checked channel for now: " << counter_ << endl;
      }
      else cerr << "We send the package to the channel" << endl;
    }
    else
    {
      ofstream save("debug.txt", ios_base::app);

      if (first_ == true)
      {
        save << "Checked channel for now: " << counter_ << endl;
      }
      else save << "We send the package to the channel" << endl;
     
      save.close();
    }
  }
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
  if (network_->GetTypePrint() == 1)
  {
  if (first_ == true)
  {
    cerr << "Create time event checking channel time: "<<time_ << endl;
  }
  else cerr << "Checking if the channel is free for more than 2 ms, time: " << time_ << endl;
  }
  else
  { 
  ofstream save("debug.txt", ios_base::app);

  if (first_ == true)
  {
    save << "Create time event checking channel time: " << time_ << endl;
  }
  else save << "Checking if the channel is free for more than 2 ms, time: " << time_ << endl;

  save.close();
  }
}
double CheckingChannel::GetTime()
{
  return time_;
}
CheckingChannel::CheckingChannel(double time, bool first, WirelessNetwork* network, int id_base_station,ConditionalEvent* conditional,int counter)
{
  time_ = time;
  first_ = first;
  network_ = network;
  channel_ = network_->GetChannel();
  conditional_ = conditional;
  id_base_station_=id_base_station;
  counter_ = counter;
  
}