#ifndef RUNNINGBACK_H
#define RUNNINGBACK_H

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

#include "FootballPlayer.h"

class RunningBack : public FootballPlayer
{
public:
    RunningBack()
    {
        rushingYards = 0;
        rushingTouchdowns = 0;
    }
    RunningBack(int rP)
    {
        roundPicked = rP;
        srand(time(NULL));
        switch (roundPicked)
        {
        case 1:
            rushingYards = rand() % 51 + 80;
            rushingTouchdowns = rand() % 3 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 2:
            rushingYards = rand() % 46 + 75;
            rushingTouchdowns = rand() % 3 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 3:
            rushingYards = rand() % 41 + 70;
            rushingTouchdowns = rand() % 3 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 4:
            rushingYards = rand() % 41 + 65;
            rushingTouchdowns = rand() % 3 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 5:
            rushingYards = rand() % 41 + 60;
            rushingTouchdowns = rand() % 3 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 6:
            rushingYards = rand() % 41 + 55;
            rushingTouchdowns = rand() % 3 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 7:
            rushingYards = rand() % 46 + 50;
            rushingTouchdowns = rand() % 3 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 8:
            rushingYards = rand() % 46 + 40;
            rushingTouchdowns = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 9:
            rushingYards = rand() % 41 + 35;
            rushingTouchdowns = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 10:
            rushingYards = rand() % 46 + 30;
            rushingTouchdowns = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 11:
            rushingYards = rand() % 46 + 25;
            rushingTouchdowns = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 12:
            rushingYards = rand() % 41 + 20;
            rushingTouchdowns = rand() % 2 + 0;
            fumbles = rand() % 3 + 0;
            break;
        case 13:
            rushingYards = rand() % 36 + 20;
            rushingTouchdowns = round(double(rand() % 3 + 1) / 6.0);
            fumbles = rand() % 3 + 0;
            break;
        case 14:
            rushingYards = rand() % 36 + 15;
            rushingTouchdowns = round(double(rand() % 4 + 1) / 8.0);
            fumbles = rand() % 3 + 0;
            break;
        case 15:
            rushingYards = rand() % 36 + 10;
            rushingTouchdowns = round(double(rand() % 5 + 1) / 10.0);
            fumbles = rand() % 4 + 0;
            break;
        case 16:
            rushingYards = rand() % 36 + 5;
            rushingTouchdowns = round(double(rand() % 6 + 1) / 12.0);
            fumbles = rand() % 4 + 0;
            break;
        default:
            break;
        }
    }
    RunningBack(int rY, int rT)
    {
        rushingYards = rY;
        rushingTouchdowns = rT;
    }
    void set_rushingYards(int rY)
    {
        rushingYards = rY;
    }
    void set_rushingTouchdowns(int rT)
    {
        rushingTouchdowns = rT;
    }
    int get_rushingYards()
    {
        return rushingYards;
    }
    int get_rushingTouchdowns()
    {
        return rushingTouchdowns;
    }
    double points()
    {
        return 0.1 * double(rushingYards) + 6.0 * double(rushingTouchdowns) - 2.0 * double(fumbles);
    }
    void teamOutput()
    {
        int indent = 0;
        cout << firstName[0] << ". " << lastName << "\n"
             << rushingYards << " YDS";
        if (rushingTouchdowns == 1)
        {
            cout << ", TD";
            indent += 2;
        }
        else if (rushingTouchdowns > 1)
        {
            cout << ", " << rushingTouchdowns << " TD";
            indent++;
        }
        else
        {
            indent += 3;
        }
        if (fumbles == 1)
        {
            cout << ", FUM";
            if (rushingYards < 100 || rushingTouchdowns > 1)
            {
                indent++;
            }
            // there is probably a mathematical way of finding why these cases specifically need to be extra indented but I just figured this out by running the program a bunch of times and guess and checking
        }
        else if (fumbles > 1)
        {
            cout << ", " << fumbles << " FUM";
        }
        else
        {
            indent += 2;
        }
        for (int i = 0; i < indent; i++)
        {
            cout << "\t";
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
        cout << rushingYards << "\t\t" << rushingTouchdowns << "\t\t" << fumbles << "\t\t";
        printf("%.1f\n", points());
    }
    void profileOutput()
    {
        cout << "SCORING CATEGORY\t\tPTS PER\t\t#\t\tSCORE\nRushing Yards\t\t\t0.1\t\t\t" << rushingYards << "\t";
        printf("\t%.1f\n", double(rushingYards) * 0.1);
        if (rushingTouchdowns > 0)
        {
            cout << "TD Rush\t\t\t\t\t6\t\t\t" << rushingTouchdowns << "\t";
            printf("\t%.1f\n", double(rushingTouchdowns) * 6.0);
        }
        if (fumbles > 0)
        {
            cout << "Total Fumbles Lost\t\t-2\t\t\t" << fumbles << "\t";
            printf("\t%.1f\n", double(fumbles) * (-2.0));
        }
        cout << "TOTAL\t\t\t\t\t\t\t\t\t";
        printf("\t%.1f\n", points());
    }
    void boom()
    {
        rushingYards *= 1.1;
        rushingTouchdowns++;
    }
    void bust()
    {
        rushingYards *= 0.75;
    }

protected:
    int rushingYards;
    int rushingTouchdowns;
};

#endif