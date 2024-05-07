#ifndef BARGRAF_H
#define BARGRAF_H
#include <stdio.h>
#include "EmbSysLib.h"

using namespace EmbSysLib::Dev;

class Bargraf
{
    public:

        Bargraf(int val, ScreenChar& sc, int zeile, int min, int max) : val(val), sc(sc), zeile(zeile), min(min), max(max)
        {
            counter++;
            showDaBargraf();
        }

        Bargraf(int val, ScreenChar& sc) : Bargraf(val, sc, 1, 1, 100) {}
        Bargraf(int val, ScreenChar& sc, int zeile) : Bargraf(val, sc, zeile, 1, 100) {}
        Bargraf(int val, ScreenChar& sc, int min, int max) : Bargraf(val, sc, 1, min, max) {}


        void showBargraf()
        {
            int maxBars = sizeof(row) - 1; // Max - 1 fuer Terminierungsoperator
            int bars = val / 5;
            bars = bars > maxBars ? maxBars : bars; // Arraygrenzen absichern
            for (int i = 0; i < bars; ++i) {
                row[i] = char(0xd6); // |
            }
            row[bars] = '\0'; // Terminierungsoperator
            sc.printf(zeile, 0,"%s", row);
        }

        static void showDaBargraf()
        {
            printf("%d", counter);
        }

        ~Bargraf()
        {
            counter--;
        }

    private:
        int val;
        int zeile;
        int min;
        int max;
        ScreenChar &sc;
        char row[21];
        static int counter;
};

#endif BARGRAF_H
