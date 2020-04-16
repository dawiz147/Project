#include "WirelessNetwork.h"

WirelessNetwork::WirelessNetwork(int type_information, int type_print, int step_mode)
{
  time_ = 0;
  channel_ = new Channel();
  type_information_ = type_information;
  type_print_ = type_print;
  if (step_mode == 1) step_mode_ = true;
  else step_mode_ = false;
  for (int i = 0; i < kNumberOfStations_; i++)
  {
    BaseStation* base = new BaseStation();
    base_stations_.push_back(base);

    ReceivingStation* rbase = new ReceivingStation();
    receiving_station_.push_back(rbase);
  }
  this->PrintInfoAboutSystem();
}

void WirelessNetwork::PrintInfoAboutSystem()
{
  if (type_information_ == 1)
  {
    if (type_print_ == 1)
    {
      cerr << "System initialization: " << endl;
      cerr << "Nuber of base stations and receiving station: " << kNumberOfStations_ << endl;
      cerr << "Maximum number of retransmission package: " << max_retrasmission_ << endl;
    }
    else
    {
      ofstream save("debug.txt", ios_base::app);

      save << "System initialization: " << endl;
      save << "Nuber of base stations and receiving station: "<< kNumberOfStations_ << endl;
      save << "Maximum number of retransmission package: " << max_retrasmission_ << endl;
      save.close();
    }
  }
  else if (type_information_ == 2)
  {
    if (type_print_ == 1)
    {
      cerr << "System initialization: " << endl;
      cerr << "Nuber of base stations and receiving station: " << kNumberOfStations_ << endl;
      cerr << "Maximum number of retransmission package: " << max_retrasmission_ << endl;
      cerr << "Vector content base station:" << endl;
    }
    else
    {
      ofstream save("debug.txt", ios_base::app);

      save << "System initialization: " << endl;
      save << "Nuber of base stations and receiving station: " << kNumberOfStations_ << endl;
      save << "Maximum number of retransmission package: " << max_retrasmission_ << endl;
      save.close();
    }
  }
}

Channel* WirelessNetwork::GetChannel()
{
  return channel_;
}

int WirelessNetwork::GetNumberOfMaxRetrasmission()
{
  return max_retrasmission_;
}
