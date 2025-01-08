#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include "D&ST.h"
#include "FootballPlayer.h"
#include "Kicker.h"
#include "Quarterback.h"
#include "RunningBack.h"
#include "TightEnd.h"
#include "WideReceiver.h"

bool contains(int n, int n2)
{ // meant for at least one of the passed ints to be a single-digit number
  int larger = max(n, n2), smaller = min(n, n2);
  while (larger > 0)
  {
    if (smaller == larger % 10)
    {
      return true;
    }
    larger /= 10;
  }
  return false;
}

int main()
{

  srand(time(NULL));

  string line, week,
      positions[16] = {"QB", "RB", "RB", "WR", "WR", "TE", "FLX", "D/ST",
                       "K", "BE", "BE", "BE", "BE", "BE", "BE", "BE"};
  int slot[16] = {1, 2, 2, 3, 3, 4, 234, 5,
                  6, 123456, 123456, 123456, 123456, 123456, 123456, 123456};
  FootballPlayer *team[16];
  bool availableSlot = true;

  ifstream ifile("Draft.txt");
  if (!ifile)
  {
    int position;
    string ready_or_not = "", names;

    cout << "Welcome to Fantasy Football Draft! There will be 16 rounds "
            "allowing you to draft your team. Afterward, you'll be able to "
            "change around your team before matchups, if you please.\n"
         << endl;
    while (ready_or_not != "yes")
    {
      if (ready_or_not != "")
      {
        cout << "\nThat's okay, take your time! Drafting a fantasy football "
                "team is a big deal.\n"
             << endl;
      }
      cout << "Are you ready to enter the draft? (type \"yes\"): ";
      cin >> ws;
      getline(cin, ready_or_not);
    }

    fstream draftfile("Draft.txt", fstream::out); // fstream::out to create and open a file that does not already exist
    cout << "\nYou are in the draft!\n-----------------";
    for (int i = 1; i <= 16; i++)
    {
      cout << "\nRound " << i << "\n--------Your team so far: " << endl;
      for (int j = 0; j < 16; j++)
      {
        cout << positions[j] << ": ";
        if (slot[j] == 0)
        {
          cout << team[j]->get_firstName() << " " << team[j]->get_lastName()
               << " (" << team[j]->get_position() << ", picked in RD "
               << team[j]->get_roundPicked() << ")" << endl;
        }
        else
        {
          cout << endl;
        }
      }

      cout << "(1 = Quarterback, 2 = Running Back, 3 = Wide Receiver, 4 = "
              "Tight End, 5 = D/ST, 6 = Kicker)\nWhich position would you like "
              "to draft?: ";
      cin >> position;

      availableSlot = false;

      switch (position)
      {
      case 1:
        for (int j = 0; j < 16; j++)
        {
          if (slot[j] == 1 || slot[j] == 123456)
          {
            team[j] = new Quarterback(i);
            team[j]->getFields("Quarterback");
            availableSlot = true;
            slot[j] = 0;
            void(freopen(
                "Draft.txt", "a",
                stdout)); // void() to fix error: ignoring return value of function declared with 'warn_unused_result'
                          // attribute [-Werror,-Wunused-result]
            cout << to_string(j) + "|" + to_string(position) + "|" +
                        team[j]->get_firstName() + "|" + team[j]->get_lastName()
                 << endl;
            fclose(stdout);
            // expansion to keep track of team record
            /*string summary_file_name = team[j]->get_firstName() +
            team[j]->get_lastName() + ".txt";
            void(freopen(summary_file_name.c_str(), "a", stdout)); //.c_str()
            because freopen passes in a c-style string which is basically a char
            array cout<<team[j]->get_firstName() + " " +
            team[j]->get_lastName()<<" ("<<team[j]->get_position()<<")"<<endl;
            fclose(stdout);*/
            void(freopen("/dev/tty", "a",
                         stdout)); // this restores the output to the console
                                   // after the initial freopen diverted the
                                   // output to the "Draft.txt" file
            break;
          }
        }
        if (availableSlot == false)
        {
          cout << "\nThere are no more available slots to draft a Quarterback "
                  "on your team!"
               << endl;
          i--;
          position = 0;
          break; // break inside of the if statement so that it doesn't loop
                 // infinitely
        }
        break;
      case 2:
        for (int j = 0; j < 16; j++)
        {
          if (slot[j] == 2 || slot[j] == 234 || slot[j] == 123456)
          {
            team[j] = new RunningBack(i);
            team[j]->getFields("Running Back");
            availableSlot = true;
            slot[j] = 0;
            void(freopen("Draft.txt", "a", stdout));
            cout << to_string(j) + "|" + to_string(position) + "|" +
                        team[j]->get_firstName() + "|" + team[j]->get_lastName()
                 << endl;
            fclose(stdout);
            /*string summary_file_name = team[j]->get_firstName() +
            team[j]->get_lastName() + ".txt";
            void(freopen(summary_file_name.c_str(), "a", stdout));
            cout<<team[j]->get_firstName() + " " + team[j]->get_lastName()<<"
            ("<<team[j]->get_position()<<")"<<endl; fclose(stdout);*/
            void(freopen("/dev/tty", "a", stdout));
            break;
          }
        }
        if (availableSlot == false)
        {
          cout << "\nThere are no more available slots to draft a Running Back "
                  "on your team!"
               << endl;
          i--;
          position = 0;
          break;
        }
        break;
      case 3:
        for (int j = 0; j < 16; j++)
        {
          if (slot[j] == 3 || slot[j] == 234 || slot[j] == 123456)
          {
            team[j] = new WideReceiver(i);
            team[j]->getFields("Wide Receiver");
            availableSlot = true;
            slot[j] = 0;
            void(freopen("Draft.txt", "a", stdout));
            cout << to_string(j) + "|" + to_string(position) + "|" +
                        team[j]->get_firstName() + "|" + team[j]->get_lastName()
                 << endl;
            fclose(stdout);
            /*string summary_file_name = team[j]->get_firstName() +
            team[j]->get_lastName() + ".txt";
            void(freopen(summary_file_name.c_str(), "a", stdout));
            cout<<team[j]->get_firstName() + " " + team[j]->get_lastName()<<"
            ("<<team[j]->get_position()<<")"<<endl; fclose(stdout);*/
            void(freopen("/dev/tty", "a", stdout));
            break;
          }
        }
        if (availableSlot == false)
        {
          cout << "\nThere are no more available slots to draft a Wide "
                  "Receiver on your team!"
               << endl;
          i--;
          position = 0;
          break;
        }
        break;
      case 4:
        for (int j = 0; j < 16; j++)
        {
          if (slot[j] == 4 || slot[j] == 234 || slot[j] == 123456)
          {
            team[j] = new TightEnd(i);
            team[j]->getFields("Tight End");
            availableSlot = true;
            slot[j] = 0;
            void(freopen("Draft.txt", "a", stdout));
            cout << to_string(j) + "|" + to_string(position) + "|" +
                        team[j]->get_firstName() + "|" + team[j]->get_lastName()
                 << endl;
            fclose(stdout);
            /*string summary_file_name = team[j]->get_firstName() +
            team[j]->get_lastName() + ".txt";
            void(freopen(summary_file_name.c_str(), "a", stdout));
            cout<<team[j]->get_firstName() + " " + team[j]->get_lastName()<<"
            ("<<team[j]->get_position()<<")"<<endl; fclose(stdout);*/
            void(freopen("/dev/tty", "a", stdout));
            break;
          }
        }
        if (availableSlot == false)
        {
          cout << "\nThere are no more available slots to draft a Tight End on "
                  "your team!"
               << endl;
          i--;
          position = 0;
          break;
        }
        break;
      case 5:
        for (int j = 0; j < 16; j++)
        {
          if (slot[j] == 5 || slot[j] == 123456)
          {
            team[j] = new DST(i);
            team[j]->set_position("D/ST");
            cout << "City Name?: ";
            cin >> ws;
            getline(cin, names);
            team[j]->set_firstName(names);
            cout << "Team Name?: ";
            cin >> ws;
            getline(cin, names);
            team[j]->set_lastName(names);
            availableSlot = true;
            slot[j] = 0;
            void(freopen("Draft.txt", "a", stdout));
            cout << to_string(j) + "|" + to_string(position) + "|" +
                        team[j]->get_firstName() + "|" + team[j]->get_lastName()
                 << endl;
            fclose(stdout);
            /*string summary_file_name = team[j]->get_firstName() +
            team[j]->get_lastName() + ".txt";
            void(freopen(summary_file_name.c_str(), "a", stdout));
            cout<<team[j]->get_firstName() + " " + team[j]->get_lastName()<<"
            ("<<team[j]->get_position()<<")"<<endl; fclose(stdout);*/
            void(freopen("/dev/tty", "a", stdout));
            break;
          }
        }
        if (availableSlot == false)
        {
          cout << "\nThere are no more available slots to draft a D/ST on your "
                  "team!"
               << endl;
          i--;
          position = 0;
          break;
        }
        break;
      case 6:
        for (int j = 0; j < 16; j++)
        {
          if (slot[j] == 6 || slot[j] == 123456)
          {
            team[j] = new Kicker(i);
            team[j]->getFields("Kicker");
            availableSlot = true;
            slot[j] = 0;
            void(freopen("Draft.txt", "a", stdout));
            cout << to_string(j) + "|" + to_string(position) + "|" +
                        team[j]->get_firstName() + "|" + team[j]->get_lastName()
                 << endl;
            fclose(stdout);
            /*string summary_file_name = team[j]->get_firstName() +
            team[j]->get_lastName() + ".txt";
            void(freopen(summary_file_name.c_str(), "a", stdout));
            cout<<team[j]->get_firstName() + " " + team[j]->get_lastName()<<"
            ("<<team[j]->get_position()<<")"<<endl; fclose(stdout);*/
            void(freopen("/dev/tty", "a", stdout));
            break;
          }
        }
        if (availableSlot == false)
        {
          cout << "\nThere are no more available slots to draft a Kicker on "
                  "your team!"
               << endl;
          i--;
          position = 0;
          break;
        }
        break;
      default:
        cout << "\nError! That's not a valid position." << endl;
        i--;
        position = 0;
        break; // this error catcher works for invalid integer inputs but for
               // some reason loops infinitely when faced with a string or
               // characted despite being converted to 0
      }
    }
    cout << "\nWoohoo, draft over! This is the team you drafted: " << endl;
    for (int j = 0; j < 16; j++)
    {
      cout << positions[j] << ": " << team[j]->get_firstName() << " "
           << team[j]->get_lastName() << " (" << team[j]->get_position()
           << ", picked in RD " << team[j]->get_roundPicked() << ")" << endl;
    }
    fstream weekfile("Week.txt", fstream::out);
    void(freopen("Week.txt", "w", stdout));
    cout << 1 << endl;
    fclose(stdout);
    void(freopen("/dev/tty", "w", stdout));
    fstream recordfile("Record.txt", fstream::out);
    void(freopen("Record.txt", "w", stdout));
    cout << "0\n0" << endl;
    fclose(stdout);
    void(freopen("/dev/tty", "w", stdout));
  }
  else
  {
    FootballPlayer *opponent_team[16];
    string yes_or_no = "", week, player_info, position;
    int line_counter = 1, second_final_seperator, boom_or_bust;
    double wins, losses;

    ifstream weekfile("Week.txt");
    weekfile >> week;
    if (stoi(week) >= 18)
    {
      fstream recordfile("Record.txt");
      recordfile >> wins;

      string line;

      int currentLine = 0;
      while (getline(recordfile, line))
      {
        currentLine++;
        if (currentLine == 1)
        {
          wins = double(stoi(line));
        }
        else
        {
          losses = double(stoi(line));
        }
      }
      cout << "End of the Fantasy Football "
              "Season!\n------------------------------------\n";
      if (wins > losses)
      {
        cout << "Congratulations on the winning season! You are the champion! "
                "\\o/"
             << endl;
      }
      else if (wins == losses)
      {
        cout << "You tied, a solid performance this season." << endl;
      }
      else
      {
        cout << "You lost. Better luck next season." << endl;
      }
      return 0;
    }
    cout << "Week:" << week << "\t\tRecord: ";

    fstream recordfile("Record.txt");
    recordfile >> wins;
    cout << wins << "W - ";
    string line;

    int linePtr = 2;
    int currentLine = 0;

    currentLine = 0;
    while (getline(recordfile, line))
    {
      currentLine++;
      if (currentLine != linePtr)
      {
        continue; // bad practice but it makes sure the loop runs until the
                  // desired line even if there is nothing to retrieve
      }
      losses = double(stoi(line));
      cout << line << "L" << endl
           << endl;
      break;
    }

    ifstream draftfile("Draft.txt");

    while (getline(draftfile >> ws, player_info))
    {
      position = "";
      for (int i = player_info.find("|") + 1; player_info[i] != '|'; i++)
      {
        second_final_seperator = i + 1;
        position += player_info[i];
      }
      switch (stoi(position))
      {
      case 1:
        team[stoi(player_info.substr(0, player_info.find("|") + 1))] =
            new Quarterback(line_counter);
        team[stoi(player_info.substr(0, player_info.find("|") + 1))]
            ->set_position("Quarterback");
        break;
      case 2:
        team[stoi(player_info.substr(0, player_info.find("|") + 1))] =
            new RunningBack(line_counter);
        team[stoi(player_info.substr(0, player_info.find("|") + 1))]
            ->set_position("Running Back");
        break;
      case 3:
        team[stoi(player_info.substr(0, player_info.find("|") + 1))] =
            new WideReceiver(line_counter);
        team[stoi(player_info.substr(0, player_info.find("|") + 1))]
            ->set_position("Wide Receiver");
        break;
      case 4:
        team[stoi(player_info.substr(0, player_info.find("|") + 1))] =
            new TightEnd(line_counter);
        team[stoi(player_info.substr(0, player_info.find("|") + 1))]
            ->set_position("Tight End");
        break;
      case 5:
        team[stoi(player_info.substr(0, player_info.find("|") + 1))] =
            new DST(line_counter);
        team[stoi(player_info.substr(0, player_info.find("|") + 1))]
            ->set_position("D/ST");
        break;
      case 6:
        team[stoi(player_info.substr(0, player_info.find("|") + 1))] =
            new Kicker(line_counter);
        team[stoi(player_info.substr(0, player_info.find("|") + 1))]
            ->set_position("Kicker");
        break;
      }
      team[stoi(player_info.substr(0, player_info.find("|") + 1))]
          ->set_firstName(player_info.substr(second_final_seperator + 1,
                                             player_info.rfind("|") -
                                                 second_final_seperator - 1));
      team[stoi(player_info.substr(0, player_info.find("|") + 1))]
          ->set_lastName(player_info.substr(player_info.rfind("|") + 1,
                                            player_info.length() -
                                                player_info.rfind("|") - 1));
      line_counter++;
    }

    ifstream opponentfile("OpponentTeam.txt");

    line_counter = 1;

    while (getline(opponentfile >> ws, player_info))
    {
      position = "";
      for (int i = player_info.find("|") + 1; player_info[i] != '|'; i++)
      {
        second_final_seperator = i + 1;
        position += player_info[i];
      }
      switch (stoi(position))
      {
      case 1:
        opponent_team[stoi(player_info.substr(0, player_info.find("|") + 1))] =
            new Quarterback(line_counter);
        opponent_team[stoi(player_info.substr(0, player_info.find("|") + 1))]
            ->set_position("Quarterback");
        break;
      case 2:
        opponent_team[stoi(player_info.substr(0, player_info.find("|") + 1))] =
            new RunningBack(line_counter);
        opponent_team[stoi(player_info.substr(0, player_info.find("|") + 1))]
            ->set_position("Running Back");
        break;
      case 3:
        opponent_team[stoi(player_info.substr(0, player_info.find("|") + 1))] =
            new WideReceiver(line_counter);
        opponent_team[stoi(player_info.substr(0, player_info.find("|") + 1))]
            ->set_position("Wide Receiver");
        break;
      case 4:
        opponent_team[stoi(player_info.substr(0, player_info.find("|") + 1))] =
            new TightEnd(line_counter);
        opponent_team[stoi(player_info.substr(0, player_info.find("|") + 1))]
            ->set_position("Tight End");
        break;
      case 5:
        opponent_team[stoi(player_info.substr(0, player_info.find("|") + 1))] =
            new DST(line_counter);
        opponent_team[stoi(player_info.substr(0, player_info.find("|") + 1))]
            ->set_position("D/ST");
        break;
      case 6:
        opponent_team[stoi(player_info.substr(0, player_info.find("|") + 1))] =
            new Kicker(line_counter);
        opponent_team[stoi(player_info.substr(0, player_info.find("|") + 1))]
            ->set_position("Kicker");
        break;
      }
      opponent_team[stoi(player_info.substr(0, player_info.find("|") + 1))]
          ->set_firstName(player_info.substr(second_final_seperator + 1,
                                             player_info.rfind("|") -
                                                 second_final_seperator - 1));
      opponent_team[stoi(player_info.substr(0, player_info.find("|") + 1))]
          ->set_lastName(player_info.substr(player_info.rfind("|") + 1,
                                            player_info.length() -
                                                player_info.rfind("|") - 1));
      line_counter++;
    }

    cout << "Your Current Team: " << endl;
    for (int j = 0; j < 16; j++)
    {
      team[j]->set_opponentRank(rand() % 32 + 1);
      if (team[j]->get_opponentRank() > 0 && team[j]->get_opponentRank() < 11)
      {
        boom_or_bust = rand() % 2 + 0;
        if (boom_or_bust == 0)
        {
          boom_or_bust = round(double(rand() % 4 + 1) / 8.0);
          if (boom_or_bust == 1)
          {
            team[j]->boom();
          }
          else
          {
            team[j]->bust();
          }
        }
      }
      else if (team[j]->get_opponentRank() > 10 &&
               team[j]->get_opponentRank() < 23)
      {
        boom_or_bust = rand() % 2 + 0;
        if (boom_or_bust == 0)
        {
          boom_or_bust = rand() % 2 + 0;
          if (boom_or_bust == 1)
          {
            team[j]->boom();
          }
          else
          {
            team[j]->bust();
          }
        }
      }
      else
      {
        boom_or_bust = rand() % 2 + 0;
        if (boom_or_bust == 0)
        {
          boom_or_bust = round(double(rand() % 4 + 1) / 8.0);
          if (boom_or_bust == 1)
          {
            team[j]->bust();
          }
          else
          {
            team[j]->boom();
          }
        }
      }
      opponent_team[j]->set_opponentRank(rand() % 32 + 1);
      if (opponent_team[j]->get_opponentRank() > 0 &&
          opponent_team[j]->get_opponentRank() < 11)
      {
        boom_or_bust = rand() % 2 + 0;
        if (boom_or_bust == 0)
        {
          boom_or_bust = round(double(rand() % 4 + 1) / 8.0);
          if (boom_or_bust == 1)
          {
            opponent_team[j]->boom();
          }
          else
          {
            opponent_team[j]->bust();
          }
        }
      }
      else if (opponent_team[j]->get_opponentRank() > 10 &&
               opponent_team[j]->get_opponentRank() < 23)
      {
        boom_or_bust = rand() % 2 + 0;
        if (boom_or_bust == 0)
        {
          boom_or_bust = rand() % 2 + 0;
          if (boom_or_bust == 1)
          {
            opponent_team[j]->boom();
          }
          else
          {
            opponent_team[j]->bust();
          }
        }
      }
      else
      {
        boom_or_bust = rand() % 2 + 0;
        if (boom_or_bust == 0)
        {
          boom_or_bust = round(double(rand() % 4 + 1) / 8.0);
          if (boom_or_bust == 1)
          {
            opponent_team[j]->bust();
          }
          else
          {
            opponent_team[j]->boom();
          }
        }
      }
      cout << positions[j] << ": " << team[j]->get_firstName() << " "
           << team[j]->get_lastName() << " (" << team[j]->get_position()
           << ", picked in RD " << team[j]->get_roundPicked()
           << "), OPP Rank: " << team[j]->get_opponentRank() << endl;
    }

    while (yes_or_no != "yes" && yes_or_no != "no")
    {
      if (yes_or_no != "")
      {
        cout << "\nInvalid answer try again\n"
             << endl;
      }
      cout << "\nWould you like to edit your team? (\"yes\" or \"no\"): ";
      cin >> ws;
      getline(cin, yes_or_no);
    }

    if (yes_or_no == "yes")
    {
      while (yes_or_no == "yes")
      {
        int switch_player_1 = -69, switch_player_2 = -69;

        for (int j = 0; j < 16; j++)
        {
          cout << j + 1 << " = " << positions[j] << ": "
               << team[j]->get_firstName() << " " << team[j]->get_lastName()
               << " (" << team[j]->get_position() << ", picked in RD "
               << team[j]->get_roundPicked()
               << "), OPP Rank: " << team[j]->get_opponentRank() << endl;
        }
        while (switch_player_1 <= 0 || switch_player_2 <= 0 ||
               switch_player_1 > 16 || switch_player_2 > 16 ||
               contains(slot[switch_player_1], slot[switch_player_2]) ==
                   false)
        {
          if (switch_player_1 != -69 && switch_player_2 != -69)
          {
            if (contains(slot[switch_player_1], slot[switch_player_2]) ==
                false)
            {
              cout << "\nThose players cannot switch with one another" << endl;
            }
            else
            {
              cout << "\nPlease make sure your input has the correct numbers "
                      "and follows the format (\"# #\") e.g. 1 3"
                   << endl;
            }
          }
          cout << "Which players do you want to switch around?: (\"# #\") ";
          cin >> switch_player_1 >> switch_player_2;
        }
        FootballPlayer *temp;
        temp = team[switch_player_1 - 1];
        team[switch_player_1 - 1] = team[switch_player_2 - 1];
        team[switch_player_2 - 1] = temp;

        yes_or_no = "";

        while (yes_or_no != "yes" && yes_or_no != "no")
        {
          if (yes_or_no != "")
          {
            cout << "\nInvalid answer try again\n"
                 << endl;
          }
          cout << "\nWould you like to continue editing your team? (\"yes\" or "
                  "\"no\"):";
          cin >> ws;
          getline(cin, yes_or_no);
        }
      }
    }

    double total_points = 0, opp_total_points = 0;

    cout << "Your Team: " << endl;
    for (int j = 0; j < 16; j++)
    {
      cout << positions[j] << ": ";
      team[j]->teamOutput();

      if (j == 0)
      {
        void(freopen("Draft.txt", "w", stdout));
      }
      else
      {
        void(freopen("Draft.txt", "a", stdout));
      }
      cout << to_string(j) + "|";
      if (team[j]->get_position() == "Quarterback")
      {
        cout << 1;
      }
      if (team[j]->get_position() == "Running Back")
      {
        cout << 2;
      }
      if (team[j]->get_position() == "Wide Receiver")
      {
        cout << 3;
      }
      if (team[j]->get_position() == "Tight End")
      {
        cout << 4;
      }
      if (team[j]->get_position() == "D/ST")
      {
        cout << 5;
      }
      if (team[j]->get_position() == "Kicker")
      {
        cout << 6;
      }
      cout << "|" + team[j]->get_firstName() + "|" + team[j]->get_lastName()
           << endl;
      fclose(stdout);
      void(freopen("/dev/tty", "w", stdout));
      // Beginning of expansion to
      /*string summary_file_name = team[j]->get_firstName() +
      team[j]->get_lastName() + ".txt"; void(freopen(summary_file_name.c_str(),
      "a", stdout)); cout<<"Wk "<<week<<": "; team[j]->gamelogOutput();
      fclose(stdout);
      void(freopen("/dev/tty", "w", stdout));*/
      if (j >= 0 && j < 10)
      {
        total_points += team[j]->points();
      }
    }
    cout << "Team Total: \t\t\t";

    if (total_points == int(total_points))
    {
      printf("%.1f\n\n", total_points);
    }
    else
    {
      cout << total_points << endl
           << endl;
    }

    cout << "Opponent's Team: " << endl;
    for (int j = 0; j < 16; j++)
    {
      cout << positions[j] << ": ";
      opponent_team[j]->teamOutput();
      if (j >= 0 && j < 10)
      {
        opp_total_points += opponent_team[j]->points();
      }
    }
    cout << "Team Total: \t\t\t";
    if (opp_total_points == int(opp_total_points))
    {
      printf("%.1f\n\n", opp_total_points);
    }
    else
    {
      cout << opp_total_points << endl
           << endl;
    }

    if (opp_total_points > total_points)
    {
      cout << "You: " << total_points << " | " << opp_total_points
           << " :Opp\n Better Luck Next Week";
      void(freopen("Record.txt", "w", stdout));
      cout << wins << endl
           << losses + 1.0 << endl;
      fclose(stdout);
      void(freopen("/dev/tty", "w", stdout));
    }
    else if (opp_total_points == total_points)
    {
      cout << "You: " << total_points << " | " << opp_total_points
           << " :Opp\n Super Duper Rare Tie!";
      void(freopen("Record.txt", "w", stdout));
      cout << wins + 0.5 << endl
           << losses + 0.5 << endl;
      fclose(stdout);
      void(freopen("/dev/tty", "w", stdout));
    }
    else
    {
      cout << "You: " << total_points << " | " << opp_total_points
           << " :Opp\n Victory Sure Is Sweet!";
      void(freopen("Record.txt", "w", stdout));
      cout << wins + 1.0 << endl
           << losses << endl;
      fclose(stdout);
      void(freopen("/dev/tty", "w", stdout));
    }
    // expansion for page navigation; currently not working idk why I'm tired so I'll debug it later
    /*string next_or_profile = "";
    while (next_or_profile != "next" && next_or_profile != "profile") {
        if (next_or_profile != "") {
            cout<<"\nInvalid Input"<<endl;
        }
        cout<<"Would you like to continue to next week's matchup or have a
    closer look at some players (\"next\" or \"profile\"): "; cin>>ws;
        getline(cin, next_or_profile);
    }
    if (next_or_profile == "profile") {
        while (next_or_profile == "profile") {
            string profile_or_summary = "";
            while (profile_or_summary != "profile" && profile_or_summary !=
    "summary") { if (profile_or_summary != "") { cout<<"\nInvalid Input"<<endl;
                }
                cout<<"Would you like to look at a player's profile for this
    week or a player's season summary? (\"profile\" or \"summary\"): "; cin>>ws;
                getline(cin, profile_or_summary);
            }
            if (profile_or_summary == "profile") {
                int profile;
                for (int j = 0; j < 16; j++) {
                    cout<<j+1<<"="<<positions[j]<<": ";
                    team[j]->teamOutput();
                    total_points += team[j]->points();
                }
                cout<<"Team Total: \t\t\t\t\t";

                if (total_points == int(total_points)) {
                    printf("%.1f\n\n", total_points);
                }
                else {
                    cout<<total_points<<endl<<endl;
                }
                cout<<"Whose profile do you want to look at?: ";
                cin>>profile;
                if (profile > 0 && profile < 17) {
                    cout<<team[profile-1]->get_firstName()<<"
    "<<team[profile-1]->get_lastName()<<"
    ("<<team[profile-1]->get_position()<<") Week "<<week<<endl;
                    team[profile-1]->profileOutput();
                    next_or_profile = "";
                }
            }
            else {
                int summary;
                string summary_line;
                for (int j = 0; j < 16; j++) {
                    cout<<j+1<<"="<<positions[j]<<": ";
                    team[j]->teamOutput();
                    total_points += team[j]->points();
                }
                cout<<"Team Total: \t\t\t\t\t";

                if (total_points == int(total_points)) {
                    printf("%.1f\n\n", total_points);
                }
                else {
                    cout<<total_points<<endl<<endl;
                }
                cout<<"Whose season summary do you want to look at?: ";
                cin>>summary;
                if (summary > 0 && summary < 17) {
                    ifstream summaryfile(team[summary-1]->get_firstName() +
    team[summary-1]->get_lastName() + ".txt"); while (getline(summaryfile,
    summary_line)) { cout<<summary_line<<endl;
                    }
                    next_or_profile = "";
                }
            }
            while (next_or_profile != "next" && next_or_profile != "profile") {
                if (next_or_profile != "") {
                    cout<<"\nInvalid Input"<<endl;
                }
                cout<<"Would you like to continue to next week's matchup or have
    a closer look at some players (\"next\" or \"profile\"): "; cin>>ws;
                getline(cin, next_or_profile);
            }
        }
    }*/
    void(freopen("Week.txt", "w", stdout));
    cout << stoi(week) + 1 << endl;
    fclose(stdout);
    void(freopen("/dev/tty", "w", stdout));
  }

  remove("Draft.txt");
  remove("Week.txt");
  remove("Record.txt");

  delete *team;

  return 0;
}