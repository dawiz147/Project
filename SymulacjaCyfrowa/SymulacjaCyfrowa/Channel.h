#pragma once
#include "Package.h"
class Channel
{
public:
	Channel();						//Channel class constructor
	~Channel() = default;			//Channel class destroyer
private:
	Package* current_package_;		//Pointer to the currently transmitted packet
	int retrasmission_id_;			//Variable that specifies the number of retransmissions that the packet performs
	double transmission_time_;		//Variable specifying the transmission time
	bool free_;						//Variable that indicates whether the channel is free
	bool colission_;				//A variable that indicates whether a collision has occurred
};

