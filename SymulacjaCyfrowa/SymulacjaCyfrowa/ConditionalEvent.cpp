#include "ConditionalEvent.h"
using namespace std;
ConditionalEvent::ConditionalEvent(WirelessNetwork* network, TimeEventList* time_event_list)
{
  network_ = network;
  id_base_station_send_packet_ = -1;
  time_event_list_= time_event_list;
  ACK_message_ = false;
  colision_ = false;
  time_ = 0;
}

void ConditionalEvent::CheckConditionalEvent()
{
  if (id_base_station_send_packet_ != -1) // sprawdzanie czy jakaœ stacja bazowa ma wys³aæ swój pakiet
  {
    temp_ = network_->CheckIdFromBaseStation(id_base_station_send_packet_);
    network_->SendPacket(id_base_station_send_packet_);
    network_->DeleteCheckingStation(id_base_station_send_packet_);

    time_ = time_+(rand() % 10) + 1;
    event_ = new EndOfPacketTransmission(time_, network_, id_base_station_send_packet_);
    time_event_list_->AddNewEvent(event_);
    event_ = new CheckACK(time_ + 1, network_, id_base_station_send_packet_);
    time_event_list_->PrintList();

    time_event_list_->AddNewEvent(event_);
    id_base_station_send_packet_ = -1;
  }
  if ((network_->CheckBaseStationTer() != -1) && (network_->GetCheckACK() == true)) // zdarzenie warunkowe wyst¹pienia b³êdu TER
  {
    network_->SetCheckACK(false);
    int temp_ = network_->CheckBaseStationTer();
    if (network_->CheckTerError(network_->CheckBaseStationTer()))
    {
      if(network_->GetTypeInfo()!=3)
      cerr << "package correctly delivered " << endl;
    }
    else
    {
     Package* temp_= network_->GetPackageToTer(network_->CheckBaseStationTer());
     if (temp_->GetLR() < network_->GetNumberOfMaxRetrasmission())
     {
       temp_->IncrementLR();
       network_->AddToRetransmission(temp_, temp_->GetIdStation());
     }
     else delete temp_;
    }
  }
  if (network_->CheckACK() != -1)// zdarzenie warunkowe wys³ania wiaddomoœci ACK
  {
    time_ = network_->GetTime();
    network_->SetAckOnChannel();
    event_ = new FinishSendACK(time_ + 1, network_, network_->CheckACK());
    network_->DeleteACK();
    time_event_list_->AddNewEvent(event_);
  }
  if (package_to_delete_ != nullptr)
  {
    delete package_to_delete_;
  }
  if (network_->GetColission())
  {
    network_->SendToRetransmission();
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

void ConditionalEvent::AddBaseStationToCheckingChannel(int id)
{
  id_base_station_checking_channel_ = id;
}

void ConditionalEvent::SetTime(double time)
{
  time_ = time;
}

