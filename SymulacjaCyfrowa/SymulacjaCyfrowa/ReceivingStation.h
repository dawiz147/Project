#pragma once
#include "Package.h"
class ReceivingStation
{
public:
  ReceivingStation();
  void AddPacket(Package* packet);
private:
  Package* packet_received_;
};

