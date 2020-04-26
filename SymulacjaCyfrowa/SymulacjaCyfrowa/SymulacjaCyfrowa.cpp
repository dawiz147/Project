#include <iostream>

using namespace std;
#include "WirelessNetwork.h"
#include "TimeEventList.h"
#include "TimeEvent.h"
#include "PackageGeneration.h"
#include "ConditionalEvent.h"
int main()
{
  int type_information;
  cerr << "Select the type of information displayed:" << endl;
  cerr << "1. Standard" << endl;
  cerr << "2. Debug" << endl;
  cerr << "3. Nothing" << endl;
  cerr << "Choose a number: "; cin >> type_information;
  while (!((type_information < 4) && (type_information > 0)))
  {
    cerr << "Wrong value selected!! Choose a number(1-3): "; cin >> type_information;
  }
  int type_print;
  cerr << "Select the text display type:" << endl;
  cerr << "1. Console" << endl;
  cerr << "2. Txt file" << endl;
  cerr << "Choose a number: "; cin >> type_print;
  while (!((type_print < 3) && (type_print > 0)))
  {
    cerr << "Wrong value selected!! Choose a number(1-2): "; cin >> type_print;
  }

  int step_mode;
  cerr << "Whether to display information in step mode (works only when displaying text in the console):" << endl;
  cerr << "1. Yes" << endl;
  cerr << "2. No" << endl;
  cerr << "Choose a number: "; cin >> step_mode;
  while (!((step_mode < 3) && (step_mode > 0)))
  {
    cerr << "Wrong value selected!! Choose a number(1-2): "; cin >> step_mode;
  }
  //----------------------------------inicjalizacja systemu-------------------------------------
  WirelessNetwork* wireless_network = new WirelessNetwork(type_information, type_print, step_mode);
  TimeEventList* time_event = new TimeEventList();
  ConditionalEvent* conditional_event = new ConditionalEvent(wireless_network, time_event);
  TimeEvent* generate;
  for (int i = 0; i < wireless_network->GetNumberOfStations(); i++)
  {
    generate = new PackageGeneration(0, wireless_network, i, time_event, conditional_event);
    cerr << i << endl;
    time_event->AddNewEvent(generate);
  }
  time_event->PrintList();
  // pętla symulacyjna
  while (wireless_network->GetTime()<800000)
  {
    generate = time_event->GetFirst();
    wireless_network->SetTime(generate->GetTime());
    generate->Execute();
    cin.get();
  }
}
