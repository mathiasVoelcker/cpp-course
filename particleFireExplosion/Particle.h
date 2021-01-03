#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace entities
{
    class Particle
    {
        public:
            double m_x;
            double m_y;
            double x_mov;
            double y_mov;
            double m_direction;
            double m_speed;

        public:
            Particle();
            virtual ~Particle();
            void update(int interval, double gravity);
            void init();
    };

}

#endif