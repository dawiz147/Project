#include "BaseStation.h"

BaseStation::BaseStation() 
{
	id_base_station_ = 0;
	CGPk_ = 0;	
}

void BaseStation::AddPackage(Package* package)
{
	package_.push(package);
}

Package* BaseStation::SendPackage()
{
	Package* package=package_.front();
	package_.pop();
	return package;
}
