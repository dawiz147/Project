#ifndef CHANNEL_H
#define CHANNEL_H
#include "Package.h"
#include <iostream>
#include <vector>
using namespace std;

class Channel
{
public:
	Channel();						//Channel class constructor
	~Channel() = default;			//Channel class destroyer
	bool GetInformationOnChannelUsage();
	void AddPackageToChannel(Package* package);
	void SetChannelFree(bool free);
	Package* GetPackage(int id );
	void SendAckMessage();
	void FinishSendingAckMessage();
	bool GetColission();
	unsigned GetSize();
	Package* GetPackageToRetransmison();
private:
	vector<Package*> vector_package_;		//Pointer to the currently transmitted packet
	int retrasmission_id_;			//Variable that specifies the number of retransmissions that the packet performs
	double transmission_time_;		//Variable specifying the transmission time
	bool free_;						//Variable that indicates whether the channel is free
	bool colission_;				//A variable that indicates whether a collision has occurred
	bool ACK_;
	Package* package_to_send_;
};
#endif
