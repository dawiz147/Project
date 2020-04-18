#pragma once
#include "WirelessNetwork.h"
class ConditionalEvent
{
public:
  ConditionalEvent(WirelessNetwork* network);
  void CheckConditionalEvent();
private:
  WirelessNetwork* network_
};

