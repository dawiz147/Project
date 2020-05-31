#include "TimeEventList.h"
TimeEventList::TimeEventList()
{
  first_ = last_ = nullptr;
}
TimeEventList::~TimeEventList()
{
  while (first_ != last_)
  {
    temp_ = first_;
    first_ = first_->next_;
    delete temp_;
  }
  delete first_;
  first_ = last_ = temp_ = nullptr;
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
    first_->prev_ = event;
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
  while (temp_->GetTime() < event->GetTime())
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

void TimeEventList::DeleteEndTransmission()
{
  temp_ = first_;
  condition_ = true;
  while (temp_ != last_)
  {
    if (temp_->RetrunId() == 2)
    {
      if (temp_ == first_)
      {
        first_ = temp_->next_;
        temp_->next_->prev_ = nullptr;
        temp_->next_ = nullptr;
        delete temp_;
        temp_ = first_;
        condition_ = false;
      }
      else
      {
        temp_->prev_->next_ = temp_->next_;
        temp_->next_->prev_ = temp_->prev_;
      }
    }
    else condition_ = true;
    if (condition_ == true) {
      temp_ = temp_->next_;
    }
  }
  if (temp_->RetrunId() == 2)
  {
    last_ = temp_->prev_;
    temp_->prev_->next_ = nullptr;
    temp_->prev_ = nullptr;
    delete temp_;
  }
}

TimeEvent* TimeEventList::GetFirst()
{
  if (first_ != nullptr) {
    temp_ = first_;
    first_ = first_->next_;
    temp_->next_ = nullptr;
    temp_->prev_ = nullptr;
    return temp_;
  }
}

void TimeEventList::DeleteCheckACK()
{
  temp_ = first_;
  condition_ = true;
  while (temp_ != last_)
  {
    if (temp_->RetrunId() == 1)
    {
      if (temp_ == first_)
      {
        first_ = temp_->next_;
        temp_->next_->prev_ = nullptr;
        temp_->next_ = nullptr;
        delete temp_;
        temp_ = first_;
        condition_ = false;
      }
      else
      {
        temp_->prev_->next_ = temp_->next_;
        temp_->next_->prev_ = temp_->prev_;
      }
    }
    else condition_ = true;
    if (condition_ == true) {
      temp_ = temp_->next_;
    }
  }
  if (temp_->RetrunId() == 1)
  {
    last_ = temp_->prev_;
    temp_->prev_->next_ = nullptr;
    temp_->prev_ = nullptr;
    delete temp_;
  }
}
