#include "PackageGeneration.h"
//#include"TimeEvent.h"
//#include"TimeEventList.h"

using namespace std;

PackageGeneration::PackageGeneration(int time, WirelessNetwork* network,int id_base_station, TimeEventList list)
{
	time_ = time;
	network_ = network;
	id_base_station_ = id_base_station;
	//conditional = conditional_;
}

double PackageGeneration::GetTime()
{
  return time_;
}

void PackageGeneration::Execute()
{
	Package* package = new Package(id_base_station_);
	network_->AddPacketToBaseStation(package,id_base_station_);
	//conditional_->AddPacketToSend(id_base_station_);
	// ZAPLANUJ DODANIE KOLEJNEGO WYGERNORAWNIA PAKIETU ZGODZIE Z CGPk
	// zaplanowanie zdarzenia czasowego sprawdzanie zajêtoœci kana³u 
}
void PackageGeneration::Print()
{
	cerr << "Zaplanowanie wygenerowania pakietu " << time_ << endl;
}
