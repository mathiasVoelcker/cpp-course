#ifndef SWARM_H_
#define SWARM_H_

#include "Particle.h"

namespace entities 
{
    class Swarm
    {
        public:
            const static int COUNT_PARTICLES = 8000;
        private: 
            Particle * m_particles;
            int lastTime;
            double gravity;
        
        public:
            Swarm();
            const Particle * getParticles() { return m_particles; };
            void update(int elapsed);
    };
}

#endif