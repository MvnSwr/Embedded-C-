#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdio.h>
#include <chrono>
#include <thread>
#include <sstream>
#include <cstring>
#include "EmbSysLib.h"

using namespace EmbSysLib::Dev;

class Display
{
    public:

        Display(ScreenChar& sc) : sc(sc)
        {
            counter = -1;
        }

        //die Methode wird genutzt um einen Ladebalken auf dem Bildschirm anzeigen zu lassen
        void loadingbar(float time) //es wird die zu laufende Zeit in Sekunden uebergeben
        {
            row[21] = '\0';
            while (++counter < 20)
            {
                for (int i = 0; i < 5; ++i)
                {
                    char hexChar = static_cast<char>(0xda - i); //0xda fuer das Display
                    row[counter] = hexChar;
                    sc.printf(2, 0, "%s", row);
                    std::this_thread::sleep_for(std::chrono::milliseconds((int)((time / (5.0f * 20.0f)) * 1000)) ); // Sleeptimer
                }
            }
        }

    private:
        int counter;
        ScreenChar& sc;
        char row[21];

        char* convertToHex(int number)
        {
            std::stringstream stream;
            stream << std::hex << number;
            std::string result = stream.str();

            char* hexStr = new char[result.length() + 1];
            std::strcpy(hexStr, result.c_str());

            return hexStr;
        }
};

#endif // DISPLAY_H
