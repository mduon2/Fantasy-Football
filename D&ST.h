#ifndef DST_H
#define DST_H

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

#include "FootballPlayer.h"

class DST : public FootballPlayer
{
public:
    DST()
    {
        pointsAllowed = 0;
        yardsAllowed = 0;
        interceptions = 0;
        sacks = 0;
        defensiveTouchdowns = 0;
    }
    DST(int rP)
    {
        roundPicked = rP;
        srand(time(0));
        if (roundPicked >= 1 && roundPicked <= 10)
        {
            pointsAllowed = rand() % 22 + 0;
            yardsAllowed = rand() % 351 + 50;
            interceptions = rand() % 3 + 0;
            fumbles = rand() % 3 + 0;
            sacks = rand() % 5 + 0;
            defensiveTouchdowns = round((rand() % 5 + 1) / 10.0);
        }
        else if (roundPicked >= 11 && roundPicked <= 13)
        {
            pointsAllowed = rand() % 36 + 0;
            yardsAllowed = rand() % 401 + 50;
            interceptions = rand() % 2 + 0;
            fumbles = rand() % 2 + 0;
            sacks = rand() % 4 + 0;
            defensiveTouchdowns = round((rand() % 8 + 1) / 16.0);
        }
        else
        {
            pointsAllowed = rand() % 43 + 0;
            yardsAllowed = rand() % 451 + 50;
            interceptions = round((rand() % 4 + 1) / 8.0);
            fumbles = round((rand() % 4 + 1) / 8.0);
            sacks = rand() % 3 + 0;
            defensiveTouchdowns = round((rand() % 10 + 1) / 20.0);
        }
    }
    DST(int pA, int yA, int i, int sk, int dT)
    {
        pointsAllowed = pA;
        yardsAllowed = yA;
        interceptions = i;
        sacks = sk;
        defensiveTouchdowns = dT;
    }
    void set_pointsAllowed(int pA)
    {
        pointsAllowed = pA;
    }
    void set_yardsAllowed(int yA)
    {
        yardsAllowed = yA;
        ;
    }
    void set_interceptions(int i)
    {
        interceptions = i;
    }
    void set_sacks(int s)
    {
        sacks = s;
    }
    void set_defensiveTouchdowns(int dT)
    {
        defensiveTouchdowns = dT;
    }
    int get_pointsAllowed()
    {
        return pointsAllowed;
    }
    int get_yardsAllowed()
    {
        return yardsAllowed;
    }
    int get_interceptions()
    {
        return interceptions;
    }
    int get_sacks()
    {
        return sacks;
    }
    int get_defensiveTouchdowns()
    {
        return defensiveTouchdowns;
    }
    double points()
    {
        double pA, yA;
        if (pointsAllowed == 0)
        {
            pA = 5.0;
        }
        else if (pointsAllowed >= 1 && pointsAllowed <= 6)
        {
            pA = 4.0;
        }
        else if (pointsAllowed >= 7 && pointsAllowed <= 13)
        {
            pA = 3.0;
        }
        else if (pointsAllowed >= 14 && pointsAllowed <= 17)
        {
            pA = 1.0;
        }
        else if (pointsAllowed >= 18 && pointsAllowed <= 27)
        {
            pA = 0.0;
        }
        else if (pointsAllowed >= 28 && pointsAllowed <= 34)
        {
            pA = -1.0;
        }
        else if (pointsAllowed >= 35 && pointsAllowed <= 45)
        {
            pA = -3.0;
        }
        else
        {
            pA = -5.0;
        }
        if (yardsAllowed < 100)
        {
            yA = 5.0;
        }
        else if (yardsAllowed >= 100 && yardsAllowed <= 199)
        {
            yA = 3.0;
        }
        else if (yardsAllowed >= 200 && yardsAllowed <= 299)
        {
            yA = 2.0;
        }
        else if (yardsAllowed >= 300 && yardsAllowed <= 349)
        {
            yA = 0.0;
        }
        else if (yardsAllowed >= 350 && yardsAllowed <= 399)
        {
            yA = -1.0;
        }
        else if (yardsAllowed >= 400 && yardsAllowed <= 449)
        {
            yA = -3.0;
        }
        else if (yardsAllowed >= 450 && yardsAllowed <= 499)
        {
            yA = -5.0;
        }
        else if (yardsAllowed >= 500 && yardsAllowed <= 549)
        {
            yA = -6.0;
        }
        else
        {
            yA = -7.0;
        }
        return pA + yA + double(sacks) + 2.0 * (interceptions + fumbles) + 6.0 * double(defensiveTouchdowns);
    }
    void teamOutput()
    {
        int indent = 5;
        cout << lastName << " D/ST" << endl;
        if (defensiveTouchdowns == 1)
        {
            cout << "TD";
            indent--;
        }
        else if (defensiveTouchdowns > 1)
        {
            cout << defensiveTouchdowns << " TD";
            indent -= 2;
        }
        if (interceptions == 1)
        {
            if (indent == 5)
            {
                cout << "INT";
            }
            else
            {
                cout << ", INT";
            }
            indent--;
        }
        else if (interceptions > 1)
        {
            if (indent == 5)
            {
                cout << interceptions << " INT";
            }
            else
            {
                cout << ", " << interceptions << " INT";
            }
            indent -= 2;
        }
        if (fumbles == 1)
        {
            if (indent == 5)
            {
                cout << "FUM";
            }
            else
            {
                cout << ", FUM";
            }
            indent--;
        }
        else if (fumbles > 1)
        {
            if (indent == 5)
            {
                cout << fumbles << " FUM";
            }
            else
            {
                cout << ", " << fumbles << " FUM";
            }
            indent -= 2;
        }
        if (indent == 5)
        {
            cout << pointsAllowed << " PA";
        }
        else
        {
            cout << ", " << pointsAllowed << " PA";
        }
        if ((interceptions > 0 && fumbles > 0) || (pointsAllowed < 10 && interceptions > 0) || (pointsAllowed < 10 && fumbles > 0))
        {
            indent++;
        }
        for (int i = 0; i < indent; i++)
        {
            cout << "\t";
        }
        printf("%.1f\n", points());
    }
    void gamelogOutput()
    {
        cout << pointsAllowed << "\t\t" << interceptions << "\t\t" << fumbles << "\t\t" << sacks << "\t\t" << defensiveTouchdowns << "\t\t";
        printf("%.1f\n", points());
    }
    void profileOutput()
    {
        cout << "SCORING CATEGORY\t\tPTS PER\t\t#\t\tSCORE" << endl;
        if (pointsAllowed == 0)
        {
            cout << "0 points allowed\t\t\t5\t\t\t1\t\t5.0" << endl;
        }
        else if (pointsAllowed >= 1 && pointsAllowed <= 6)
        {
            cout << "1-6 points allowed\t\t\t4\t\t\t1\t\t4.0" << endl;
        }
        else if (pointsAllowed >= 7 && pointsAllowed <= 13)
        {
            cout << "7-13 points allowed\t\t\t3\t\t\t1\t\t3.0" << endl;
        }
        else if (pointsAllowed >= 14 && pointsAllowed <= 17)
        {
            cout << "14-17 points allowed\t\t1\t\t\t1\t\t1.0" << endl;
        }
        else if (pointsAllowed >= 28 && pointsAllowed <= 34)
        {
            cout << "28-34 points allowed\t\t-1\t\t\t1\t\t-1.0" << endl;
        }
        else if (pointsAllowed >= 35 && pointsAllowed <= 45)
        {
            cout << "35-45 points allowed\t\t-3\t\t\t1\t\t-3.0" << endl;
        }
        else if (pointsAllowed > 45)
        {
            cout << "46+ points allowed\t\t\t-5\t\t\t1\t\t-5.0" << endl;
        }
        if (interceptions > 0)
        {
            cout << "Each Interception\t\t\t2\t\t\t" << interceptions << "\t";
            printf("\t%.1f\n", double(interceptions) * (2.0));
        }
        if (fumbles > 0)
        {
            cout << "Each Fumble Recovered\t\t2\t\t\t" << fumbles << "\t";
            printf("\t%.1f\n", double(fumbles) * (2.0));
        }
        if (sacks > 0)
        {
            cout << "Each Sack\t\t\t\t\t1\t\t\t" << sacks << "\t";
            printf("\t%.1f\n", double(sacks));
        }
        if (defensiveTouchdowns > 0)
        {
            cout << "Defensive TD\t\t\t\t6\t\t\t" << defensiveTouchdowns << "\t";
            printf("\t%.1f\n", double(defensiveTouchdowns) * (6.0));
        }
        if (yardsAllowed < 100)
        {
            cout << "0-99 total yards allowed\t5\t\t\t1\t\t5.0" << endl;
        }
        else if (yardsAllowed >= 100 && yardsAllowed <= 199)
        {
            cout << "100-199 total yards allowed\t3\t\t\t1\t\t3.0" << endl;
        }
        else if (yardsAllowed >= 200 && yardsAllowed <= 299)
        {
            cout << "200-299 total yards allowed\t2\t\t\t1\t\t2.0" << endl;
        }
        else if (yardsAllowed >= 350 && yardsAllowed <= 399)
        {
            cout << "350-399 total yards allowed\t5\t\t\t-1\t\t-1.0" << endl;
        }
        else if (yardsAllowed >= 400 && yardsAllowed <= 449)
        {
            cout << "400-449 total yards allowed\t-3\t\t\t1\t\t-3.0" << endl;
        }
        else if (yardsAllowed >= 450 && yardsAllowed <= 499)
        {
            cout << "450-499 total yards allowed\t-5\t\t\t1\t\t-5.0" << endl;
        }
        else if (yardsAllowed >= 500 && yardsAllowed <= 549)
        {
            cout << "500-549 total yards allowed\t-6\t\t\t1\t\t-6.0" << endl;
        }
        else if (yardsAllowed > 549)
        {
            cout << "550+ total yards allowed\t-7\t\t\t1\t\t-7.0" << endl;
        }
        cout << "TOTAL\t\t\t\t\t\t\t\t\t\t";
        if (points() == int(points()))
        {
            printf("\t%.1f\n", points());
            return;
        }
        cout << "\t" << points() << endl;
    }
    void boom()
    {
        sacks += 2;
        yardsAllowed *= 0.75;
    }
    void bust()
    {
        pointsAllowed += 7;
        yardsAllowed *= 1.25;
    }

protected:
    int pointsAllowed;
    int yardsAllowed;
    int interceptions;
    int sacks;
    int defensiveTouchdowns;
};

#endif