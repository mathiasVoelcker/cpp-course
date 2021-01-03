#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace helpers;
using namespace entities;

int main()
{
    // const int SCREEN_WIDTH = 800;
    // const int SCREEN_HEIGHT = 600;

    Screen screen;

    if (!screen.init())
    {
        cout << "could not init SDL" << endl;
        return 1;
    }

    Swarm swarm;

    while(true)
    {      
        // 0X0000FF00  BLUE
        // 0XFF000000 RED
        // 0X00FF0000 GREEN
        screen.clear();

        // number of milisec since program started
        int elapsed = SDL_GetTicks();
        
        swarm.update(elapsed);

        double green = 1 + sin(elapsed * 0.0001);
        double red = 1 + cos(elapsed * 0.00015);
        double blue = 1 + sin(elapsed * 0.0002);

        // // int colorChanges = (SCREEN_HEIGHT * SCREEN_WIDTH) / 65025;
        // // cout << "color changes: " << colorChanges << endl;
        // // Uint8 test = 0x00;
        unsigned char finalGreen = green * 128;
        unsigned char finalRed = red * 128;
        unsigned char finalBlue = blue * 128;
        if (finalRed == 0) finalRed = 1;

        const Particle * const listParticles = swarm.getParticles();
        for (int i = 0; i < Swarm::COUNT_PARTICLES; i++)
        {
            Particle particle = listParticles[i];
            // cout << i << endl;
            int x = (particle.m_x) * (Screen::SCREEN_WIDTH / 2);
            int y = (particle.m_y - 1) * (Screen::SCREEN_WIDTH / 2) + (Screen::SCREEN_HEIGHT / 2);
            screen.setPixel(x, y, finalRed, finalGreen, finalBlue);
        }

        screen.boxBlur();

        // cout << hex << (int)finalRed << endl;
        // for (int y = 0; y < Screen::SCREEN_HEIGHT; y++)
        // {
            
        //     for (int x = 0; x < Screen::SCREEN_WIDTH; x++)
        //     {
        //         screen.setPixel(x, y, finalRed, finalGreen, finalBlue);
        //     }
        //     // if (y % 3 == 0)
        //     //     green += 0x01;
        // }

        screen.update();

        if (!screen.proccessEvents())
            break;
    }

    screen.close();

    return 0;
}