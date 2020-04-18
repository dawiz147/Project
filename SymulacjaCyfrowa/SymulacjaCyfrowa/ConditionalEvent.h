#pragma once
#include "WirelessNetwork.h"
class ConditionalEvent
{
public:
  ConditionalEvent(WirelessNetwork* network);
  void CheckConditionalEvent();
  void AddPacketToSend(int id);
private:
  WirelessNetwork* network_;
  int id_base_station_send_packet_;
};

