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
  else if (first_->GetTime() > event->GetTime())
  {
    event->next_ = first_;
    first_ = event;
  }
  // dodwanie na koniec
  else if (last_->GetTime() < event->GetTime())
  {
    event->next_ = nullptr;
    event->prev_=last_;
    last_->next_ = event;
    last_ = event;
  }
  //dodawanie w œrodku
  temp = first_;
  while (temp->next_->GetTime() < event->GetTime())
  {
    temp = temp->next_;
  }
  temp->next_->prev_ = event;
  event->next_ = temp->next_;
  event->prev_ = temp;
  temp->next_ = event;


}

void TimeEventList::PrintList()
{
  if (first_ == nullptr) cerr << "list is empty" << endl;
  temp = first_;
  while (temp != last_)
  {
    temp->Print();
    temp = temp->next_;
  }
  temp->Print();
}
