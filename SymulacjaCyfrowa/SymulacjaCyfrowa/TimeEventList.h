#pragma once
#include "TimeEvent.h"
using namespace std;
#include <iostream>

class TimeEventList
{
  TimeEventList();
  void AddNewEvent(TimeEvent* event);
  TimeEvent* GetFirstEvent();
  void PrintList();
private:
  TimeEvent* first_;
  TimeEvent* last_;
  TimeEvent* temp;
};

