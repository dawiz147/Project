#pragma once
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
private:
  TimeEvent* first_;
  TimeEvent* last_;
  TimeEvent* temp_;
};

