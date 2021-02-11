#include <iostream>
#include "Swarm.h"

using namespace std;

namespace entities {
    Swarm::Swarm()
    {
        m_particles = new Particle[COUNT_PARTICLES];
        lastTime = 0;
        gravity = 0.01;
    }

    void Swarm::update(int elapsed)
    {
        int interval = elapsed - lastTime;

        // cout << elapsed << endl;

        gravity += 0.01;

        for (int i = 0; i < Swarm::COUNT_PARTICLES; i++)
        {
            m_particles[i].update(interval, gravity);
        }

        lastTime = elapsed;
    }
}
