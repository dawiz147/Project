#include "PackageGeneration.h"



using namespace std;

PackageGeneration::PackageGeneration(int time, WirelessNetwork* network,int id_base_station, TimeEventList* list, ConditionalEvent* conditional)
{
	time_ = time;
	network_ = network;
	id_base_station_ = id_base_station;
	conditional_= conditional;
  list_ = list;
}

double PackageGeneration::GetTime()
{
  return time_;
}

void PackageGeneration::Execute()
{
	Package* package = new Package(id_base_station_,network_->GetIdGeneratedPackage());
  if (network_->GetTypeInfo() == 2)
  {
    if (network_->GetTypePrint() == 1)
    {
      cerr << "Packet generation id:" << package->GetId() << endl;
    }
    else
    {
      ofstream save("debug.txt", ios_base::app);
      save << "packet generation id:" << package->GetId() << endl;
      save.close();
    }
  }
	network_->AddPacketToBaseStation(package,id_base_station_);
  TimeEvent* time_event = new PackageGeneration(time_ + network_->GetTimeGenerationPackage(), network_, id_base_station_, list_, conditional_);
  list_->AddNewEvent(time_event);
  if (network_->CheckingStation(id_base_station_)) //sprawdzanie czy dana stacja nas³uchuje ju¿ kana³u w celu przes³ania pakietu
  {
    //nic nie rób stacja sprawdza ju¿ kana³

  }
  else
  {
    network_->AddBaseStationChecking(id_base_station_);
    TimeEvent* event = new CheckingChannel(time_, network_, id_base_station_, conditional_, 0,list_);
    list_->AddNewEvent(event);

  }
}
void PackageGeneration::Print()
{
  if (network_->GetTypeInfo() != 3) {
    if (network_->GetTypePrint() == 1)
    {
      cerr << "It is planned to generate the package on time" << time_ << endl;
    }
    else
    {
      ofstream save("debug.txt", ios_base::app);
      save << "It is planned to generate the package on time" << time_ << endl;
      save.close();
    }
  }
}
