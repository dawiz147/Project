#pragma once
#include <vector>
#include "BaseStation.h"
#include "Channel.h"
#include "ReceivingStation.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>      
#include <iostream>
#include<fstream>
using namespace std;
class WirelessNetwork
{
public:
	WirelessNetwork(int type_information,int type_print, int step_mode);						//WirelessNetwork class constructor 
	~WirelessNetwork() = default;						//WirelessNetwork class destroyer
	void PrintInfoAboutSystem();
	Channel* GetChannel();
	int GetNumberOfMaxRetrasmission();

private:
	vector<BaseStation*> base_stations_;				//A vector that stores pointers to each broadcasting station
	double time_;										//A variable that specifies the overall system time
	const int kNumberOfStations_ = rand() % 10;						//Variable specifying the number of broadcasting stations
	Channel* channel_;						//Channel indicator
	vector<ReceivingStation*> receiving_station_;		//Pointer to receiving station
	const int max_retrasmission_= rand() % 50;						//Constant describing the number of retransmissions allowed
	int type_information_;
	int type_print_;
	bool step_mode_;
};

