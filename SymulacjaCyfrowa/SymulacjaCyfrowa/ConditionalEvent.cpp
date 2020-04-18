#include "ConditionalEvent.h"

ConditionalEvent::ConditionalEvent(WirelessNetwork* network, TimeEventList* time_event_list)
{
  network_ = network;
  id_base_station_send_packet_ = -1;
  time_event_list_= time_event_list;
  ACK_message_ = false;
  colision_ = false;
}

void ConditionalEvent::CheckConditionalEvent()
{
  if (id_base_station_send_packet_ >= 0)
  {
    network_->SendPacket(id_base_station_send_packet_);
    id_base_station_send_packet_ = -1;
    //zaplanuj zdarzenie czasowe wyst¹pienie b³êdu TER
    //time_event_ = new TerError(123123, network_);
    //time_to_delete_Ter_ = 123123;
    //time_event_list_->AddNewEvent(time_event_);
  }
  if (ACK_message_ == true)
  {
    time_event_list_->DeleteTimeEvent(time_to_delete_Ter_);
    ACK_message_ = false;
  }
  if (package_to_delete_ != nullptr)
  {
    delete package_to_delete_;
  }
  if (colision_package_ != nullptr)
  {
    network_->AddToRetransmission(colision_package_, colision_package_->GetIdStation());
    colision_package_ = nullptr;
  }

}

void ConditionalEvent::AddPacketToSend(int id)
{
  id_base_station_send_packet_ = id;
}

void ConditionalEvent::ACKMessage()
{
  ACK_message_ = true;
}

void ConditionalEvent::SetPackageToDelete(Package* packet)
{
  package_to_delete_ = packet;
}

void ConditionalEvent::SetCollision(Package* colision_package)
{
  colision_ = true;
  colision_package_ = colision_package;
}

