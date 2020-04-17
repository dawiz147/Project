#pragma once
#include "TimeEvent.h"
class TimeEventList
{
  TimeEventList();
  void AddNewEvent(TimeEvent* event);
  TimeEvent* GetFirstEvent();
private:
  TimeEvent* first_;
  TimeEvent* last_;
};

