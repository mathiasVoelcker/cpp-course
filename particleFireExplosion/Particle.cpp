#include "Particle.h"
#include <stdlib.h>

namespace entities
{
    Particle::Particle() : m_x(1), m_y(1) 
    {
        // m_x = ((2.0 * rand())/RAND_MAX);
        // m_y = ((2.0 * rand())/RAND_MAX);
        init();

        // x_mov = 0.001 * ((2.0 * rand() / RAND_MAX) - 1);
        // y_mov = 0.001 * ((2.0 * rand() / RAND_MAX) - 1);
    }


    Particle::~Particle()
    {
        
    }

    void Particle::init()
    {
        m_x = 1; 
        m_y = 1;
        m_direction = (2.0 * M_PI * rand()) / RAND_MAX;
        m_speed = 0.05 * (2.0 * rand() / RAND_MAX);

        m_speed *= m_speed;
    }

    void Particle::update(int interval, double gravity)
    {
        
        
        // m_direction += interval * 0.0001;

        // double gravity_direction = (M_PI * 1.5) * gravity;

        // m_direction = m_direction
        
        double xspeed = m_speed * cos(m_direction);
        double yspeed = m_speed * (sin(m_direction) + gravity);
        // yspeed += gravity;

        m_x += xspeed;
        m_y += yspeed;

        // if (m_x < 0 || m_x > 2 || m_y < 0 || m_y > 2)
        // {
        //     init();
        // }

        // m_x += xspeed * interval;
        // m_y += yspeed * interval;

        // if (m_x <= 0 || m_x >= 2)
        // {
        //     x_mov = -x_mov;
        // }

        // if (m_y <= 0 || m_y >= 2)
        // {
        //     y_mov = -y_mov;
        // }
    }
}