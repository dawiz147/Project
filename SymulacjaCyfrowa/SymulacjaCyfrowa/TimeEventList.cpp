#include "TimeEventList.h"
TimeEventList::TimeEventList()
{
  first_ = last_ = nullptr;
}
void TimeEventList::AddNewEvent(TimeEvent* event)
{
  if (first_ == nullptr) // je¿eli jest to pierwszy time event dodaj go na poczatek listy
  {
    first_ = last_ = event;

  }
  //dodawanie na pocz¹tek
  else if (first_->GetTime() >= event->GetTime())
  {
    event->next_ = first_;
    first_ = event;

  }
  // dodwanie na koniec
  else if (last_->GetTime() <= event->GetTime())
  {

    event->next_ = nullptr;
    event->prev_=last_;
    last_->next_ = event;
    last_ = event;

  }
  //dodawanie w œrodku
  else{
  temp_ = first_;
  while (temp_->GetTime() <= event->GetTime())
  {
    temp_ = temp_->next_;
  }
  event->next_ = temp_;
  event->prev_ = temp_->prev_;
  temp_->prev_->next_ = event;
  temp_->prev_ = event;
  }

}

void TimeEventList::PrintList()
{
  if (first_ == nullptr) cerr << "list is empty" << endl;
  else
  {
    temp_ = first_;
    while (temp_ != last_)
    {
      temp_->Print();
      temp_ = temp_->next_;
    }
    temp_->Print();
  }
}

void TimeEventList::DeleteTimeEvent(double time)
{
  temp_ = first_;
  
  while (temp_->GetTime() != time)
  {
    temp_ = temp_->next_;
  }
  temp_->next_->prev_ = temp_->prev_;
  temp_->prev_->next_ = temp_->next_;
  delete temp_;
}

TimeEvent* TimeEventList::GetFirst()
{
  if (first_ != nullptr) {
    TimeEvent* first_event_from_list = first_;
    first_ = first_->next_;
    first_event_from_list->next_ = nullptr;
    first_event_from_list->prev_ = nullptr;
    return first_event_from_list;
  }
}
