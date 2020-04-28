#ifndef CONDITIONALEVENT_H
#define CONDITIONALEVENT_H
#include "WirelessNetwork.h"
#include "TimeEventList.h"
#include "TimeEvent.h"
//#include "TerError.h"
#include "EndOfPacketTransmission.h"
#include "CheckACK.h"
#include "Package.h"
#include "FinishSendACK.h"
class ConditionalEvent
{
public:
  ConditionalEvent(WirelessNetwork* network, TimeEventList* time_event_list);
  void CheckConditionalEvent();
  void AddPacketToSend(int id);
  void ACKMessage();
  void SetPackageToDelete(Package* packet);
  void SetCollision(Package* colision_package);
  void AddBaseStationToCheckingChannel(int id);
  void SetTime(double time);
  
private:
  WirelessNetwork* network_;
  int id_base_station_send_packet_;
  TimeEvent* time_event_;
  TimeEventList* time_event_list_;
  double time_to_delete_Ter_;
  bool ACK_message_;
  Package* package_to_delete_;
  bool colision_;
  Package* colision_package_;
  int id_base_station_checking_channel_;
  TimeEvent* event_;
  double time_;
  int temp_;
};
#endif
