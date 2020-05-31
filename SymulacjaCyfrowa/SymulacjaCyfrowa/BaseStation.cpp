#include "BaseStation.h"

BaseStation::BaseStation() 
{
	id_base_station_ = 0;
	CGPk_ = 0;	
	ACK_message_ = false;
	error_rate_ = 0;
}

void BaseStation::AddPackage(Package* package)
{
	package_.push(package);
}

Package* BaseStation::SendPackage(double time)
{
	Package* package;
	if (package_to_retransmission_ == nullptr)
	{
		package = package_.front();
		package_.pop();
		package->ExitBuffor(time);
		return package;
	}
	else
	{
		package = package_to_retransmission_;
		package_to_retransmission_ = nullptr;
		return package;
	}
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

void BaseStation::SetSeedExp(int seed)
{
	seed_exp_ = seed;
}

void BaseStation::SetSeedNormal(int seed)
{
	seed_normal_ = seed;
}

int& BaseStation::GetSeedExp()
{
	return seed_exp_;
}

int& BaseStation::GetSeedNormal()
{
	return seed_normal_;
}

void BaseStation::AddError()
{
	error_rate_++;
	//all_package_++;
}

void BaseStation::AddPackageError()
{
	all_package_++;
}

double BaseStation::GetErrorRate()
{
	cerr << "-----" << endl;
	cerr <<"error"<< error_rate_ << endl;
	cerr << all_package_ << endl;
	if (error_rate_ == 0)return 0;
	else return error_rate_/ all_package_;
}

int BaseStation::GetPackageError()
{
	return all_package_;
}

void BaseStation::ResetStatistic()
{
	error_rate_ = 0;
	all_package_ = 0;
}
