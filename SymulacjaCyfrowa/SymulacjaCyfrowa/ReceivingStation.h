#pragma once
#include "Package.h"
class ReceivingStation
{
  ReceivingStation();
  void AddPacket(Package* packet);
private:
  Package* packet_received_;
};

