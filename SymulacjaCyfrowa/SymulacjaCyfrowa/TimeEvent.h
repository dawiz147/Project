#pragma once

class TimeEvent
{
public:
	virtual void Execute() = 0;
	virtual void Print() = 0;
	virtual double GetTime();
	TimeEvent* next_;
	TimeEvent* prev_;
private:
	double time_;

};

