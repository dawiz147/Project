#ifndef TIMEEVENTLIST_H
#define TIMEEVENTLIST_H
#include "TimeEvent.h"
using namespace std;
#include <iostream>

class TimeEventList
{
public:
  TimeEventList();
  ~TimeEventList();
  void AddNewEvent(TimeEvent* event);
  //TimeEvent* GetFirstEvent();
  void PrintList();
  void DeleteTimeEvent(double time);
  void DeleteEndTransmission();
  TimeEvent* GetFirst();
  void DeleteCheckACK();
private:
  TimeEvent* first_;
  TimeEvent* last_;
  TimeEvent* temp_;
  bool condition_;
};
#endif
