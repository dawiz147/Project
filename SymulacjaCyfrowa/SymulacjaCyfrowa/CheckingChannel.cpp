#include "CheckingChannel.h"
void CheckingChannel::Execute()//True- zak³adamy ¿e kana³ sprawdzamy 1 rz, false sprawdzenie po czasie DIFS
{
  if (network_->GetTypeInfo()==2)
  {
    if (network_->GetTypePrint() == 1)
    {
      cerr << "Checked channel for now: " << counter_ << endl;
    }
    else
    {
      ofstream save("debug.txt", ios_base::app);   
      save << "Checked channel for now: " << counter_ << endl;
      save.close();
    }
  }
  
    TimeEvent* event;
    if (channel_->GetInformationOnChannelUsage() == true)
    {
      counter_++;
      if (counter_ >= 4)
      {
        if (network_->GetTypeInfo() != 3) {
          if (network_->GetTypePrint() == 1)
          {
            cerr << "Send Package from station: " << id_base_station_ << endl;
          }
          else
          {
            ofstream save("debug.txt", ios_base::app);
            save << "Send Package from station: " << id_base_station_ << endl;
            save.close();
          }
         
        }
        network_->DeleteCheckingStation(id_base_station_);
        conditional_->AddPacketToSend(id_base_station_);
      }
      else
      {
        event = new CheckingChannel(time_ + 0.5, network_, id_base_station_, conditional_, counter_, list_);
        list_->AddNewEvent(event);
      }
    }
    else
    {
      counter_=0;
      event = new CheckingChannel(time_ + 0.5, network_, id_base_station_, conditional_, counter_, list_);
      list_->AddNewEvent(event);
    }
   
   

 
}
void CheckingChannel::Print()
{
  if (network_->GetTypeInfo() != 3) {
    if (network_->GetTypePrint() == 1)
    {
      cerr << "Create time event checking channel time: " << time_ << "id base station: " << id_base_station_ << "counter: " << counter_ << endl;
    }
    else
    {
      ofstream save("debug.txt", ios_base::app);
      save << "Create time event checking channel time: " << time_ << "id base station: " << id_base_station_ << "counter: " << counter_ << endl;
      save.close();
    }
  }
}
double CheckingChannel::GetTime()
{
  return time_;
}
CheckingChannel::CheckingChannel(double time, WirelessNetwork* network, int id_base_station,ConditionalEvent* conditional,int counter, TimeEventList* list)
{
  time_ = time;
  network_ = network;
  channel_ = network_->GetChannel();
  conditional_ = conditional;
  id_base_station_=id_base_station;
  counter_ = counter;
  list_ = list;
  
}