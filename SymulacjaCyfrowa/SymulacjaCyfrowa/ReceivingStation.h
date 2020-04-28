#ifndef RECEIVINGSTATION_H
#define RECEIVINGSTATION_H
#include "Package.h"
//#include "ConditionalEvent.h"

class ReceivingStation
{
public:
  ReceivingStation();
  void AddPacket(Package* packet);
  Package* GetPackage();
private:
  Package* packet_received_;
 // ConditionalEvent* conditional_;
};
#endif
