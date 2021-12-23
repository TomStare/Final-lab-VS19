

#include "Game.h"




	Game::Game() {
		Window = nullptr; game_int = nullptr; music = nullptr;
	}

	Game::~Game() {

	}

	void Game::Init() {
			Window = new RenderWindow(VideoMode(1000, 800), "Final-lab Game");
			Window->setFramerateLimit(60);
			game_int = new game_interface;
			music = new Music;
			music->openFromFile("../files/music.ogg");
			music->setLoop(true);
			music->play();
	}

	void Game::Run() {
		Window->setMouseCursorVisible(1);
		int num_balls = 0;
		num_balls = game_int->Draw_Start(Window, music);
		Window->setMouseCursorVisible(0);
		Clock clock1;
		float deltaTime = 0.0f;
		bool endGame = 0;
		vector<CircleShape> balls(num_balls);
		vector<float> spX(3);
		vector<float> spY(3);
		for (int i = 0; i < num_balls; i++)
		{
			balls[i].setRadius(5);
			balls[i].setFillColor(Color::Yellow);
			balls[i].setPosition(250 + 250 * i, 100);
			spX[i] = 300.0f + 150 * i;
			spY[i] = 300.0f + 150 * i;
		}
		spX[0] = -spX[0];
		spY[2] = -spY[2];
		spY[1] = -spY[1];
		spX[1] = -spX[1];
		RectangleShape board;
		board.setSize(Vector2f(200, 15));
		board.setPosition(400, 750);
		board.setFillColor(Color::Green);
		while (Window->isOpen() && !endGame) {
			Event event;
			while (Window->pollEvent(event)) {
				if (event.type == Event::Closed)
					Window->close();
			}
			if (Mouse::getPosition(*Window).x<800 && Mouse::getPosition(*Window).x > 0) {
				board.setPosition(Mouse::getPosition(*Window).x, 750);
			}
			else if (Mouse::getPosition(*Window).x >= 800) {
				board.setPosition(800, 750);
			}
			else {
				board.setPosition(0, 750);
			}
			for (int i = 0; i < num_balls; i++)
			{
				balls[i].move(deltaTime * spX[i], deltaTime * spY[i]);
				if (balls[i].getPosition().x >= 995)
				{
					balls[i].setPosition(995, balls[i].getPosition().y);
					spX[i] = -spX[i];
				}
				if (balls[i].getPosition().x <= 0)
				{
					balls[i].setPosition(0, balls[i].getPosition().y);
					spX[i] = -spX[i];
				}
				if (balls[i].getPosition().y <= 0)
				{
					balls[i].setPosition(balls[i].getPosition().x, 0);
					spY[i] = -spY[i];
				}
				if (balls[i].getPosition().y >= 795)
				{
					endGame = true;
					balls[i].setPosition(425 + 50 * i, 100);
				}
				if (((balls[i].getGlobalBounds().top + balls[i].getGlobalBounds().height) > board.getGlobalBounds().top)
					&& (balls[i].getGlobalBounds().left < (board.getGlobalBounds().left + board.getGlobalBounds().width))
					&& ((balls[i].getGlobalBounds().left + balls[i].getGlobalBounds().width) > board.getGlobalBounds().left)
					&& (balls[i].getGlobalBounds().top < (board.getGlobalBounds().top + board.getGlobalBounds().height)))
				{
					
					spY[i] = -spY[i];
				}
				if (((balls[i].getGlobalBounds().left + balls[i].getGlobalBounds().width) > board.getGlobalBounds().left)
					&& ((balls[i].getGlobalBounds().top + balls[i].getGlobalBounds().height) > board.getGlobalBounds().top)
					&& (balls[i].getGlobalBounds().top < (board.getGlobalBounds().top + board.getGlobalBounds().height))
					&& (balls[i].getGlobalBounds().left < board.getGlobalBounds().left + 5))
				{
					spX[i] = -spX[i];
				}
			}
			Window->clear();
			for (int i = 0; i < num_balls; i++)
			{
				Window->draw(balls[i]);
			}
			Window->draw(board);
			deltaTime = clock1.getElapsedTime().asSeconds();
			clock1.restart();
			Window->display();
		}
		Game::Run();
	}

	void Game::End() {
		if (Window != nullptr)
			delete Window;
		Window = nullptr;
		if (game_int != nullptr)
			delete game_int;
		game_int = nullptr;
		if (music != nullptr)
			delete music;
		music = nullptr;
	}



