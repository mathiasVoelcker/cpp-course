#include <iostream>
#include "Screen.h"

using namespace std;

namespace helpers 
{

    Screen::Screen(): m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL)
    {

    }

    bool Screen::init()
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
            cout << "ups" << endl;
            return false;
        }

        m_window = SDL_CreateWindow("Butterfly", 
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

    void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha)
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
        color += alpha;

        m_buffer[(y * SCREEN_WIDTH) + x] = color;
    }

    void Screen::test()
    {
        for (int i = 0; i < SCREEN_WIDTH; i++)
        {
            m_buffer[(5 * SCREEN_WIDTH) + i] = 0xffffffff;
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
        for (int y = 0; y < SCREEN_HEIGHT; y++)
        {
            for (int x = 0; x < SCREEN_WIDTH; x++)
            {
                m_buffer[(y * SCREEN_WIDTH) + x] = 0x00000000;
            }
        }
    }

    // void Screen::clear()
    // {
    //     for (int y = 0; y < SCREEN_HEIGHT; y++)
    //     {
    //         for (int x = 0; x < SCREEN_WIDTH; x++)
    //         {
    //             Uint32 particle = m_buffer[(y * SCREEN_WIDTH) + x];
    //             Uint8 alpha = particle & 0x000000FF;
    //             if (alpha == 0) break;
    //             alpha -= 5;
                
    //             setPixel(x, y, 
    //                 (Uint8)(particle >> 24),
    //                 (Uint8)(particle >> 16),
    //                 (Uint8)(particle >> 8),
    //                 alpha);
                
    //             m_buffer[(y * SCREEN_WIDTH) + x] = (particle >> 24) + (particle >> 16) + (particle >> 8) + alpha;
    //         }
    //     }
    // }

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
        SDL_DestroyTexture(m_texture);
        SDL_DestroyRenderer(m_renderer);
        SDL_DestroyWindow(m_window);
        cout << "success!" << endl;
        SDL_Quit();
    }

}
