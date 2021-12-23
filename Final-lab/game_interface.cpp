#include "game_interface.h"
#include "Game.h"

	game_interface::game_interface()
	{
		buttons.loadFromFile("../files/buttons.png");
		
	}

	game_interface::~game_interface()
	{
	}
	int game_interface::Draw_Start(RenderWindow* Window, Music* music)
	{
		bool start_int = 1;
		int num_but = 0, num_balls = 0;
		Sprite but_start(buttons);
		Sprite but_exit(buttons);
		Sprite but_settings(buttons);
		but_start.setTextureRect(IntRect(0, 0, 207, 208));
		but_start.setPosition(398, 100);
		but_exit.setTextureRect(IntRect(0, 208, 176, 176));
		but_exit.setPosition(150, 313);
		but_settings.setTextureRect(IntRect(0, 384, 176, 176));
		but_settings.setPosition(675, 313);
		while (start_int)
		{
			Event event;
			while (Window->pollEvent(event))
			{
				if (event.type == Event::Closed)
					Window->close();
			}
			but_start.setColor(Color::White);
			but_exit.setColor(Color::White);
			but_settings.setColor(Color::White);
			if (IntRect(398, 100, 207, 208).contains(Mouse::getPosition(*Window))) { but_start.setColor(Color::Blue); }
			if (IntRect(150, 313, 176, 176).contains(Mouse::getPosition(*Window))) { but_exit.setColor(Color::Blue); }
			if (IntRect(675, 313, 176, 176).contains(Mouse::getPosition(*Window))) { but_settings.setColor(Color::Blue); }
			Window->clear();
			Window->draw(but_start);
			Window->draw(but_exit);
			Window->draw(but_settings);
			Window->display();
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (IntRect(398, 100, 207, 208).contains(Mouse::getPosition(*Window))) { start_int = 0; num_balls = game_interface::Difficulty_Selection(Window); }
				if (IntRect(150, 313, 176, 176).contains(Mouse::getPosition(*Window))) { Window->close(); }
				if (IntRect(675, 313, 176, 176).contains(Mouse::getPosition(*Window))) { game_interface::settings(music, Window); }
			}
			
		}
		return (num_balls);
	}

	int game_interface::Difficulty_Selection(RenderWindow* Window)
	{
		bool dif_sel = 1;
		int num_balls = 0;
		Sprite easy_dif(buttons);
		Sprite normal_dif(buttons);
		Sprite hard_dif(buttons);
		easy_dif.setTextureRect(IntRect(208, 0, 127, 47));
		easy_dif.setPosition(436, 328);
		normal_dif.setTextureRect(IntRect(208, 48, 127, 47));
		normal_dif.setPosition(436, 376);
		hard_dif.setTextureRect(IntRect(208, 96, 127, 47));
		hard_dif.setPosition(436, 424);
		while (dif_sel)
		{
			Event event;
			while (Window->pollEvent(event))
			{
				if (event.type == Event::Closed)
					Window->close();
			}
			easy_dif.setColor(Color::White);
			normal_dif.setColor(Color::White);
			hard_dif.setColor(Color::White);
			if (IntRect(436, 328, 127, 47).contains(Mouse::getPosition(*Window))) { easy_dif.setColor(Color::Green); }
			if (IntRect(436, 376, 127, 47).contains(Mouse::getPosition(*Window))) { normal_dif.setColor(Color::Yellow); }
			if (IntRect(436, 424, 127, 47).contains(Mouse::getPosition(*Window))) { hard_dif.setColor(Color::Red); }
			Window->clear();
			Window->draw(easy_dif);
			Window->draw(normal_dif);
			Window->draw(hard_dif);
			Window->display();
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (IntRect(436, 328, 127, 47).contains(Mouse::getPosition(*Window))) { num_balls = 1; dif_sel = 0; }
				if (IntRect(436, 376, 127, 47).contains(Mouse::getPosition(*Window))) { num_balls = 2; dif_sel = 0; }
				if (IntRect(436, 424, 127, 47).contains(Mouse::getPosition(*Window))) { num_balls = 3; dif_sel = 0; }
			}
		}
		return (num_balls);
	}

	void game_interface::settings(Music* music, RenderWindow* Window)
	{
		bool but_mus = 1, start = 1;
		Sprite but_music1(buttons);
		Sprite but_music2(buttons);
		Sprite music_icon(buttons);
		Sprite but_back(buttons);
		but_music2.setTextureRect(IntRect(0, 640, 79, 79));
		but_music2.setPosition(150, 200);
		but_music1.setTextureRect(IntRect(0, 720, 79, 79));
		but_music1.setPosition(150, 300);
		music_icon.setTextureRect(IntRect(80, 560, 112, 127));
		music_icon.setPosition(300, 200);
		but_back.setTextureRect(IntRect(176, 208, 142, 143));
		but_back.setPosition(800, 50);
		while (start) {
			Event event;
			while (Window->pollEvent(event))
			{
				if (event.type == Event::Closed)
					Window->close();
			}
			but_music1.setColor(Color::White);
			but_music2.setColor(Color::White);
			if (IntRect(150, 300, 80, 80).contains(Mouse::getPosition(*Window))) { but_music1.setColor(Color::Blue); }
			if (IntRect(150, 200, 80, 80).contains(Mouse::getPosition(*Window))) { but_music2.setColor(Color::Blue); }
			Window->clear();
			if (but_mus) {
				Window->draw(but_music1);
			}
			else {
				Window->draw(but_music2);
			}
			Window->draw(but_back);
			Window->draw(music_icon);
			Window->display();
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				if (but_mus) {
					if (IntRect(150, 300, 80, 80).contains(Mouse::getPosition(*Window))) { but_mus = 0; music->stop(); }
				}
				else {
					if (IntRect(150, 200, 80, 80).contains(Mouse::getPosition(*Window))) { but_mus = 1; music->play(); }
				}
				if (IntRect(800, 50, 142, 143).contains(Mouse::getPosition(*Window))) { game_interface::Draw_Start(Window, music); start = 0; }
			}
		}
	}

