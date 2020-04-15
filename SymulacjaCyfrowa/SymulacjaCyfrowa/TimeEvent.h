#pragma once

class TimeEvent
{
	virtual void Execute() = 0;
	virtual void Print() = 0;
	TimeEvent* next_;

};

