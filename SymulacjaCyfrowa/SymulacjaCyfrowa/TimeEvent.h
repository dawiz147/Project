#ifndef TIMEEVENT_H
#define TIMEEVENT_H
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
#endif
