#include "BaseStation.h"

BaseStation::BaseStation() 
{
	id_base_station_ = 0;
	CGPk_ = 0;	
	ACK_message_ = false;
}

void BaseStation::AddPackage(Package* package)
{
	package_.push(package);
}

Package* BaseStation::SendPackage()
{
	cerr << "The package is sent" << endl;
	Package* package=package_.front();
	package_.pop();
	return package;
}

void BaseStation::Retransmition(Package* package)
{
	package_to_retransmission_ = package;
}

void BaseStation::SetAckMessage()
{
	ACK_message_ = true;
}

bool BaseStation::CheckACK()
{
	temp_ = ACK_message_;
	ACK_message_ = false;
	return temp_;
}

int BaseStation::GetFirtPackageID()
{
	return package_.front()->GetId();
}
