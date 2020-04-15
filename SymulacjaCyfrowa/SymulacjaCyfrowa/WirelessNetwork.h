#pragma once
#include <vector>
#include "BaseStation.h"
#include "Channel.h"
#include "ReceivingStation.h"

class WirelessNetwork
{
public:
	WirelessNetwork() = default;						//WirelessNetwork class constructor 
	~WirelessNetwork() = default;						//WirelessNetwork class destroyer
private:
	vector<BaseStation*> base_stations_;				//A vector that stores pointers to each broadcasting station
	double time_;										//A variable that specifies the overall system time
	const int kNumberOfStations_;						//Variable specifying the number of broadcasting stations
	Channel* channel_ = nullptr;						//Channel indicator
	ReceivingStation* receiving_station_ = nullptr;		//Pointer to receiving station
	const int max_retrasmission_;						//Constant describing the number of retransmissions allowed
};

