#ifndef RECEIVINGSTATION_H
#define RECEIVINGSTATION_H
#include "Package.h"


class ReceivingStation
{
public:
  ReceivingStation();
  void AddPacket(Package* packet);
  Package* GetPackage();
  void SaveTime(double time);
private:
  Package* packet_received_;

};
#endif
