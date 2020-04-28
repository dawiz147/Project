#ifndef WIRELESSNETWORK_H
#define WIRELESSNETWORK_H
#include <vector>
#include "BaseStation.h"
#include "Channel.h"
#include "ReceivingStation.h"
//#include "ConditionalEvent.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>      
#include <iostream>
#include <fstream>

using namespace std;
class WirelessNetwork
{
public:
	WirelessNetwork(int type_information, int type_print, int step_mode);						//WirelessNetwork class constructor 
	~WirelessNetwork() = default;						//WirelessNetwork class destroyer
	void PrintInfoAboutSystem();
	Channel* GetChannel();
	int GetNumberOfMaxRetrasmission();
	void AddPacketToReceivingStation(Package* package, int id_station);
	void AddPacketToBaseStation(Package* package, int id_station);
	void SendPacket(int id_base_station);
	void AddToRetransmission(Package* packet,int id);
	int GetTypeInfo();
	int GetTypePrint();
	int GetStepMode();
	double GetTime();
	bool CheckACK(int id);
	int GetIdGeneratedPackage();
	int GetNumberOfStations();
	void SetTime(double time);
	double GetTimeGenerationPackage();
	void AddBaseStationChecking(int id);
	bool CheckingStation(int id);
	void DeleteCheckingStation(int id);
	void SetIdTerError(int id);
	int GetIdTerError();
	int CheckIdFromBaseStation(int id);
	void SendACK(int id);
	int CheckACK();
	void DeleteACK();
	void SetAckOnChannel();
	void SentAckOnChannel();
	void SetAck(int id);
	void SaveBaseStationTer(int id);
	int CheckBaseStationTer();
	bool CheckTerError(int id);
	Package* GetPackageToTer(int id);
	bool GetColission();
	void SendToRetransmission();
private:
	vector<BaseStation*> base_stations_;				//A vector that stores pointers to each broadcasting station
	double time_;										//A variable that specifies the overall system time
	const int kNumberOfStations_ = 2;						//Variable specifying the number of broadcasting stations
	Channel* channel_;						//Channel indicator
	vector<ReceivingStation*> receiving_station_;		//Pointer to receiving station
	const int max_retrasmission_ = rand() % 50;						//Constant describing the number of retransmissions allowed
	int type_information_;
	int type_print_;
	int step_mode_;
	int id_genereted_package_;
	vector<int> bases_station_checking_channel_;
	int id_base_station_to_retransmision_ter_error_;
	int base_station_to_send_ack_;
	int temp_;
	int id_base_station_to_check_ter_=-1;
	Package* temp_package_;
};
#endif
