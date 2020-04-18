#include "ConditionalEvent.h"

ConditionalEvent::ConditionalEvent(WirelessNetwork* network)
{
  network_ = network;
  id_base_station_send_packet_ = -1;
}

void ConditionalEvent::CheckConditionalEvent()
{
  if (id_base_station_send_packet_ >= 0)
  {
    network_->
  }
}

void ConditionalEvent::AddPacketToSend(int id)
{
  id_base_station_send_packet_ = id;
}
