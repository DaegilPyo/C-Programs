#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace pyo{
	struct Particle
	{
		double m_y;
		double m_x;
		double m_speed;
		double m_direction;
	public:
		Particle();
		virtual ~Particle();
		void update(int interval);
	private:
		void init();
	};
	
}




#endif // !PARTICLE_H_
