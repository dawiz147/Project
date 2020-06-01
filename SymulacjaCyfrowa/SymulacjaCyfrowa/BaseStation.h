#ifndef BASESTATION_H
#define BASESTATION_H
#include "Package.h"
#include <queue>
#include <iostream>
using namespace std;

class BaseStation
{
public:
	BaseStation();					//BaseStation class constructor
	~BaseStation() = default;		//BaseStation class destroyer
	void AddPackage(Package* package);
	Package* SendPackage(double time);
	void Retransmition(Package* package);
	void SetAckMessage();
	bool CheckACK();
	int GetFirtPackageID();
	void SetSeedExp(int seed);
	void SetSeedNormal(int seed);
	int& GetSeedExp();
	int& GetSeedNormal();
	void AddError();
	void AddPackageError();
	double GetErrorRate();
	int GetPackageError();
	void ResetStatistic();
	void PrintInfoTest();

private:
	queue <Package*> package_;		//A queue that will store packets to be sent through the channel
	int id_base_station_;			//Variable specifying the number of the sending station
	const int kCTIZ_ = 0;			//Constant describing ACK pickup time
	double CGPk_;					//Random variable describing the packet generation time
	bool transmiting_;				//Variable meaning that the station has started transmission
	Package* package_to_retransmission_;
	bool ACK_message_;
	bool temp_;
	int seed_exp_;
	int seed_normal_;
	double error_rate_;
	double all_package_;
};
#endif
