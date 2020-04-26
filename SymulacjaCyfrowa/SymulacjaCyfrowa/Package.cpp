#include "Package.h"

Package::Package(int id_station,int id_package)
{
	id_package_ = id_package;
	average_waiting_time_ = 0;
	nr_retransmission_ = 0;
	CTPk_ = 0;
	source_transmiter_ = 0;
	id_station_ = id_station;
}



int Package::GetLR()
{
	return nr_retransmission_;
}

int Package::GetIdStation()
{
	return id_station_;
}

int Package::GetId()
{
  return id_package_;
}

void Package::IncrementLR()
{
	nr_retransmission_++;
}
