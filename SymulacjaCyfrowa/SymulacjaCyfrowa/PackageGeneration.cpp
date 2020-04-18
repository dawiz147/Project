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
	Package* package = new Package(id_base_station_);
	network_->AddPacketToBaseStation(package,id_base_station_);
	conditional_->AddPacketToSend(id_base_station_);
	// ZAPLANUJ DODANIE KOLEJNEGO WYGERNORAWNIA PAKIETU ZGODZIE Z CGPk
	// zaplanowanie zdarzenia czasowego sprawdzanie zajêtoœci kana³u 
}
void PackageGeneration::Print()
{
	cerr << "Scheduling the package to be generated on time: " << time_ << endl;
}
