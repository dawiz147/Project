#ifndef WIRELESSNETWORK_H
#define WIRELESSNETWORK_H
#include <vector>
#include "BaseStation.h"
#include "Channel.h"
#include "ReceivingStation.h"
#include <stdio.h>      
#include <stdlib.h>     
#include <time.h>      
#include <iostream>
#include <fstream>
//#include "TimeEventList.h"

using namespace std;
class WirelessNetwork
{
public:
	WirelessNetwork(int type_information, int type_print, int step_mode);						//WirelessNetwork class constructor 
	~WirelessNetwork();						//WirelessNetwork class destroyer
	void PrintInfoAboutSystem();
	Channel* GetChannel();
	int GetNumberOfMaxRetrasmission();
	void AddPacketToReceivingStation(Package* package, int id_station);
	void AddPacketToBaseStation(Package* package, int id_station);
	void SendPacket(int id_base_station,double time);
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
	bool GetCheckACK();
	void SetCheckACK(bool can_you_check_ack);
	void SetBaseStationSendPacket(int id); // ustawianie zmiennej do zdarzenia warunkowego wys³ania pakietu
	int GetBaseStationSendPacket(); // pobieranie zmiennej do zdarzenia warunkowego wysy³ania pakietu
	double UniformGenerator(int& seed, bool uniform, int id);
	double UniformGeneratorIntercal(int maks, int min, int& seed,int id);
	double ExponentialGenerator(double lambda,int& seed,int id);
	int ZeroOneGenerator(double p,int& seed);
	void SetSeedNormalToBaseStation(int seed, int id);
	void SetSeedExpToBaseStation(int seed, int id);
	int& GetSeedNormalFromBaseStation(int id);
	int& GetSeedExpFromBaseStation(int id);
	void SetSeedInChannel(int seed);
	int& GetSeedFromChannel();
	void SaveIdToCheckToSendACK(int id);
	int GetIdToCheckToSendACK();
	void IncrementErrorRateBaseStation(int id);
	void IncrementPackageErrorRateBaseStation(int id);
	void IncrementNumberOfPacket();
	int GetNumberCorrectlySentPacket();
	void IncrementSumOfRetransmission(int amount);
	void SaveTimeReceivingStation(double time, int id);
	void AddAverageDelayBuffor(double time);
	void AddAverageDelayChannel(double time);
	void PrintStatistic();
	void ResetStatistic();
	double GetChartInitialPhase();
private:
	vector<BaseStation*> base_stations_;				//A vector that stores pointers to each broadcasting station
	double time_;										//A variable that specifies the overall system time
	const int kNumberOfStations_ =10;						//Variable specifying the number of broadcasting stations
	Channel* channel_;						//Channel indicator
	vector<ReceivingStation*> receiving_station_;		//Pointer to receiving station
	const int max_retrasmission_ = 15;						//Constant describing the number of retransmissions allowed
	int type_information_;
	int type_print_;
	int step_mode_;
	int id_genereted_package_;
	vector<int> bases_station_checking_channel_;
	int id_base_station_to_retransmision_ter_error_;
	int base_station_to_send_ack_;
	int temp_;
	int id_base_station_to_check_ter_=-1;
	bool can_you_check_ack_=false;
	Package* temp_package_;
	int id_base_station_send_packet_; //Zmienna u¿ywana do wykonania zdarzenia warunkowego wys³ania pakietu ze stacji (zmienna przechowuje id stacji bazowej (-1 == nie ma stacji która chce wys³aæ pakiet))
	int id_base_station_check_to_send_ACK_;
	double number_of_packets_correctly_received_;
	double sum_of_retransmissions_;
	double average_delay_of_the_packet_buffor_=0;
	double average_delay_of_the_packet_channel_=0;
	const double kM = 2147483647.0;
	static const int kA = 16807;
	static const int kQ = 127773;
	static const int kR = 2836;
};
#endif
