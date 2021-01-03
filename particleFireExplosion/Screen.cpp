#include <iostream>
#include "Screen.h"

using namespace std;

namespace helpers 
{

    Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL), m_blur_buffer(NULL)
    {

    }

    bool Screen::init()
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            cout << "ups" << endl;
            return false;
        }

        m_window = SDL_CreateWindow("Particle Fire Explosion", 
                                    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
                                    SCREEN_WIDTH, SCREEN_HEIGHT, 
                                    SDL_WINDOW_SHOWN);
        
        if (m_window == NULL)
        {
            cout << "windo is null" << endl;
            SDL_Quit();
            return false;
        }

        m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

        if (m_renderer == NULL)
        {
            cout << "error in creating m_renderer" << endl;
            SDL_DestroyRenderer(m_renderer);
            SDL_DestroyWindow(m_window);
            return false;
        }

        m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

        if (m_texture == NULL)
        {
            cout << "error in creating m_texture" << endl;
            SDL_DestroyTexture(m_texture);
            SDL_DestroyRenderer(m_renderer);
            SDL_DestroyWindow(m_window);
            return false;
        }

        m_buffer = new Uint32[SCREEN_HEIGHT * SCREEN_WIDTH];
        m_blur_buffer = new Uint32[SCREEN_HEIGHT * SCREEN_WIDTH];

        memset(m_buffer, 0XFF000000, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32));
        memset(m_blur_buffer, 0XFF000000, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32));

        return true;
    }

    void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue)
    {
        if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
            return;
            
        Uint32 color = 0;
        
        color += red;
        color <<= 8;
        color += green;
        color <<= 8;
        color += blue;
        color <<= 8;
        color += 0xFF;

        // cout << hex << color << endl;

        m_buffer[(y * SCREEN_WIDTH) + x] = color;
    }

    void Screen::boxBlur()
    {
        Uint32 *aux = m_buffer;
        // m_buffer = m_blur_buffer;
        m_blur_buffer = aux;

        for (int y = 0; y < SCREEN_HEIGHT; y++)
        {
            for (int x = 0; x < SCREEN_WIDTH; x++)
            {

                int red_total = 0;
                int green_total = 0;
                int blue_total = 0;

                for (int row = -1; row <= 1; row ++)
                {
                    int real_row = row + y;
                    for (int col = -1; col <= 1; col ++)
                    {
                        int real_col = col + x;

                        if (real_col < 0 || real_col >= SCREEN_WIDTH) continue;
                        if (real_row < 0 || real_row >= SCREEN_HEIGHT) continue;
                        
                        Uint32 color = m_blur_buffer[(SCREEN_WIDTH * real_row) + real_col];
                        // cout << hex << color << endl;

                        Uint8 red = color >> 24;
                        // cout << hex << red << endl;

                        Uint8 green = color >> 16;
                        // cout << hex << green << endl;

                        Uint8 blue = color >> 8;
                        // cout << hex << blue << endl;

                        red_total += red;
                        green_total += green;
                        blue_total += blue;

                    }
                }

                // cout << "red total: " << hex << red_total << endl;

                Uint8 final_red = red_total / 9;
                Uint8 final_green = green_total / 9;
                Uint8 final_blue = blue_total / 9;

                // cout << "final red: " << hex << final_red << endl;

                setPixel(x, y, final_red, final_green, final_blue);
            }
        }
    }

    void Screen::update()
    {
        SDL_UpdateTexture(m_texture, NULL, m_buffer, SCREEN_WIDTH * sizeof(Uint32));
        SDL_RenderClear(m_renderer);
        SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
        SDL_RenderPresent(m_renderer);
    }

    void Screen::clear()
    {
        memset(m_buffer, 0x00000000, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32));
        memset(m_blur_buffer, 0x00000000, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32));
    }

    bool Screen::proccessEvents()
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                return false;
            }
        }
        return true;
    }

    void Screen::close()
    {
        delete [] m_buffer;
        delete [] m_blur_buffer;
        SDL_DestroyTexture(m_texture);
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        cout << "success!" << endl;
        SDL_Quit();
    }

}
