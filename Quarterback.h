#ifndef QUARTERBACK_H
#define QUARTERBACK_H

#include <iostream>
#include <cstdlib>

using namespace std;

#include "FootballPlayer.h"

class Quarterback : public FootballPlayer
{
public:
    Quarterback()
    {
        passingYards = 0;
        passingTouchdowns = 0;
        interceptions = 0;
    }
    Quarterback(int rP)
    {
        roundPicked = rP;
        srand(time(NULL));
        switch (roundPicked)
        {
        case 1:
            passingYards = rand() % 51 + 275;
            passingTouchdowns = rand() % 3 + 2;
            interceptions = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 2:
            passingYards = rand() % 46 + 275;
            passingTouchdowns = rand() % 3 + 2;
            interceptions = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 3:
            passingYards = rand() % 41 + 275;
            passingTouchdowns = rand() % 3 + 2;
            interceptions = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 4:
            passingYards = rand() % 46 + 270;
            passingTouchdowns = rand() % 3 + 2;
            interceptions = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 5:
            passingYards = rand() % 46 + 265;
            passingTouchdowns = rand() % 3 + 2;
            interceptions = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 6:
            passingYards = rand() % 46 + 255;
            passingTouchdowns = rand() % 4 + 1;
            interceptions = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 7:
            passingYards = rand() % 51 + 250;
            passingTouchdowns = rand() % 4 + 1;
            interceptions = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 8:
            passingYards = rand() % 51 + 240;
            passingTouchdowns = rand() % 3 + 1;
            interceptions = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 9:
            passingYards = rand() % 46 + 235;
            passingTouchdowns = rand() % 3 + 1;
            interceptions = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 10:
            passingYards = rand() % 51 + 230;
            passingTouchdowns = rand() % 3 + 1;
            interceptions = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 11:
            passingYards = rand() % 51 + 225;
            passingTouchdowns = rand() % 3 + 1;
            interceptions = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            break;
        case 12:
            passingYards = rand() % 51 + 200;
            passingTouchdowns = rand() % 3 + 0;
            interceptions = rand() % 3 + 0;
            fumbles = rand() % 3 + 0;
            break;
        case 13:
            passingYards = rand() % 51 + 190;
            passingTouchdowns = rand() % 3 + 0;
            interceptions = rand() % 3 + 0;
            fumbles = rand() % 3 + 0;
            break;
        case 14:
            passingYards = rand() % 41 + 180;
            passingTouchdowns = rand() % 3 + 0;
            interceptions = rand() % 3 + 0;
            fumbles = rand() % 3 + 0;
            break;
        case 15:
            passingYards = rand() % 41 + 160;
            passingTouchdowns = rand() % 2 + 0;
            interceptions = rand() % 4 + 0;
            fumbles = rand() % 4 + 0;
            break;
        case 16:
            passingYards = rand() % 51 + 150;
            passingTouchdowns = rand() % 2 + 0;
            interceptions = rand() % 3 + 1;
            fumbles = rand() % 3 + 1;
            break;
        default:
            break;
        }
    }
    Quarterback(int pY, int pT, int ints)
    {
        passingYards = pY;
        passingTouchdowns = pT;
        interceptions = ints;
    }
    void set_passingYards(int pY)
    {
        passingYards = pY;
    }
    void set_passingTouchdowns(int pT)
    {
        passingTouchdowns = pT;
    }
    void set_interceptions(int ints)
    {
        interceptions = ints;
    }
    int get_passingYards()
    {
        return passingYards;
    }
    int get_passingTouchdowns()
    {
        return passingTouchdowns;
    }
    int get_interceptions()
    {
        return interceptions;
    }
    double points()
    {
        return 0.04 * double(passingYards) + 4.0 * double(passingTouchdowns) - 2.0 * double(interceptions + fumbles);
    }
    void teamOutput()
    {
        int indent = 0;
        cout << firstName[0] << ". " << lastName << "\n"
             << passingYards << " YDS";
        if (passingTouchdowns == 1)
        {
            cout << ", TD";
            indent += 2;
        }
        else if (passingTouchdowns > 1)
        {
            cout << ", " << passingTouchdowns << " TD";
            indent++;
        }
        else
        {
            indent += 3;
        }
        if (interceptions == 1)
        {
            cout << ", INT";
            if (passingYards < 100 || passingTouchdowns > 1)
            {
                indent++;
            }
        }
        else if (interceptions > 1)
        {
            cout << ", " << interceptions << " INT";
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
        cout << passingYards << "\t\t" << passingTouchdowns << "\t\t" << interceptions << "/" << fumbles << "\t\t";
        if (points() == int(points()))
        {
            printf("%.1f\n", points());
        }
        else
        {
            cout << points() << endl;
        }
    }
    void profileOutput()
    {
        cout << "SCORING CATEGORY\t\tPTS PER\t\t#\t\tSCORE\nPassing Yards\t\t\t0.04\t\t" << passingYards << "\t";
        if (double(passingYards) * 0.04 == passingYards * 0.04)
        {
            printf("\t%.1f\n", double(passingYards) * 0.04);
        }
        else
        {
            cout << "\t" << double(passingYards) * 0.04 << endl;
        }
        if (passingTouchdowns > 0)
        {
            cout << "TD Pass\t\t\t\t\t4\t\t\t" << passingTouchdowns << "\t";
            printf("\t%.1f\n", double(passingTouchdowns) * 4.0);
        }
        if (interceptions > 0)
        {
            cout << "Interceptions Thrown\t-2\t\t\t" << interceptions << "\t";
            printf("\t%.1f\n", double(interceptions) * (-2.0));
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
        passingYards *= 1.25;
        passingTouchdowns++;
    }
    void bust()
    {
        passingYards *= 0.75;
        interceptions++;
    }

protected:
    int passingYards;
    int passingTouchdowns;
    int interceptions;
};

#endif
