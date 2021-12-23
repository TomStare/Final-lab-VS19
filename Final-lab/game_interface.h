#pragma once

#include "main.h"



	class game_interface
	{
	public:
		Texture buttons;
		game_interface();
		~game_interface();
		int Draw_Start(RenderWindow* Window, Music* music);
		int Difficulty_Selection(RenderWindow* Window);
		void settings(Music* music, RenderWindow* Window);
	};

