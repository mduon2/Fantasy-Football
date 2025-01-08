#ifndef FOOTBALLPLAYER_H
#define FOOTBALLPLAYER_H

#include <iostream>

using namespace std;

class FootballPlayer
{
public:
    FootballPlayer()
    {
        firstName = "John";
        lastName = "Doe";
        roundPicked = 0;
        fumbles = 0;
        position = "N/A";
        opponentRank = 0;
    }
    FootballPlayer(string fN, string lN, int rP, int f, string p, int oP)
    {
        firstName = fN;
        lastName = lN;
        roundPicked = rP;
        fumbles = f;
        position = p;
        opponentRank = oP;
    }
    virtual ~FootballPlayer()
    {
        delete this;
    }
    virtual double points()
    {
        return 0.0;
    }
    virtual void teamOutput()
    {
        cout << endl;
    }
    virtual void gamelogOutput()
    {
        cout << endl;
    }
    virtual void profileOutput()
    {
        cout << endl;
    }
    virtual void boom()
    {
        return;
    }
    virtual void bust()
    {
        return;
    }
    string get_firstName()
    {
        return firstName;
    }
    string get_lastName()
    {
        return lastName;
    }
    int get_roundPicked()
    {
        return roundPicked;
    }
    int get_fumbles()
    {
        return fumbles;
    }
    string get_position()
    {
        return position;
    }
    int get_opponentRank()
    {
        return opponentRank;
    }
    void set_firstName(string fN)
    {
        firstName = fN;
    }
    void set_lastName(string lN)
    {
        lastName = lN;
    }
    void set_roundPicked(int rP)
    {
        roundPicked = rP;
    }
    void set_fumbles(int f)
    {
        fumbles = f;
    }
    void set_position(string p)
    {
        position = p;
    }
    void set_opponentRank(int oP)
    {
        opponentRank = oP;
    }
    void getFields(string p)
    {
        string names;
        cout << "First Name?: ";
        cin >> ws;
        getline(cin, names);
        firstName = names;
        ;
        cout << "Last Name?: ";
        cin >> ws;
        getline(cin, names);
        lastName = names;
        position = p;
    }

protected:
    string firstName, lastName, position;
    int roundPicked;
    int fumbles;
    int opponentRank;
};

#endif
