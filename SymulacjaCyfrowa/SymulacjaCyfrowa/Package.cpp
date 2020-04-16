#include "Package.h"

Package::Package() 
{
	id_package_ = 0;
	average_waiting_time_ = 0;
	nr_retransmission_ = 0;
	CTPk_ = 0;
	source_transmiter_ = 0;
}

int Package::GetLR()
{
	return nr_retransmission_;
}

void Package::IncrementLR()
{
	nr_retransmission_++;
}
