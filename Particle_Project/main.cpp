#include<iostream>
#include<stdio.h>
#include<math.h>
#include<SDL.h>
#include<stdlib.h>
#include<time.h>
#include"Swarm.h"
#include"Particle.h"
#include"Screen.h"
using namespace std;
using namespace pyo;

int main(int argc, char* argv[])
{
	srand((unsigned int)time(NULL));

	Screen screen;


	if (screen.init() == false) {
		cout << "Error initiasing SDL." << endl;
	}
	//----------------------------------------------------------------------------------
	
	Swarm swarm;
	//----------------------------------------------------------------------------------

	while (true) {
		//Update particles
		//Draw particles
		int elapsed = SDL_GetTicks();
		
		swarm.update(elapsed);

		unsigned char green = (unsigned char)(1 + sin(elapsed*0.01))*128;
		unsigned char red = (unsigned char)(1 + sin(elapsed*0.002))*128;
		unsigned char blue = (unsigned char)(1 + sin(elapsed*0.0003))*128;
		const Particle* const pParticles = swarm.Getparticles();

		for (int i = 0; i < Swarm::NPARTICLES; i++) {
			Particle particle = pParticles[i];
			int x = (int)((particle.m_x + 1) * Screen::SCREEN_WIDTH / 2);
			int y = (int)(particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HIEGHT / 2);
			screen.setPixel(x, y, red, green, blue);
		}
		screen.boxBlur();
		//Draw the screen
		screen.update();
		//Check for messages/evenets
		if (screen.processEvents() == false) {
			break;
		}
	}
	//----------------------------------------------------------------------------------
	screen.close();

	return 0;
}