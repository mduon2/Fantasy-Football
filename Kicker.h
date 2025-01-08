#ifndef KICKER_H
#define KICKER_H

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

#include "FootballPlayer.h"

class Kicker : public FootballPlayer
{
public:
    Kicker()
    {
        extraPoints = 0;
        below_forty_yd_FG_made = 0;
        forties_yd_FG_made = 0;
        fifties_yd_FG_made = 0;
        FG_missed = 0;
    }
    Kicker(int rP)
    {
        roundPicked = rP;
        srand(time(NULL));
        if (roundPicked >= 1 && roundPicked <= 10)
        {
            extraPoints = rand() % 6 + 0;
            below_forty_yd_FG_made = rand() % (6 - extraPoints) + 0;
            fifties_yd_FG_made = rand() % (6 - extraPoints - below_forty_yd_FG_made) + 0;
            forties_yd_FG_made = rand() % (6 - extraPoints - below_forty_yd_FG_made - fifties_yd_FG_made) + 0;
            FG_missed = round(double(rand() % 8 + 1) / 16.0);
        }
        else if (roundPicked >= 11 && roundPicked <= 13)
        {
            extraPoints = rand() % 6 + 0;
            below_forty_yd_FG_made = rand() % (6 - extraPoints) + 0;
            forties_yd_FG_made = rand() % (6 - extraPoints - below_forty_yd_FG_made - fifties_yd_FG_made) + 0;
            fifties_yd_FG_made = rand() % (6 - extraPoints - below_forty_yd_FG_made) + 0;
            FG_missed = round(double(rand() % 7 + 1) / 14.0);
        }
        else
        {
            extraPoints = rand() % 5 + 0;
            below_forty_yd_FG_made = rand() % (5 - extraPoints) + 0;
            forties_yd_FG_made = rand() % (5 - extraPoints - below_forty_yd_FG_made - fifties_yd_FG_made) + 0;
            fifties_yd_FG_made = rand() % (5 - extraPoints - below_forty_yd_FG_made) + 0;
            FG_missed = round(double(rand() % 5 + 1) / 10.0);
        }
    }
    Kicker(int eP, int bF, int forties, int fifties, int fgm)
    {
        extraPoints = eP;
        below_forty_yd_FG_made = bF;
        forties_yd_FG_made = forties;
        fifties_yd_FG_made = fifties;
        FG_missed = fgm;
    }
    void set_extraPoints(int pat)
    {
        extraPoints = pat;
    }
    void set_below_forty_yd_FG_made(int bfy)
    {
        below_forty_yd_FG_made = bfy;
        ;
    }
    void set_forties_yd_FG_made(int fy)
    {
        forties_yd_FG_made = fy;
    }
    void set_fifties_yd_FG_made(int fy)
    {
        fifties_yd_FG_made = fy;
    }
    void set_FG_missed(int fgm)
    {
        FG_missed = fgm;
    }
    int get_extraPoints()
    {
        return extraPoints;
    }
    int get_below_forty_yd_FG_made()
    {
        return below_forty_yd_FG_made;
    }
    int get_forties_yd_FG_made()
    {
        return forties_yd_FG_made;
    }
    int get_fifties_yd_FG_made()
    {
        return fifties_yd_FG_made;
    }
    int get_FG_missed()
    {
        return FG_missed;
    }
    double points()
    {
        return double(extraPoints) + 3.0 * double(below_forty_yd_FG_made) + 4.0 * double(forties_yd_FG_made) + 5.0 * double(fifties_yd_FG_made) - double(FG_missed);
    }
    void teamOutput()
    {
        cout << firstName[0] << ". " << lastName << "\n"
             << below_forty_yd_FG_made + forties_yd_FG_made + fifties_yd_FG_made << "/" << below_forty_yd_FG_made + forties_yd_FG_made + fifties_yd_FG_made + FG_missed << " FG, " << extraPoints << "/" << extraPoints + round((rand() % 34 + 1) / 68.0) << " XP";
        printf("\t\t\t%.1f\n", points());
    }
    void gamelogOutput()
    {
        cout << below_forty_yd_FG_made + forties_yd_FG_made + fifties_yd_FG_made << "\t\t" << below_forty_yd_FG_made + forties_yd_FG_made + fifties_yd_FG_made + FG_missed << "\t\t" << extraPoints << "\t\t";
        printf("%.1f\n", points());
    }
    void profileOutput()
    {
        cout << "SCORING CATEGORY\t\tPTS PER\t\t#\t\tSCORE" << endl;
        if (forties_yd_FG_made > 0)
        {
            cout << "FG Made (40-49 yards)\t4\t\t\t" << forties_yd_FG_made << "\t";
            printf("\t%.1f\n", double(forties_yd_FG_made) * 4.0);
        }
        if (below_forty_yd_FG_made > 0)
        {
            cout << "FG Made (0-39 yards)\t3\t\t\t" << below_forty_yd_FG_made << "\t";
            printf("\t%.1f\n", double(below_forty_yd_FG_made) * 3.0);
        }
        if (FG_missed > 0)
        {
            cout << "Total FG Missed\t\t\t-1\t\t\t" << FG_missed << "\t";
            printf("\t%.1f\n", double(FG_missed) * (-1.0));
        }
        if (extraPoints > 0)
        {
            cout << "Each PAT Made\t\t\t1\t\t\t" << extraPoints << "\t";
            printf("\t%.1f\n", double(extraPoints));
        }
        if (fifties_yd_FG_made > 0)
        {
            cout << "FG Made (50-59 yards)\t5\t\t\t" << fifties_yd_FG_made << "\t";
            printf("\t%.1f\n", double(fifties_yd_FG_made) * 5.0);
        }
        cout << "TOTAL\t\t\t\t\t\t\t\t\t\t";
        printf("%.1f\n", points());
    }
    void boom()
    {
        extraPoints++;
        below_forty_yd_FG_made++;
    }
    void bust()
    {
        FG_missed++;
    }

protected:
    int extraPoints;
    int below_forty_yd_FG_made;
    int forties_yd_FG_made;
    int fifties_yd_FG_made;
    int FG_missed;
};

#endif