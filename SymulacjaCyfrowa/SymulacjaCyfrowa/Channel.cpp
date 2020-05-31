#include "Channel.h"

Channel::Channel()
{
	Package* current_package_ = nullptr;
	retrasmission_id_ = 0 ;
	transmission_time_ = 0 ;
	free_ = true;
	
}
bool Channel::GetInformationOnChannelUsage()
{
	return free_;
}

void Channel::AddPackageToChannel(Package* package)
{
	vector_package_.push_back(package);
	free_ = false;
}

void Channel::SetChannelFree(bool free)
{
	free_ = free;
}

Package* Channel::GetPackage(int id)
{
	for (unsigned i = 0; i < vector_package_.size(); i++)
	{
		if (vector_package_[i]->GetIdStation() == id)
		{
			package_to_send_ = vector_package_[i];
			vector_package_.erase(vector_package_.begin() + i);

		}
	}
	if (vector_package_.empty())free_= true;
	return package_to_send_;
}

void Channel::SendAckMessage()
{
	free_ = false;
	ACK_ = true;
}

void Channel::FinishSendingAckMessage()
{
	free_ = true;
	ACK_ = false;
}

bool Channel::GetColission()
{
	return colission_;
}

unsigned Channel::GetSize()
{
	return vector_package_.size();
}

Package* Channel::GetPackageToRetransmison()
{
	package_to_send_ = vector_package_[0];
	vector_package_.erase(vector_package_.begin());
	//cerr << "size " << vector_package_.size() << endl;
	if (vector_package_.size() == 0)
	{
		colission_ = false;
		free_ = true;
	}
	return package_to_send_;
}

void Channel::SetSeed(int seed)
{
	seed_ = seed;
}

int& Channel::GetSeed()
{
	return seed_;
}

void Channel::SetCollision()
{
	colission_ = true;
}
