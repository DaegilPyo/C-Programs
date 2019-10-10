#ifndef SWARM_H_
#define SWARM_H_
#include"Particle.h"
namespace pyo{
	class Swarm
	{
	public:
		const static int NPARTICLES = 5000;
	private:
		Particle* m_pParticle;
		int lastTime;
	public:
		Swarm();
		virtual ~Swarm();

		void update(int);
		const Particle* const Getparticles() const { return m_pParticle; };
	};

}

#endif // !SWARM_H_


