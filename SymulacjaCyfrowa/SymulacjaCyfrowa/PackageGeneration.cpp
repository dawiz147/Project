#include "PackageGeneration.h"
//#include"TimeEvent.h"
//#include"TimeEventList.h"


using namespace std;

PackageGeneration::PackageGeneration(int time, WirelessNetwork* network,int id_base_station, TimeEventList* list, ConditionalEvent* conditional)
{
	time_ = time;
	network_ = network;
	id_base_station_ = id_base_station;
	conditional_= conditional;
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
      cerr << "Packet transmission completed id:" << package->GetId() << endl;
    }
    else
    {
      ofstream save("debug.txt", ios_base::app);
      save << "packet transmission completed id:" << package->GetId() << endl;
      save.close();
    }
  }
	network_->AddPacketToBaseStation(package,id_base_station_);
	conditional_->AddPacketToSend(id_base_station_);


	// ZAPLANUJ DODANIE KOLEJNEGO WYGERNORAWNIA PAKIETU ZGODZIE Z CGPk
	// zaplanowanie zdarzenia czasowego sprawdzanie zajêtoœci kana³u 
}
void PackageGeneration::Print()
{
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
