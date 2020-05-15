#include "WirelessNetwork.h"

WirelessNetwork::WirelessNetwork(int type_information, int type_print, int step_mode)
{
  base_station_to_send_ack_ = -1;
  id_base_station_to_retransmision_ter_error_ = -1;
  id_base_station_to_check_ter_ = -1;
  id_base_station_send_packet_ = -1;
  id_base_station_check_to_send_ACK_ = -1;
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

WirelessNetwork::~WirelessNetwork()
{
  delete temp_package_;
  delete channel_;
  cerr << "usuwanko" << endl;
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
  base_stations_[id_station]->AddPackage(package);
}

void WirelessNetwork::SendPacket(int id_base_station,double time)
{
  channel_->AddPackageToChannel(base_stations_[id_base_station]->SendPackage(time));
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

bool WirelessNetwork::GetCheckACK()
{
  return can_you_check_ack_;
}

void WirelessNetwork::SetCheckACK(bool can_you_check_ack)
{
  can_you_check_ack_ = can_you_check_ack;
}

void WirelessNetwork::SetBaseStationSendPacket(int id)
{
  id_base_station_send_packet_ = id;
}

int WirelessNetwork::GetBaseStationSendPacket()
{
  return id_base_station_send_packet_;
}

double WirelessNetwork::UniformGenerator(int& seed,bool uniform,int id)
{
  int h = seed / kQ;
  seed = kA * (seed - kQ*h) - kR*h;
  if (seed < 0)seed = seed + static_cast<int>(kM);
  if (uniform == true)
  {
    if (id > -1)
    {
      this->SetSeedNormalToBaseStation(seed, id);
    }
    else
    {
      this->SetSeedInChannel(seed);
    }
  }
  else
  {
    this->SetSeedExpToBaseStation(seed, id);
  }
  return seed / kM;
}

double WirelessNetwork::UniformGeneratorIntercal(int maks, int min, int& seed,int id)
{
  return UniformGenerator(seed,true,id)*(maks-min)+min;
}

double WirelessNetwork::ExponentialGenerator(int lambda, int& seed,int id)
{
  return -(1.0/lambda)*log(UniformGenerator(seed,false,id));
}

int WirelessNetwork::ZeroOneGenerator(double p, int& seed)
{
  if (UniformGenerator(seed,true,-1) < p)return 1;
  else return 0;
}

void WirelessNetwork::SetSeedNormalToBaseStation(int seed, int id)
{
  base_stations_[id]->SetSeedNormal(seed);
}

void WirelessNetwork::SetSeedExpToBaseStation(int seed, int id)
{
  base_stations_[id]->SetSeedExp(seed);
}

int& WirelessNetwork::GetSeedNormalFromBaseStation(int id)
{
  return base_stations_[id]->GetSeedNormal();
}

int& WirelessNetwork::GetSeedExpFromBaseStation(int id)
{
  return base_stations_[id]->GetSeedExp();
}

void WirelessNetwork::SetSeedInChannel(int seed)
{
  channel_->SetSeed(seed);
}

int& WirelessNetwork::GetSeedFromChannel()
{
  return channel_->GetSeed();
}

void WirelessNetwork::SaveIdToCheckToSendACK(int id)
{
  id_base_station_check_to_send_ACK_ = id;
}

int WirelessNetwork::GetIdToCheckToSendACK()
{
  return id_base_station_check_to_send_ACK_;
}

void WirelessNetwork::IncrementErrorRateBaseStation(int id)
{
  base_stations_[id]->AddError();
}

void WirelessNetwork::IncrementPackageErrorRateBaseStation(int id)
{
  base_stations_[id]->AddPackageError();
}

void WirelessNetwork::IncrementNumberOfPacket()
{
  number_of_packets_correctly_received_++;
}

int WirelessNetwork::GetNumberCorrectlySentPacket()
{
  return number_of_packets_correctly_received_;
}

void WirelessNetwork::IncrementSumOfRetransmission(int amount)
{
  sum_of_retransmissions_ += amount;
}

void WirelessNetwork::SaveTimeReceivingStation(double time, int id)
{
  receiving_station_[id]->SaveTime(time);
}

void WirelessNetwork::AddAverageDelayBuffor(double time)
{
  average_delay_of_the_packet_buffor_ += time;
}

void WirelessNetwork::AddAverageDelayChannel(double time)
{ 
  average_delay_of_the_packet_channel_ += time;
}

void WirelessNetwork::PrintStatistic()
{
  double temp=0.0;
  double temp2=0.0;
  int id_maks_error_ = base_stations_[0]->GetErrorRate();
  cerr << "Srednia pakietowa stopa bledow (usredniona po K odbiornikach): " << endl;
  for (int i = 0; i < base_stations_.size(); i++)
  {

    temp += base_stations_[i]->GetErrorRate();
    if (id_maks_error_ < temp)id_maks_error_ = i;
    temp2 += base_stations_[i]->GetPackageError();
  }
  cerr << (temp/ temp2)*100.00 <<"%"<< endl;
  cerr << "maksymalna pakietowa stopa bledow" << endl;
  temp = base_stations_[id_maks_error_]->GetErrorRate();
  temp2 = base_stations_[id_maks_error_]->GetPackageError();
  cerr << ( temp/ temp2) * 100.00<<"%" << endl;
  cerr << "srednia liczba retransmisji pakietow" << endl;
  cerr << double(sum_of_retransmissions_ / number_of_packets_correctly_received_) << endl;
  cerr << "Przeplywnosc systemu:" << endl;
  cerr << number_of_packets_correctly_received_ / time_ << endl;
  cerr << "Srednie opoznienie(bufor - odebranie)" << endl;
  cerr << average_delay_of_the_packet_channel_ / number_of_packets_correctly_received_ << endl;
  cerr << "Sredni czas oczekiwania(bufor - opuszczenie) " << endl;
  cerr << average_delay_of_the_packet_buffor_ / number_of_packets_correctly_received_ << endl;
}

void WirelessNetwork::ResetStatistic()
{
  for (int i = 0; i < base_stations_.size(); i++)
  {
    base_stations_[i]->ResetStatistic();
  }
  sum_of_retransmissions_ = 0;
  number_of_packets_correctly_received_ = 0;
  average_delay_of_the_packet_channel_ = 0;
  average_delay_of_the_packet_buffor_ = 0;
}




