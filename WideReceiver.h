#ifndef WIDERECEIVER_H
#define WIDERECEIVER_H

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

#include "FootballPlayer.h"

class WideReceiver : public FootballPlayer
{
public:
    WideReceiver()
    {
        receptions = 0;
        receivingYards = 0;
        receivingTouchdowns = 0;
    }
    WideReceiver(int rP)
    {
        roundPicked = rP;
        srand(time(NULL));
        switch (roundPicked)
        {
        case 1:
            receptions = rand() % 5 + 6;
            receivingYards = rand() % 51 + 90;
            receivingTouchdowns = rand() % 3 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 2:
            receptions = rand() % 5 + 6;
            receivingYards = rand() % 46 + 85;
            receivingTouchdowns = rand() % 3 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 3:
            receptions = rand() % 5 + 5;
            receivingYards = rand() % 41 + 80;
            receivingTouchdowns = rand() % 3 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 4:
            receptions = rand() % 5 + 5;
            receivingYards = rand() % 41 + 75;
            receivingTouchdowns = rand() % 3 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 5:
            receptions = rand() % 5 + 4;
            receivingYards = rand() % 46 + 70;
            receivingTouchdowns = rand() % 3 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 6:
            receptions = rand() % 5 + 4;
            receivingYards = rand() % 46 + 65;
            receivingTouchdowns = rand() % 3 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 7:
            receptions = rand() % 4 + 4;
            receivingYards = rand() % 41 + 65;
            receivingTouchdowns = rand() % 3 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 8:
            receptions = rand() % 4 + 4;
            receivingYards = rand() % 41 + 60;
            receivingTouchdowns = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 9:
            receptions = rand() % 4 + 3;
            receivingYards = rand() % 36 + 55;
            receivingTouchdowns = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 10:
            receptions = rand() % 4 + 3;
            receivingYards = rand() % 41 + 50;
            receivingTouchdowns = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 11:
            receptions = rand() % 3 + 3;
            receivingYards = rand() % 41 + 45;
            receivingTouchdowns = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 12:
            receptions = rand() % 3 + 2;
            receivingYards = rand() % 41 + 35;
            receivingTouchdowns = rand() % 2 + 0;
            fumbles = rand() % 3 + 0;
            break;
        case 13:
            receptions = rand() % 2 + 2;
            receivingYards = rand() % 41 + 30;
            receivingTouchdowns = round(double(rand() % 3 + 1) / 6.0);
            fumbles = rand() % 3 + 0;
            break;
        case 14:
            receptions = rand() % 2 + 1;
            receivingYards = rand() % 36 + 20;
            receivingTouchdowns = receivingTouchdowns = round(double(rand() % 4 + 1) / 8.0);
            fumbles = rand() % 3 + 0;
            break;
        case 15:
            receptions = rand() % 2 + 1;
            receivingYards = rand() % 36 + 15;
            receivingTouchdowns = receivingTouchdowns = round(double(rand() % 5 + 1) / 10.0);
            fumbles = rand() % 4 + 0;
            break;
        case 16:
            receptions = rand() % 2 + 0;
            receivingYards = rand() % 36 + 10;
            receivingTouchdowns = receivingTouchdowns = round(double(rand() % 6 + 1) / 12.0);
            fumbles = rand() % 3 + 1;
            break;
        default:
            break;
        }
    }
    WideReceiver(int r, int rY, int rT)
    {
        receptions = r;
        receivingYards = rY;
        receivingTouchdowns = rT;
    }
    void set_receptions(int r)
    {
        receptions = r;
    }
    void set_receivingYards(int rY)
    {
        receivingYards = rY;
    }
    void set_receivingTouchdowns(int rT)
    {
        receivingTouchdowns = rT;
    }
    int get_receptions()
    {
        return receptions;
    }
    int get_receivingYards()
    {
        return receivingYards;
    }
    int get_receivingTouchdowns()
    {
        return receivingTouchdowns;
    }
    double points()
    {
        return double(receptions) + 0.1 * double(receivingYards) + 6.0 * double(receivingTouchdowns) - 2.0 * double(fumbles);
    }
    void teamOutput()
    {
        cout << firstName[0] << ". " << lastName << "\n"
             << receptions << " REC, " << receivingYards << " YDS";
        if (receivingTouchdowns == 1)
        {
            cout << ", TD\t\t";
        }
        else if (receivingTouchdowns > 1)
        {
            cout << ", " << receivingTouchdowns << " TD\t";
        }
        else
        {
            cout << "\t\t\t";
        }
        if (points() == int(points()))
        {
            printf("%.1f\n", points());
        }
        else
        {
            cout << points() << endl;
        }
    }
    void gamelogOutput()
    {
        cout << receptions << "\t\t" << receivingYards << "\t\t" << receivingTouchdowns << "\t\t" << fumbles << "\t\t";
        printf("%.1f\n", points());
    }
    void profileOutput()
    {
        cout << "SCORING CATEGORY\t\tPTS PER\t\t#\t\tSCORE\nReceiving Yards\t\t\t0.1\t\t\t" << receivingYards << "\t";
        printf("\t%.1f\n", double(receivingYards) * 0.1);
        if (receivingTouchdowns > 0)
        {
            cout << "TD Reception\t\t\t6\t\t\t" << receivingTouchdowns << "\t";
            printf("\t%.1f\n", double(receivingTouchdowns) * 6.0);
        }
        if (fumbles > 0)
        {
            cout << "Total Fumbles Lost\t\t-2\t\t\t" << fumbles << "\t";
            printf("\t%.1f\n", double(fumbles) * (-2.0));
        }
        cout << "TOTAL\t\t\t\t\t\t\t\t\t";
        if (points() == int(points()))
        {
            printf("\t%.1f\n", points());
            return;
        }
        cout << "\t" << points() << endl;
    }
    void boom()
    {
        receptions += 2;
        receivingYards *= 1.25;
    }
    void bust()
    {
        if (receptions >= 2)
        {
            receptions -= 2;
            receivingYards *= 0.75;
        }
        else
        {
            receivingYards *= 0.6;
        }
    }

protected:
    int receptions;
    int receivingYards;
    int receivingTouchdowns;
};

#endif