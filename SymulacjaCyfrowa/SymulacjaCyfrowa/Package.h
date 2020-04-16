#pragma once
class Package
{
public:
	Package();							//Package class constructor
	~Package() = default;				//Package class destroyer
	int GetLR();
	void IncrementLR();

private:
	int id_package_;					//A variable that specifies the package number
	double average_waiting_time_;		//Variable specifying the average packet wait time (time between the packet's appearance in the buffer and leaving it)
	int nr_retransmission_;				//Variable describing the number of the current retransmission
	double CTPk_;						//Variable describing the duration of the transmission
	int source_transmiter_;				//Variable describing which of the broadcasting stations the packet was sent from
};

