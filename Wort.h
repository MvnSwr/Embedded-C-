#ifndef WORT_H
#define WORT_H

#include "Anzeige.h"
#include <stdio.h>
#include "EmbSysLib.h"

using namespace EmbSysLib::Dev;

class Wort : public Anzeige
{
    public:

        Wort(ScreenChar& sc) : sc(sc) {}

        void show(float wert)
        {
            if (wert > 75) {
                strcpy(sol, "ganz");
            } else if (wert > 50) {
                strcpy(sol, "dreiviertel");
            } else if (wert > 25) {
                strcpy(sol, "halb");
            } else if (wert > 0) {
                strcpy(sol, "viertel");
            } else {
                strcpy(sol, "null");
            }
            sc.printf(2, 0, "%s", sol);
        }

    private:
        ScreenChar& sc;
        char sol[12];
};

#endif // WORT_H
