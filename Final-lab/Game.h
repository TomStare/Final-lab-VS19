#pragma once

#include "main.h"
#include "game_interface.h"


	class Game {
	public:
		RenderWindow* Window;
		game_interface* game_int;
		Music* music;
		Game();
		~Game();
		void Init();
		void Run();
		void End();
	};


