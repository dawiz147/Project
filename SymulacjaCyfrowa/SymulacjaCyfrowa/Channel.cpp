#include "Channel.h"

Channel::Channel()
{
	Package* current_package_ = nullptr;
	retrasmission_id_ = 0 ;
	transmission_time_ = 0 ;
	
}
bool Channel::GetInformationOnChannelUsage()
{
	return free_;
}

void Channel::AddPackageToChannel(Package* package)
{
	current_package_ = package;
}
