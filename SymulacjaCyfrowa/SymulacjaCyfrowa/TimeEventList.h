#ifndef TIMEEVENTLIST_H
#define TIMEEVENTLIST_H
#include "TimeEvent.h"
using namespace std;
#include <iostream>

class TimeEventList
{
public:
  TimeEventList();
  void AddNewEvent(TimeEvent* event);
  //TimeEvent* GetFirstEvent();
  void PrintList();
  void DeleteTimeEvent(double time);
  TimeEvent* GetFirst();
private:
  TimeEvent* first_;
  TimeEvent* last_;
  TimeEvent* temp_;
};
#endif
