#include "Package.h"

Package::Package(int id_station)
{
	id_package_ = 0;
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

void Package::IncrementLR()
{
	nr_retransmission_++;
}
