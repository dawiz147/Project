#pragma once
#include "Package.h"
#include <queue>

using namespace std;

class BaseStation
{
public:
	BaseStation();					//BaseStation class constructor
	~BaseStation() = default;		//BaseStation class destroyer
	void AddPackage(Package* package);
private:
	queue <Package*> package_;		//A queue that will store packets to be sent through the channel
	int id_base_station_;			//Variable specifying the number of the sending station
	const int kCTIZ_ = 0;			//Constant describing ACK pickup time
	double CGPk_;					//Random variable describing the packet generation time
	bool transmiting_;				//Variable meaning that the station has started transmission
};

