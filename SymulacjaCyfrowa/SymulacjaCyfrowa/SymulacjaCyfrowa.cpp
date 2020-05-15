#include <iostream>
using namespace std;
#include "WirelessNetwork.h"
#include "TimeEventList.h"
#include "TimeEvent.h"
#include "PackageGeneration.h"
#include "CheckACK.h"
#include "EndOfPacketTransmission.h"
#include "FinishSendACK.h"

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
  double temp_int = 0;
  int temp_time = 0;
  //----------------------------------inicjalizacja systemu-------------------------------------
  WirelessNetwork* wireless_network = new WirelessNetwork(type_information, type_print, step_mode);
  TimeEventList* time_event = new TimeEventList();
  //ConditionalEvent* conditional_event = new ConditionalEvent(wireless_network, time_event);
  TimeEvent* generate;
  //----------------------------------Tworzenie wykresów generatorów------------------------------------------
  int create_file;
  cerr << "Do you want to create files to create generator charts :" << endl;
  cerr << "1. Yes" << endl;
  cerr << "2. No" << endl;
  cerr << "Choose a number: "; cin >> create_file;
  while (!((create_file < 3) && (create_file > 0)))
  {
    cerr << "Wrong value selected!! Choose a number(1-3): "; cin >> create_file;
  }
  int seed = 1000000;
  if (create_file == 1)
  {
    double exp = 0;
    int temp_result = 0;
    int tab1[2] = { 0 };
    int tab2[11] = {0};
    int tab_exp[300] = { 0 };
    for (int i = 0; i < 1000000; i++) // zapis do pliku w celu utworzenia wykresu
    {
      temp_result = round(wireless_network->UniformGenerator(seed,0,0));
      tab1[temp_result]++;
    }
    ofstream save("Unifrorm0-1.txt", ios_base::app);
    save << "result 0: "<<tab1[0] << endl;
    save << "result 1: " << tab1[1] << endl;
    save.close();

    for (int i = 0; i < 1000000; i++) // zapis do pliku w celu utworzenia wykresu
    {
      exp = wireless_network->UniformGeneratorIntercal(10,1,seed,0);
      if(exp >1 && exp <=1.9)tab2[1]++;
      else if (exp > 1.9 && exp <= 2.8)tab2[2]++;
      else if (exp > 2.8 && exp <= 3.7)tab2[3]++;
      else if (exp > 3.7 && exp <= 4.6)tab2[4]++;
      else if (exp > 4.6 && exp <= 5.5)tab2[5]++;
      else if (exp > 5.5 && exp <= 6.4)tab2[6]++;
      else if (exp > 6.4 && exp <= 7.3)tab2[7]++;
      else if (exp > 7.3 && exp <= 8.2)tab2[8]++;
      else if (exp > 8.2 && exp <= 9.1)tab2[9]++;
      else if (exp > 9.1 && exp <= 10)tab2[10]++;
      
    }
    for(int i=0;i<10;i++)
    { 
    ofstream save("Unifrorm1-10.txt", ios_base::app);
    save << i+1 <<" "  << tab2[i+1] << endl;
    save.close();
    }
    for (int i = 0; i < 1000000; i++) // zapis do pliku w celu utworzenia wykresu
    {
      exp = wireless_network->ExponentialGenerator(5,seed,0);
      temp_result = exp * 100;
      tab_exp[temp_result]++;
    }
    for (int i = 0; i < 300; i++)
    {
      ofstream save("Exp.txt", ios_base::app);
      save << i  << " " << tab_exp[i] << endl;
      save.close();
    }


  }
  //----------------------------------losowanie seedów------------------------------------------
  // liczba potrzebnych seedow uwzględniając 10 symulacji:
  // 10 symulacji* 10 nadajników =100 seedów dla generatorów wykładniczych
  // 10 symulacji * 10 nadajników= 100 sedów dla generatorów równomiernych
  // 10 symulacji * 1= 10 seedów dla decyzji czy pakiet został poprawnie przesłany przez kanał
  vector<int>exponential;
  vector<int>normal;
  vector<int>zero_one;
  bool condition_seed=true;
  seed = 33;
  int counter = 0;
  while (condition_seed)
  {
    wireless_network->UniformGenerator(seed,0,0);
    counter++;
    if (counter >= 100000)
    {
      if (exponential.size() < 101)
      {
        exponential.push_back(seed);
        counter = 0;
      }
      else if (normal.size() < 101)
      {
        normal.push_back(seed);
        counter = 0;

      }
      else if (zero_one.size() < 11)
      {
        zero_one.push_back(seed);
      }
      else if (condition_seed == true)
      {
        condition_seed = false;
      }
    }
  }
  // Zapisywanie seedów do plików 
  for (int i = 0; i < exponential.size(); i++)
  {
    ofstream save("Exp_seed.txt", ios_base::app);
    save << i<<" : " << exponential[i] << endl;
    save.close();
  }
  for (int i = 0; i < normal.size(); i++)
  {
    ofstream save("Normal_seed.txt", ios_base::app);
    save << i << " : " << normal[i] << endl;
    save.close();
  }
  for (int i = 0; i < zero_one.size(); i++)
  {
    ofstream save("Zero_one_seed.txt", ios_base::app);
    save << i << " : " << zero_one[i] << endl;
    save.close();
  }
  //------------------------------wybor warunka koncowego zakonczenia symulacji------------------------
  int end_simulation_condition;
  double condition_of_finish_time;
  int condition_of_finish_packages;
  cerr << "Select the end simulation condition" << endl;
  cerr << "1. Time " << endl;
  cerr << "2. Number of correctly delivered packages" << endl;
  cerr << "Choose a number: "; cin >> end_simulation_condition;
  while (!((end_simulation_condition < 3) && (end_simulation_condition > 0)))
  {
    cerr << "Wrong value selected!! Choose a number(1-3): "; cin >> end_simulation_condition;
  }
  if (end_simulation_condition == 1)
  {

    cerr << "Enter the end time of the simulation: "; cin >> condition_of_finish_time;
    condition_of_finish_packages=INT_MAX;

  }
  else
  {
    cerr << "Enter the number of packets sent correctly when the simulation is to end : "; cin >> condition_of_finish_packages;
    condition_of_finish_time = INT_MAX;
  }

  bool condition = true;
  double time_initial_phase;
  cerr << "Enter the time of the initial phase after which the statistics should be reset" << endl;
  cin >> time_initial_phase;
  //---------------------inicjalizacja systemu : wygenerowanie pierwszych zdarzeń, przypisanie wylosowanych seedów

    double time = 0;
    for (int i = 0; i < wireless_network->GetNumberOfStations(); i++)
    {
      wireless_network->SetSeedNormalToBaseStation(normal[0], i);
      normal.erase(normal.begin());
      wireless_network->SetSeedExpToBaseStation(exponential[0], i);
      exponential.erase(exponential.begin());
      time = wireless_network->ExponentialGenerator(5, wireless_network->GetSeedExpFromBaseStation(i), i);
      generate = new PackageGeneration(time, wireless_network, i, time_event);
      time_event->AddNewEvent(generate);
    }
    wireless_network->SetSeedInChannel(zero_one[0]);
    zero_one.erase(zero_one.begin());

    // pętla symulacyjna
    while ((wireless_network->GetTime() < condition_of_finish_time) && (wireless_network->GetNumberCorrectlySentPacket() < condition_of_finish_packages))
    {
      if (type_information != 3) {
        if (type_print == 1)
        {
          cerr << "..............................................." << endl;
        }
        else
        {
          ofstream save("debug.txt", ios_base::app);
          save << "..............................................." << endl;
          save.close();
        }
        //time_event->PrintList();
        if (type_print == 1)
        {
          cerr << "..............................................." << endl;
        }
        else
        {
          ofstream save("debug.txt", ios_base::app);
          save << "..............................................." << endl;
          save.close();
        }
      }
      if (time_initial_phase < wireless_network->GetTime() && condition == true)
      {
        condition = false;
        wireless_network->ResetStatistic();
      }


      if (step_mode == 1) cin.get();
      else;
      generate = time_event->GetFirst();
      wireless_network->SetTime(generate->GetTime());
      generate->Execute();
      delete generate;
      // conditional_event->SetTime(wireless_network->GetTime());


      if (type_information != 3) {
        if (type_print == 1)
        {
          cerr << "================check conditional event================" << endl;
        }
        else
        {
          ofstream save("debug.txt", ios_base::app);
          save << "================check conditional event================" << endl;
          save.close();
        }
      }

      if (wireless_network->GetBaseStationSendPacket() != -1) // sprawdzanie czy jakaś stacja bazowa ma wysłać swój pakiet
      {
        temp_int = wireless_network->CheckIdFromBaseStation(wireless_network->GetBaseStationSendPacket());
        wireless_network->SendPacket(wireless_network->GetBaseStationSendPacket(), wireless_network->GetTime());
        if (type_information == 2)
        {
          if (type_print == 1)
          {
            cerr << "The packet was sent from the base station with id: " << wireless_network->GetBaseStationSendPacket() << " id package: " << temp_int << endl;
            cerr << "Scheduling the packet transmission end event and checking ACK messages" << endl;
          }
          else
          {
            ofstream save("debug.txt", ios_base::app);
            save << "The packet was sent from the base station with id: " << wireless_network->GetBaseStationSendPacket() << " id package: " << temp_int << endl;
            save << "Scheduling the packet transmission end event and checking ACK messages" << endl;
            save.close();
          }
        }
        wireless_network->DeleteCheckingStation(wireless_network->GetBaseStationSendPacket());

        temp_time = wireless_network->UniformGeneratorIntercal(10, 1, wireless_network->GetSeedNormalFromBaseStation(wireless_network->GetBaseStationSendPacket()), wireless_network->GetBaseStationSendPacket());
        generate = new EndOfPacketTransmission(temp_time + wireless_network->GetTime(), wireless_network, wireless_network->GetBaseStationSendPacket());
        time_event->AddNewEvent(generate);
        generate = new CheckACK(temp_time + 1 + wireless_network->GetTime(), wireless_network, wireless_network->GetBaseStationSendPacket());
        time_event->AddNewEvent(generate);
        wireless_network->SetBaseStationSendPacket(-1);
      }

      if ((wireless_network->CheckBaseStationTer() != -1)) // zdarzenie warunkowe wystąpienia błędu TER
      {
        Package* temp_ = wireless_network->GetPackageToTer(wireless_network->CheckBaseStationTer());
        if (temp_->GetLR() < wireless_network->GetNumberOfMaxRetrasmission())
        {
          temp_->IncrementLR();
          wireless_network->AddToRetransmission(temp_, temp_->GetIdStation());
          wireless_network->SaveBaseStationTer(-1);
        }
        else delete temp_;

      }
      if (wireless_network->GetIdToCheckToSendACK() > -1) // sprawdzene czy pakiet został poprawnie przesłany przez kanał
      {
        if (wireless_network->ZeroOneGenerator(0.9, wireless_network->GetSeedFromChannel())) // pakiet poprawnie dostarczony wyślij wiadomośc ACK
        {
          wireless_network->SendACK(wireless_network->GetIdToCheckToSendACK());// przekazuje id do zdarzenia warunkowego wysłania wiadomości ack
          if (type_information == 2)
          {
            if (type_print == 1)
            {
              cerr << "Start sending an ack message by the station with id" << wireless_network->GetIdToCheckToSendACK() << endl;
            }
            else
            {
              ofstream save("debug.txt", ios_base::app);
              save << "Start sending an ack message by the station with id" << wireless_network->GetIdToCheckToSendACK() << endl;
              save.close();
            }
          }
          wireless_network->SaveTimeReceivingStation(wireless_network->GetTime(), wireless_network->GetIdToCheckToSendACK());
          wireless_network->IncrementPackageErrorRateBaseStation(wireless_network->GetIdToCheckToSendACK());
          wireless_network->SetAckOnChannel();
          generate = new FinishSendACK(wireless_network->GetTime() + 1, wireless_network, wireless_network->GetIdToCheckToSendACK());
          wireless_network->SaveIdToCheckToSendACK(-1);
          time_event->AddNewEvent(generate);
        }
        else// pakiet nie został poprawnie dostarczony brak wysłania wiadomości ACK
        {
          wireless_network->IncrementErrorRateBaseStation(wireless_network->GetIdToCheckToSendACK());
        }
      }


      if (wireless_network->GetColission())
      {
        wireless_network->SendToRetransmission();
      }

      if (type_information != 3) {
        if (type_print == 1)
        {
          cerr << "=======================================================" << endl;
        }
        else
        {
          ofstream save("debug.txt", ios_base::app);
          save << "========================================================" << endl;
          save.close();
        }
      }
    }

    wireless_network->PrintStatistic();
}
