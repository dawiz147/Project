#pragma once
#include "Package.h"
//#include "ConditionalEvent.h"

class ReceivingStation
{
public:
  ReceivingStation();
  void AddPacket(Package* packet);
private:
  Package* packet_received_;
 // ConditionalEvent* conditional_;
};

