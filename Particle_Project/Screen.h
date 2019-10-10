#ifndef SCREEN_H
#define SCREEN_H
#include<SDL.h>
#include<iostream>
namespace pyo
{
	class Screen
	{
	public:
		const static int SCREEN_WIDTH = 800;
		const static int SCREEN_HIEGHT = 600;
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_texture;
		Uint32* m_buffer1;
		Uint32* m_buffer2;
	public:
		Screen();
		bool init();
		bool processEvents();
		void close();
		void update();
		//void clear();
		void boxBlur();
		void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	};
}
#endif // !SCREEN_H
