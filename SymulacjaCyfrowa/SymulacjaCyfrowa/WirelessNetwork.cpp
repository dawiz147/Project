#include "WirelessNetwork.h"

WirelessNetwork::WirelessNetwork(int type_information, int type_print, int step_mode)
{
  base_station_to_send_ack_ = -1;
  id_base_station_to_retransmision_ter_error_ = -1;
  time_ = 0;
  channel_ = new Channel();
  type_information_ = type_information;
  type_print_ = type_print;
  step_mode_ = step_mode;
  id_genereted_package_ = 0;
  
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
      if (step_mode_ == 1)
      {
        cin.get();
      }
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
  else if (type_information_ == 2)
  {
    if (type_print_ == 1)
    {
      cerr << "System initialization: " << endl;
      cerr << "Nuber of base stations and receiving station: " << kNumberOfStations_ << endl;
      cerr << "Maximum number of retransmission package: " << max_retrasmission_ << endl;
      cerr << "Vector content base station:" << endl;
      if (step_mode_ == 1)
      {
        cin.get();
      }
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

void WirelessNetwork::AddPacketToReceivingStation(Package* package, int id_station)
{
  receiving_station_[id_station]->AddPacket(package);
}

void WirelessNetwork::AddPacketToBaseStation(Package* package, int id_station)
{
  if (type_information_ == 2)
  {
    if (type_print_ == 1)
    {
      cerr << "End of packet transmission id: " << package->GetId() << " The packet was sent from the base station with id: " << id_station << endl;
    }
    else
    {
      ofstream save("debug.txt", ios_base::app);
      save << "End of packet transmission id: " << package->GetId() << " The packet was sent from the base station with id: " << id_station << endl;
      save.close();
    }
  }
  base_stations_[id_station]->AddPackage(package);
}

void WirelessNetwork::SendPacket(int id_base_station)
{
  if (type_information_ == 2)
  {
    if (type_print_ == 1)
    {
      cerr << "The packet was sent from the base station with id: " <<  id_base_station << endl;
    }
    else
    {
      ofstream save("debug.txt", ios_base::app);
      save << "The packet was sent from the base station with id: " << id_base_station << endl;
      save.close();
    }
  }
  channel_->AddPackageToChannel(base_stations_[id_base_station]->SendPackage());

}

void WirelessNetwork::AddToRetransmission(Package* packet, int id)
{
  if (type_information_ == 2)
  {
    if (type_print_ == 1)
    {
      cerr << "packet sent for retransmission with id : " << packet->GetId()<<" sent to the station with id: "<< id << endl;
    }
    else
    {
      ofstream save("debug.txt", ios_base::app);
      save << "packet sent for retransmission with id : " << packet->GetId() << " sent to the station with id: " << id << endl;
      save.close();
    }
  }
  base_stations_[id]->Retransmition(packet);
}

int WirelessNetwork::GetTypeInfo()
{
  return type_information_;
}

int WirelessNetwork::GetTypePrint()
{
  return type_print_;
}

int WirelessNetwork::GetStepMode()
{
  return step_mode_;
}

double WirelessNetwork::GetTime()
{
  return time_;
}

bool WirelessNetwork::CheckACK(int id)
{
  return base_stations_[id]->CheckACK();
}

int WirelessNetwork::GetIdGeneratedPackage()
{
  id_genereted_package_++;
  return id_genereted_package_;
}

int WirelessNetwork::GetNumberOfStations()
{
  return kNumberOfStations_;
}

void WirelessNetwork::SetTime(double time)
{
  time_ = time;
}

double WirelessNetwork::GetTimeGenerationPackage()
{
  return rand()%30;
}

void WirelessNetwork::AddBaseStationChecking(int id)
{
  bases_station_checking_channel_.push_back(id);
}

bool WirelessNetwork::CheckingStation(int id)
{
  for (unsigned i = 0; i < bases_station_checking_channel_.size(); i++)
  {
    if (bases_station_checking_channel_[i] == id)
    {
      return true;
    }
  }
  return false;
}

void WirelessNetwork::DeleteCheckingStation(int id)
{
  for (unsigned i = 0; i < bases_station_checking_channel_.size(); i++)
  {
    if (bases_station_checking_channel_[i] == id)
    {
      bases_station_checking_channel_.erase(bases_station_checking_channel_.begin() + i);
      return;
    }
  }
}

void WirelessNetwork::SetIdTerError(int id)
{
  id_base_station_to_retransmision_ter_error_ = id;
}

int WirelessNetwork::GetIdTerError()
{
  temp_ = id_base_station_to_retransmision_ter_error_;
  id_base_station_to_retransmision_ter_error_ = -1;
  return temp_;
}

int WirelessNetwork::CheckIdFromBaseStation(int id)
{
  return base_stations_[id]->GetFirtPackageID();
}

void WirelessNetwork::SendACK(int id)
{
  base_station_to_send_ack_ = id;
}

int WirelessNetwork::CheckACK()
{
  return base_station_to_send_ack_;
}

void WirelessNetwork::DeleteACK()
{
  base_station_to_send_ack_ = -1;
}

void WirelessNetwork::SetAckOnChannel()
{
  channel_->SendAckMessage();
}

void WirelessNetwork::SentAckOnChannel()
{
  channel_->FinishSendingAckMessage();
}

void WirelessNetwork::SetAck(int id)
{
  base_stations_[id]->SetAckMessage();
}

void WirelessNetwork::SaveBaseStationTer(int id)
{
  id_base_station_to_check_ter_ = id;
}

int WirelessNetwork::CheckBaseStationTer()
{
  return id_base_station_to_check_ter_;
}

bool WirelessNetwork::CheckTerError(int id)
{
  return base_stations_[id]->CheckACK();
}

Package* WirelessNetwork::GetPackageToTer(int id)
{
  return receiving_station_[id]->GetPackage();
}

bool WirelessNetwork::GetColission()
{
  return channel_->GetColission();
}

void WirelessNetwork::SendToRetransmission()
{
  for (unsigned i = 0; i < channel_->GetSize(); i++)
  {
    temp_package_ = channel_->GetPackageToRetransmison();
    this->AddToRetransmission(temp_package_, temp_package_->GetIdStation());
  }
}
