#include "PackageGeneration.h"


using namespace std;

PackageGeneration::PackageGeneration(int time, WirelessNetwork* network,int id_base_station)
{
	time_ = time;
	network_ = network;
	id_base_station_ = id_base_station;
}

double PackageGeneration::GetTime()
{
  return time_;
}

void PackageGeneration::Execute()
{
	Package* package = new Package();
	network_->AddPacketToBaseStation(package,id_base_station_);
	// ZAPLANUJ DODANIE KOLEJNEGO WYGERNORAWNIA PAKIETU ZGODZIE Z CGPk
}
void PackageGeneration::Print()
{
	cerr << "Zaplanowanie wygenerowania pakietu " << time_ << endl;
}
