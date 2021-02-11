#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen.h"

#define N 50000

using namespace std;
using namespace helpers;

void regular(Screen screen)
{
    for (int i = 0; i < N; i++)
    {
            float u = i * 24.0 * M_PI / N;
            float rotation = -M_PI / 2.0;

            float m = exp(cos(u)) - (2 * cos(4 * u)) - pow((sin(u / 12.0)), 5);

            float x = cos(u) * m * 50;
            float y = sin(u) * m * 50;

            float r_x = ((x * cos(rotation)) - (y * sin(rotation)));
            float r_y = ((x * sin(rotation)) + (y * cos(rotation)));

            int red = abs(255 * cos(i * M_PI/20000.0));

            int green = (i * (255.0 / (float)N));

            int blue = abs(255 * sin(i * M_PI/20000.0));

            screen.setPixel((int)r_x + (Screen::SCREEN_WIDTH / 2), (int)r_y + (Screen::SCREEN_HEIGHT / 2), red, 0x00, blue);
    }
    screen.update();
}

void fractalZoom(Screen screen)
{

    while (true) 
    {
        for (int i = 0; i < N; i++)
        {
            float u = i * 24.0 * M_PI / N;
            float z_rotation = -M_PI / 2.0; 
            float m = exp(cos(u)) - (2 * cos(4 * u)) - pow((sin(u / 12.0)), 5);

            float x = cos(u) * m * 50;
            float y = sin(u) * m * 50;
            float z = 1;

            float x_after_rot_z = (x * cos(z_rotation)) - (y * sin(z_rotation));
            float y_after_rot_z = (x * sin(z_rotation)) + (y * cos(z_rotation));

            x = x_after_rot_z;
            y = y_after_rot_z;
            z = pow(z, 2) + 400;

            float angle = atan(y / (400 - z));
            y = y + (tan(angle) * z);

            angle = atan(x / (400 - z));
            x = x + (tan(angle) * z);

            int red = abs(255 * cos(i * M_PI/20000.0));

            int green = (i * (255.0 / (float)N));

            int blue = abs(255 * sin(i * M_PI/20000.0));

            screen.setPixel((int)x + (Screen::SCREEN_WIDTH / 2), (int)y + (Screen::SCREEN_HEIGHT / 2), red, 0x00, blue);
        }
        screen.update();
        screen.clear();
        if (!screen.proccessEvents())
            break;
    }
}

void shifted(Screen screen, float rotation, int x_origin, int y_origin)
{
    for (int i = 0; i < N; i++)
    {
            float u = i * 24.0 * M_PI / N;
            float z_rotation = -M_PI / 2.0; 

            float m = exp(cos(u)) - (2 * cos(4 * u)) - pow((sin(u / 12.0)), 5);

            float x = cos(u) * m * 50;
            float y = sin(u) * m * 50;
            float z = 1;

            //rotation in Z
            float x_after_rot_z = (x * cos(z_rotation)) - (y * sin(z_rotation));
            float y_after_rot_z = (x * sin(z_rotation)) + (y * cos(z_rotation));
            

            //rotation in Y
            float y_rotation;
            if (y > 0) 
            {
                // cout << "y rotation: " << y_rotation << endl;
                y_rotation = -rotation + (M_PI/6);
            }
            else {
                 y_rotation = rotation + (M_PI/6);
            }

            float x_after_rot_y = (x_after_rot_z * cos(y_rotation)) + (z * sin(y_rotation));
            float z_after_rot_y = (x_after_rot_z * -sin(y_rotation)) + (z * cos(y_rotation));

            float y_after_rot_x = (y_after_rot_z * cos(M_PI / 6)) + (z_after_rot_y * sin(M_PI / 6));
            float z_after_rot_x = (y_after_rot_z * -sin(M_PI / 6)) + (z_after_rot_y * sin(M_PI / 6));

            x = x_after_rot_y;
            y = y_after_rot_x;
            z = z_after_rot_x;

            // z = pow(z, 2) + 0.5;


            float angle = atan(y / (400 - z));
            y = y + (tan(angle) * z);

            angle = atan(x / (400 - z));
            x = x + (tan(angle) * z);

            x += x_origin;
            y += y_origin;

            int red = abs(255 * cos(i * M_PI/20000.0));

            int green = (i * (255.0 / (float)N));

            int blue = abs(255 * sin(i * M_PI/20000.0));

            screen.setPixel((int)x + (Screen::SCREEN_WIDTH / 2), (int)y + (Screen::SCREEN_HEIGHT / 2), red, 0x00, blue);
    }
    screen.update();
}

void dancing(Screen screen)
{
    float y_rotation = 0;
    float z_rotation = 0;
    float rot_speed = M_PI / 21;
    float mov_speed = M_PI / 64;
    int x, y;
    // x = 50;
    // y = 0;
    while(true)
    {
        if (abs(y_rotation - M_PI/3) < 0.00001 || abs(y_rotation + M_PI/3) < 0.00001)
        {
            rot_speed = -rot_speed;
        }
        y_rotation += rot_speed;
        z_rotation += mov_speed;
        float rnd = rand() / (float)RAND_MAX;
        rnd = (rnd / 5) + 0.9; //number range from 0.9 to 1.1
        mov_speed *= rnd;
        if (mov_speed < 0.8 * (M_PI / 64)) mov_speed = 0.8 * (M_PI / 64);
        else if (mov_speed > 1.2 * (M_PI / 64)) mov_speed = 1.2 * (M_PI / 64);

        x = 100 * cos(z_rotation);
        y = 100 * sin(z_rotation);

        shifted(screen, y_rotation, x, y);
        screen.clear();
        if (!screen.proccessEvents())
            break;
    }
}

int main() 
{
    Screen screen;

    if (!screen.init())
    {
        cout << "could not init SDL" << endl;
        return 1;
    }

    // regular(screen);
    // shifted(screen, -M_PI / 3.0);
    dancing(screen);
    // fractalZoom(screen);
    // screen.test();
    screen.proccessEvents();
    // if (!screen.proccessEvents())
    //     break;

    SDL_Event event;

    bool quit = false;

    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
        }
    }

    screen.close();

    return 0;
}